//
// Created by ahmed-essam100 on 03/11/18.
//

#include "Matrix_init.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int **mat_A,**mat_B,**mat_C1,**mat_C2;
int row1,col1,row2,col2;
int rows_done=0,elements_done=0,task1=0;


void Matrix_init()
{
    FILE *f;
    //Reading The Input File
    f = fopen("Matrix.txt","r");
    //Scanning rows and columns of Matrix1
    fscanf(f,"%d",&row1);
    fscanf(f,"%d",&col1);
    mat_A = (int**)malloc(row1* sizeof(int*));
    for (int i = 0; i < row1; ++i) {
        mat_A[i] = (int*)malloc(col1* sizeof(int));
    }
    int i,j;
    //Scanning Matrix1
    for(i=0;i<row1;i++)
        for (j=0; j < col1; j++)
        {
            fscanf(f,"%d",&mat_A[i][j]);
        }
    //Scanning rows and columns of Matrix2
    fscanf(f,"%d",&row2);
    fscanf(f,"%d",&col2);
    mat_B = (int**)malloc(row2* sizeof(int*));
    for (int i = 0; i < row2; ++i) {
        mat_B[i] = (int*)malloc(col2* sizeof(int));
    }
    //Scanning Matrix2
    for(i=0;i<row2;i++)
        for (j=0; j < col2; j++)
        {
            fscanf(f,"%d",&mat_B[i][j]);
        }
    mat_C1 = (int**)malloc(row1* sizeof(int*));
    for (int i = 0; i < row1; ++i) {
        mat_C1[i] = (int*)malloc(col2* sizeof(int));
    }
    mat_C2 = (int**)malloc(row1* sizeof(int*));
    for (int i = 0; i < row1; ++i) {
        mat_C2[i] = (int*)malloc(col2* sizeof(int));
    }
    fclose(f);
}

void *Multiply_row(void* thread_id)
{
    int task = rows_done++,i,j,k;
    for(i=task;i<(task+1);i++)
        for(j=0;j<col2;j++) {
            for (k = 0; k < row2; k++) {
                mat_C1[i][j] += mat_A[i][k] * mat_B[k][j];
            }
        }
}

void *Multiply_element(void* thread_id)
{
    int i,j,k;
    if(elements_done==col2)
    {
        task1+=1;
        elements_done=0;
    }
    for(i=task1;i<(task1+1);i++)
        for(j=elements_done;j<(elements_done+1);j++)
            for(k=0;k<row2;k++) {
                mat_C2[i][j] += mat_A[i][k] * mat_B[k][j];
            }
    elements_done++;

}

void *get_call_back(int variation)
{
    if(variation==By_Row)
    {
        return Multiply_row;
    }
    else if(variation==By_Element)
    {
        return Multiply_element;
    }
}
