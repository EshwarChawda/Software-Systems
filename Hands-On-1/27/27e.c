/*
============================================================================
Name : 27.c
Author : Eshwar Chawda
Description : Write a program to execute ls -Rl by the following system calls.
e. execvp
Date: 27th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
    // it will use environment variable PATH to run executable PATH .
    // it does not required entire file path as we did in execl().
    char *path = "ls";
    char *argv[] = {path, "-Rl", NULL};
    execvp(path, argv);
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ gcc 27e.c -o 27e
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ ./27e
.:
total 100
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:20 27a
-rw-rw-r-- 1 eshwar eshwar   893 Aug 30 20:21 27a.c
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:22 27b
-rw-rw-r-- 1 eshwar eshwar  1076 Aug 30 20:22 27b.c
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:28 27c
-rw-rw-r-- 1 eshwar eshwar   725 Aug 30 20:31 27c.c
-rwxrwxr-x 1 eshwar eshwar 16000 Aug 30 20:25 27d
-rw-rw-r-- 1 eshwar eshwar  1067 Aug 30 20:26 27d.c
-rwxrwxr-x 1 eshwar eshwar 16000 Aug 30 20:31 27e
-rw-rw-r-- 1 eshwar eshwar   601 Aug 30 20:17 27e.c
-rw-rw-r-- 1 eshwar eshwar     0 Aug 30 20:28 file_27c.txt

*/
