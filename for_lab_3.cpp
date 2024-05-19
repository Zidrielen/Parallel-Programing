#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <vector>

typedef long long int llint;
using namespace std;
using namespace chrono;
using namespace filesystem;

const string MATRIX_1 = "..\\matrix\\matrix_1\\";
const string MATRIX_2 = "..\\matrix\\matrix_2\\";


/*----Отсчёт времени в миллисекундах----*/
size_t comp_time(const system_clock::time_point& start)
{
	system_clock::time_point finish = system_clock::now();
	return duration_cast<microseconds>(finish - start).count();
}


/*----Умножение матриц без распараллеливания----*/
size_t multiplication_lab_1(llint* n, llint* m, llint* res, int size)
{
    int i, j, k;
    system_clock::time_point start = system_clock::now();
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            for(k = 0; k < size; k++)
                res[i*size+j] += n[i*size+k] * m[k*size+j];
    return comp_time(start);
}


/*----Получение имён файлов с матрицами----*/
vector<string> get_name_matrix(const string& path)
{
    vector<string> files;
    for(auto const& file: directory_iterator(path))
    {
        string path_str = file.path().string();
        string name = path_str.substr(path_str.rfind("\\") + 1);
        files.push_back(name);
    }
    return files;
}


/*----Получение размеров матриц----*/
int get_size_matrix(const string& path)
{
    return stoi(path.substr(0, path.rfind("_")));
}


/*----Запись результата умножения матриц----*/
void write_matrix(const string& filename, llint* res, int size)
{
    string file = "..\\matrix\\results\\" + filename;
    FILE* fout = fopen(file.c_str(), "w");
    if(!fout) {perror(NULL); exit(-1); }
    int count = size * size;
    for(int i = 1; i <= count; i++)
    {
        fprintf_s(fout, "%lld", res[i-1]);
        if(i % size == 0) fprintf_s(fout, "\n");
        else fprintf_s(fout, " ");
    }
    fclose(fout);
}


/*----Чтение файла с матрицей----*/
void read_matrix(const string& path_file, llint* mat)
{
    FILE* fin = fopen(path_file.c_str(), "r");
    if(!fin) {perror(NULL); exit(-1); }
    for(int j = 0; !feof(fin); j++)
        fscanf_s(fin, "%lld ", &mat[j]);
    fclose(fin);
}


int main()
{
    vector<string> name_matrix;
    name_matrix = get_name_matrix(MATRIX_1);

    int cur_size = 0, count = 0;
    llint *n = nullptr, *m = nullptr, *res = nullptr;
    size_t time = 0;

    FILE* fout = fopen("..\\stats\\Lab_3\\stats.csv", "w");
    if(!fout) {perror(NULL); exit(-1); }

    for(int i = 0; i < name_matrix.size(); i++)
    {
        int size = get_size_matrix(name_matrix[i]);
        if(cur_size != size)
        {
            count = size * size;
            if(cur_size) delete [] m, n, res;
            m = new llint[count]();
            n = new llint[count]();
            res = new llint[count]();
            cur_size = size;
        }
        else fill(res, res + count, 0);

        read_matrix(MATRIX_1 + name_matrix[i], n);
        read_matrix(MATRIX_2 + name_matrix[i], m);

        time = multiplication_lab_1(n, m, res, size);
        fprintf_s(fout, "%s\t%zu\n", name_matrix[i].c_str(), time);
        write_matrix(name_matrix[i], res, size);
    }

    fclose(fout);
    delete [] m, n, res;
}