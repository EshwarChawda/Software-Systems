/*
============================================================================
Name : 24.c
Author : Eshwar Chawda
Description : Write a program to create an orphan process.
Date: 27th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){
    pid_t pid;
    pid=fork();
    int abc;
    if(pid<0){
        printf("forkfailed\n");
        exit(1);
    }
    if(pid==0){
        sleep(10);
        printf("In child\n");
    }else{
        abc=getpid();
        printf("In parent %d\n", abc);
        exit(0);
    }
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/24$ gcc 24.c -o 24
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/24$ ./24
In parent 21578
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/24$ In child

*/
