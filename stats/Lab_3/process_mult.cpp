#include <stdio.h>

#include <algorithm>
#include <ctime>

typedef unsigned int usint;

using namespace std;

const int COUNT = 100;
const int MAX_VALUE = 1000 + 1;


/*----Умножение матриц без распараллеливания----*/
usint multiplication_lab_1(usint* n, usint* m, usint* res, usint size)
{
    int i, j, k;
    usint start = clock();
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            for(k = 0; k < size; k++)
                res[i*size+j] += n[i*size+k] * m[k*size+j];
    return clock() - start;
}


int main()
{
    srand((unsigned)time(NULL));
    usint time = 0, count_elem = 0;
    usint *n = nullptr, *m = nullptr, *res = nullptr;

    FILE* fout = fopen("stats.csv", "w");
    if(!fout) {perror(NULL); exit(-1); }

    for(int i = 50; i <= 500; i += 50)
    {
        count_elem = i * i;
        n = new usint[count_elem];
        m = new usint[count_elem];
        res = new usint[count_elem];
        for(int j = 0; j < COUNT; j++)
        {
            for(int k = 0; k < count_elem; k++)
            {
                n[k] = rand() % MAX_VALUE;
                m[k] = rand() % MAX_VALUE;
            }
            time = multiplication_lab_1(n, m, res, i);
            fprintf(fout, "%d_%d\t%u\n", i, j, time);
        }
        delete [] m, n, res;
    }

    fclose(fout);
}