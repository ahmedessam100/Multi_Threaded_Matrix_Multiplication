//
// Created by ahmed-essam100 on 03/11/18.
//
#include "Threads.h"
#include <pthread.h>
#include "Matrix_init.h"

/*Creating Threads*/
void Create_Threads(int Threads_number,int variation)
{
    /*Initializing Counter*/
    int i;
    /*Initializing array of threads with size passed*/
    pthread_t threads[Threads_number];
    for(i=0;i<Threads_number;i++)
    {
        /*Creating Threads Based on the function and the variation of calculation*/
        pthread_create(&threads[i], NULL, get_call_back(variation), NULL);
    }
    for(i=0;i<Threads_number;i++)
    {
        /*Joining Threads*/
        pthread_join(threads[i], NULL);
    }
}

/*Exiting The Thread*/
void Exit_Threads()
{
    pthread_exit(NULL);
}
