/*
============================================================================
Name : 12.c
Author : Eshwar Chawda
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 25th August, 2024.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    FILE *file = fopen("file_12.txt", "r");
    int fd = fileno(file);
    int mode = fcntl(fd, F_GETFL);
    printf("mode of file descriptor is: %d\n",mode);
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/12$ gcc 12.c -o 12
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/12$ ./12
mode of file descriptor is: 32768
*/
