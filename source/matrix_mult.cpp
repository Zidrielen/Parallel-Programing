#include "matrix_mult.hpp"


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


/*----Умножение матриц с использованием OpenMP----*/
size_t multiplication_lab_2(llint* n, llint* m, llint* res, int size)
{
    int i, j, k;
    system_clock::time_point start = system_clock::now();
#pragma omp parallel for private(j, k)
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            for(k = 0; k < size; k++)
                res[i*size+j] += n[i*size+k] * m[k*size+j];
    return comp_time(start);
}