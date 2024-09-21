/*
============================================================================
Name : 4.c
Author : Eshwar Chawda
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.   
Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// using time stamp counter
unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc": "=A"(dst));
    return dst;
}

void main()
{
    long long int start, end;

    start = rdtsc();
    int iter = 1;
    while (iter <= 100)
    {
        getppid();
        iter += 1;
    }

    end = rdtsc();

    printf("time required : %llu\n", end - start);
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/4$ gcc 4.c -o 4
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/4$ ./4
time required : 24128
============================================================================
*/
