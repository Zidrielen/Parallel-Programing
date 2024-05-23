#include <stdio.h>

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <vector>

typedef unsigned int usint;

using namespace std;
using namespace chrono;
using namespace filesystem;

const string MATRIX_1 = "matrix_1\\";
const string MATRIX_2 = "matrix_2\\";


/*----Отсчёт времени в миллисекундах----*/
usint comp_time(const system_clock::time_point& start)
{
	system_clock::time_point finish = system_clock::now();
	return (usint)duration_cast<microseconds>(finish - start).count();
}


/*----Умножение матриц без распараллеливания----*/
usint multiplication_lab_1(usint* n, usint* m, usint* res, usint size)
{
    int i, j, k;
    system_clock::time_point start = system_clock::now();
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            for(k = 0; k < size; k++)
                res[i*size+j] += n[i*size+k] * m[k*size+j];
    return comp_time(start);
}


/*----Получение размеров матриц----*/
usint get_size_matrix(const string& path)
{
    return stoi(path.substr(0, path.rfind("_")));
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


/*----Чтение файла с матрицей----*/
void read_matrix(const string& path_file, usint* mat, usint count)
{
    FILE* fin = fopen(path_file.c_str(), "r");
    if(!fin) {perror(NULL); exit(-1); }
    fread(mat, sizeof(usint), count, fin);
    fclose(fin);
}


int main()
{
    vector<string> name_matrix = get_name_matrix(MATRIX_1);

    usint cur_size = 0, count = 0, time = 0;
    usint *n = nullptr, *m = nullptr, *res = nullptr;

    FILE* fout = fopen("stats.csv", "w");
    if(!fout) {perror(NULL); exit(-1); }

    for(int i = 0; i < name_matrix.size(); i++)
    {
        usint size = get_size_matrix(name_matrix[i]);
        if(cur_size != size)
        {
            count = size * size;
            if(cur_size) delete [] m, n, res;
            m = new usint[count]();
            n = new usint[count]();
            res = new usint[count]();
            cur_size = size;
        }
        else fill(res, res + count, 0);

        read_matrix(MATRIX_1 + name_matrix[i], n, count);
        read_matrix(MATRIX_2 + name_matrix[i], m, count);

        time = multiplication_lab_1(n, m, res, size);
        fprintf_s(fout, "%s\t%u\n", name_matrix[i].c_str(), time);
    }

    fclose(fout);
    delete [] m, n, res;
}