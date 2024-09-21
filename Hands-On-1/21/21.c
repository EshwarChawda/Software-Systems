/*
============================================================================
Name : 21.c
Author : Eshwar Chawda
Description : Write a program, call fork and print the parent and child process id.
Date: 26th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    pid_t parent= getppid();
    pid_t process= getpid();
    pid_t pid=fork();
    printf("child process: %d\n",process);
    printf("parent process: %d\n",parent);
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/21$ gcc 21.c -o 21
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/21$ ./21
child process: 20482
parent process: 6498

*/
