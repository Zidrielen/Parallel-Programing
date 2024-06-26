#include <stdio.h>
#include <stdlib.h>

#include <ctime>

typedef unsigned int usint;

using namespace std;

const usint COUNT = 100;
const usint MAX_VALUE = 1000 + 1;


/*----Умножение матриц без распараллеливания----*/
usint multiplication_lab_1(usint* n, usint* m, usint* res, usint size)
{
    usint i, j, k;
    usint start = clock();
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            for(k = 0; k < size; k++)
                res[i*size+j] += n[i*size+k] * m[k*size+j];
    return 1000 * (clock() - start) / CLOCKS_PER_SEC;
}


int main()
{
    srand((unsigned)time(NULL));
    usint time = 0, count_elem = 0;
    usint* n = NULL;
    usint* m = NULL;
    usint* res = NULL;

    FILE* fout = fopen("stats.csv", "w");
    if(!fout) {perror(NULL); exit(-1); }

    for(usint i = 50; i <= 500; i += 50)
    {
        count_elem = i * i;
        n = new usint[count_elem];
        m = new usint[count_elem];
        res = new usint[count_elem];
        for(int j = 0; j < COUNT; j++)
        {
            for(usint k = 0; k < count_elem; k++)
            {
                n[k] = rand() % MAX_VALUE;
                m[k] = rand() % MAX_VALUE;
            }
            time = multiplication_lab_1(n, m, res, i);
            fprintf(fout, "%d_%d\t%u\n", i, j, time);
        }
        delete [] n;
        delete [] m;
        delete [] res;
    }

    fclose(fout);
}