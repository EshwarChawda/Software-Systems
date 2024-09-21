/*
============================================================================
Name : 7.c
Author : Eshwar Chawda
Description : Write a simple program to print the created thread ids.
Date: 14th Sep, 2024.
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread :%lu\n", pthread_self());
}

void main()
{
    pthread_t threadID1, threadID2, threadID3;
    int pstatus;
    pstatus = pthread_create(&threadID1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/7$ gcc 7.c -o 7
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/7$ ./7
Printing from thread :124803331655360
Printing from thread :124803321169600
Printing from thread :124803342141120
============================================================================
*/
