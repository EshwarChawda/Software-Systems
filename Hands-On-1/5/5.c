/*
============================================================================
Name : 5.c
Author : Eshwar Chawda
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 24th August, 2024.
============================================================================
*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
extern int errno;
int main(){
    int fd1=open("file_5.txt",O_RDONLY|O_CREAT);
    int fd2=open("file_5.txt",O_RDONLY|O_CREAT);
    int fd3=open("file_5.txt",O_RDONLY|O_CREAT);
    int fd4=open("file_5.txt",O_RDONLY|O_CREAT);
    int fd5=open("file_5.txt",O_RDONLY|O_CREAT);


    printf("fd =  %d\n",fd1);
    printf("fd =  %d\n",fd2);
    printf("fd =  %d\n",fd3);
    printf("fd =  %d\n",fd4);
    printf("fd =  %d\n",fd5);


    if(fd1==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd2==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd3==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd4==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd5==-1){
        printf("error number %d\n",errno);
        perror("program");
    }

    
    //infinte loop
    while(1){

    }
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/5$ ./5 &
[1] 9367
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/5$ fd =  3
fd =  4
fd =  5
fd =  6
fd =  7
^C
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/5$ cd /proc/9367/fd
eshwar@eshwar-Lenovo-V14-IIL:/proc/9367/fd$ ls
0  1  2  3  4  5  6  7

*/
