/*
============================================================================
Name : 27.c
Author : Eshwar Chawda
Description : Write a program to execute ls -Rl by the following system calls.
a. execl
Date: 27th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL);
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ gcc 27a.c -o 27a
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ ./27a
.:
total 36
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:20 27a
-rw-rw-r-- 1 eshwar eshwar   440 Aug 30 20:17 27a.c
-rw-rw-r-- 1 eshwar eshwar   574 Aug 30 20:14 27b.c
-rw-rw-r-- 1 eshwar eshwar   538 Aug 30 20:17 27c.c
-rw-rw-r-- 1 eshwar eshwar   465 Aug 30 20:17 27d.c
-rw-rw-r-- 1 eshwar eshwar   601 Aug 30 20:17 27e.c

*/
