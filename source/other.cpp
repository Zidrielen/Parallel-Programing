#include "other.hpp"

/*----Отсчёт времени в миллисекундах----*/
size_t comp_time(const system_clock::time_point& start)
{
	system_clock::time_point finish = system_clock::now();
	return duration_cast<microseconds>(finish - start).count();
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
