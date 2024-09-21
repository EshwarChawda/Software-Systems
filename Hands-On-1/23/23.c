/*
============================================================================
Name : 23.c
Author : Eshwar Chawda
Description :  Write a program to create a Zombie state of the running program.
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
    int abc=-1;
    if(pid<0){
        printf("forkfailed\n");
        exit(1);
    }
    if(pid==0){
        printf("In child\n");
        exit(0);
    }else{
        sleep(10);
        printf("In parent\n");
    }
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/23$ gcc 23.c -o 23
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/23$ ./23
In child
In parent

*/
