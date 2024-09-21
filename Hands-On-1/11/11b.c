/*
============================================================================
Name : 11b.c
Author : Eshwar Chawda
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
b. use dup2
Date: 25th August, 2024.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
    int file_desc = open("test.txt",O_WRONLY | O_APPEND);
    dup2(file_desc, 1) ; 
    printf("I will be printed in the file test.txt\n");
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/11$ gcc 11b.c -o 11b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/11$ ./11b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/11$ cat test.txt
This is test file.
I will be printed in the file test.txt

*/
