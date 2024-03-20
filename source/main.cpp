#include "matrix_mult.hpp"
#include "other.hpp"


const string MATRIX_1 = "..\\matrix\\matrix_1\\";
const string MATRIX_2 = "..\\matrix\\matrix_2\\";


int main()
{
    vector<string> name_matrix;

    /*----Получение имён файлов----*/
    name_matrix = get_name_matrix(MATRIX_1);

    int cur_size = 0, count = 0;
    llint *n, *m, *res;

    /*----Создание файла для сохранения статистики----*/
    FILE* fout = fopen("..\\stats\\Lab_1\\stats.csv", "w");
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

        size_t time = multiplication_lab_1(n, m, res, size);

        write_matrix(name_matrix[i], res, size);
        fprintf_s(fout, "%s\t%zu\n", name_matrix[i].c_str(), time);
        printf_s("%s - success\n", name_matrix[i].c_str());
    }

    fclose(fout);
    delete [] m, n, res;
}