#include "matrix_mult.hpp"
#include "other.hpp"


const string MATRIX_1 = "..\\matrix\\matrix_1\\";
const string MATRIX_2 = "..\\matrix\\matrix_2\\";
const int THREADS = 2;


int main()
{
    vector<string> name_matrix;
    name_matrix = get_name_matrix(MATRIX_1);

    int cur_size = 0, count = 0;
    int *n = nullptr, *m = nullptr, *res = nullptr;
    int time = 0;

    FILE* fout = fopen("..\\stats\\Lab_3\\stats.csv", "w");
    if(!fout) {perror(NULL); exit(-1); }

    for(int i = 0; i < name_matrix.size(); i++)
    {
        int size = get_size_matrix(name_matrix[i]);
        if(cur_size != size)
        {
            count = size * size;
            if(cur_size) delete [] m, n, res;
            m = new int[count]();
            n = new int[count]();
            res = new int[count]();
            cur_size = size;
        }
        else fill(res, res + count, 0);

        read_matrix(MATRIX_1 + name_matrix[i], n);
        read_matrix(MATRIX_2 + name_matrix[i], m);

        time = multiplication_lab_1(n, m, res, size);
        fprintf_s(fout, "%s\t%d\n", name_matrix[i].c_str(), time);
        write_matrix(name_matrix[i], res, size);
    }

    fclose(fout);
    delete [] m, n, res;
}