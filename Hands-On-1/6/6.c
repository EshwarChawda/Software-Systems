/*
============================================================================
Name : 6.c
Author : Eshwar chawda
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 24th August, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main() {
    char buffer[1024];

    size_t bytesRead;
    while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 1) {
        
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;

}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/6$ gcc 6.c -o 6
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/6$ ./6
hello
hello
hii
hii

*/
