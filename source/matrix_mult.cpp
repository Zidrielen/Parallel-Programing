#include "matrix_mult.hpp"


/*----Умножение матриц без распараллеливания----*/
int multiplication_lab_1(int* n, int* m, int* res, int size)
{
    int i, j, k;
    system_clock::time_point start = system_clock::now();
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            for(k = 0; k < size; k++)
                res[i*size+j] += n[i*size+k] * m[k*size+j];
    return comp_time(start);
}