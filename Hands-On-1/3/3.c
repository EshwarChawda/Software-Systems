/*
============================================================================
Name : 3.c
Author : Eshwar Chawda
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 24th August, 2024.
============================================================================
*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
extern int errno;
int main(){
    int fd=open("file_3.txt",O_RDONLY|O_CREAT);
    printf("fd =  %d\n",fd);
    if(fd==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/3$ gcc 3.c -o 3
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/3$ ./3
fd =  3

*/
