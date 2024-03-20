#include "matrix_mult.hpp"


/*----Умножение матриц без распараллеливания----*/
size_t multiplication_lab_1(llint* n, llint* m, llint* res, int size)
{
    int index = 0, tmp_size = size;
    int matrix_position = 0;
    system_clock::time_point start = system_clock::now();
    while(tmp_size--)
    {
        for(int j = 0; j < size; j++)
        {
            int pos = j;
            for(int i = matrix_position; i < size + matrix_position; i++)
            {
                res[index] += n[i] * m[pos];
                pos += size;
            }
            index++;
        }
        matrix_position += size;
    }
    return comp_time(start);
}
