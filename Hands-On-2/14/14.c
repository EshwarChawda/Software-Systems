/*
============================================================================
Name : 14.c
Author : Eshwar Chawda
Description :  Write a simple program to create a pipe, write to the pipe, read from pipe and display on
    the monitor.
Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int pipefd[2]; // pipefd[0] for reading end   and pipefd[1] is writing end
    char *buff;
    char buf[10];

    // creating pipe
    if (pipe(pipefd) == -1)
    {
        printf("pipe error");
        exit(1);
    }
    printf("enter string of size 10 character\n");
    scanf("%s", buf);
    // writing in pipe and store in kernal
    write(pipefd[1], buf, 10);
    write(pipefd[1], "\n", 1);
    //closing pipes reading end
    close(pipefd[1]);

    // reading from pipe & display in monitor using STDOUT.
    printf("Display on Monitor\n");
    while (read(pipefd[0], &buff, 1))
    {
        write(1, &buff, 1);
    }
    return 0;
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/14$ gcc 14.c -o 14
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/14$ ./14
enter string of size 10 character
abcdefghij
Display on Monitor
abcdefghij
============================================================================
*/
