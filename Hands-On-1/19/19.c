/*
============================================================================
Name : 19.c
Author : Eshwar chawda
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 26th August, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

static __inline__ unsigned long long rdtsc(void) {
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    
    // Read TSC before getpid()
    start = rdtsc();
    
    // Call getpid()
    pid_t pid = getpid();
    
    // Read TSC after getpid()
    end = rdtsc();
    
    // Calculate the difference in CPU cycles
    printf("PID: %d\n", pid);
    printf("Time taken by getpid() in CPU cycles: %llu\n", end - start);
    
    return 0;
}
/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/19$ gcc 19.c -o 19
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/19$ ./19
PID: 22711
Time taken by getpid() in CPU cycles: 3379

*/
