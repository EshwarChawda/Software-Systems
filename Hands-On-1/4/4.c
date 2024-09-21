/*
============================================================================
Name : 4.c
Author : Eshwar Chawda
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 24th August, 2024.
============================================================================
*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
extern int errno;
int main(){
    int fd=open("file_4.txt",O_EXCL|O_RDWR);
    printf("fd =  %d\n",fd);
    if(fd==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/4$ gcc 4.c -o 4
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/4$ ./4
fd =  3
*/
