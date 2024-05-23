#include <stdio.h>

#include <string>

extern "C"
{
    #include <time.h>
}

typedef unsigned int usint;

const char* MATRIX_1 = "matrix_1\\";
const char* MATRIX_2 = "matrix_2\\";

const int COUNT = 100;
const int MAX_VALUE = 1000 + 1;


void create_mat(int size, usint* mat, const char* path)
{
    std::string path_file = path + std::to_string(size) + "_";
    int count_elem = size * size;
    for(int i = 0; i < COUNT; i++)
    {
        for(int j = 0; j < count_elem; j++)
            mat[j] = rand() % MAX_VALUE;
        FILE* fout = fopen((path_file + std::to_string(i)).c_str(), "w");
        if(!fout) {perror(NULL); exit(-1); }
        fwrite(mat, sizeof(usint), count_elem, fout);
        fclose(fout);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    for(int i = 50; i <= 500; i += 50)
    {
        usint* mat = new usint[i * i];
        create_mat(i, mat, MATRIX_1);
        create_mat(i, mat, MATRIX_2);
        delete [] mat;
    }

    return 0;
}