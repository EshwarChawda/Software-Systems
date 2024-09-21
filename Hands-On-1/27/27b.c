/*
============================================================================
Name : 27.c
Author : Eshwar Chawda
Description : Write a program to execute ls -Rl by the following system calls.
b. execlp
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
    execlp(path, path, "-Rl", NULL);
    return 0;
}
/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ gcc 27b.c -o 27b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ ./27b
.:
total 52
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:20 27a
-rw-rw-r-- 1 eshwar eshwar   893 Aug 30 20:21 27a.c
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:22 27b
-rw-rw-r-- 1 eshwar eshwar   574 Aug 30 20:14 27b.c
-rw-rw-r-- 1 eshwar eshwar   538 Aug 30 20:17 27c.c
-rw-rw-r-- 1 eshwar eshwar   465 Aug 30 20:17 27d.c
-rw-rw-r-- 1 eshwar eshwar   601 Aug 30 20:17 27e.c

*/
