/*
============================================================================
Name : 22.c
Author : Eshwar Chawda
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 14th Sep, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
int f;
char *s ="./22-fifo";
mkfifo("22-fifo",0744);
f = open("22-fifo", O_CREAT | O_WRONLY);

if (f == -1)
{
perror("Error while opening FIFO file!");
_exit(0);
}
char *st;
long int size=100;
printf("enter message\n");
int l=getline(&st,&size,stdin);
write(f, st, l);
close(f);
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/22$ cc 22b.c -o 22b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/22$ ./22b
enter message
hello

============================================================================
*/
