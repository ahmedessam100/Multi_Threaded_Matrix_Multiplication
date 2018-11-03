#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include "Matrix_init.h"
#include "Threads.h"

extern int row1,col1,row2,col2;
extern int **mat_A,**mat_B,**mat_C1,**mat_C2;

int main() {
    /*Matrices Initialization*/
    Matrix_init();
    /*Initializing Counters*/
    int i,j;
    /*Creating Threads*/
    /*First Mode Computation by row*/
    int threads_numb = row1;
    /*Creating Threads Based On the Variation of Calculation*/
    Create_Threads(threads_numb, By_Row);
    /*Opening File For the output*/
    FILE *out;
    out = fopen("Output.txt","w");
    for(i=0;i<row1;i++) {
        for (j = 0; j < col2; j++) {
            fprintf(out, "%d ", mat_C1[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "END1\t");
    /*Creating Threads*/
    /*Second Mode Computation by Element*/
    int threads_numb1 = row1*col2;
    /*Creating Threads Based On the Variation of Calculation*/
    Create_Threads(threads_numb1,By_Element);
    fprintf(out, "\n");
    for(i=0;i<row1;i++) {
        for (j = 0; j < col2; j++) {
            fprintf(out, "%d ", mat_C2[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "END2\t");
    fclose(out);
    return 0;
}

