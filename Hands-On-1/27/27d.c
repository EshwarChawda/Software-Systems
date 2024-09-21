/*
============================================================================
Name : 27.c
Author : Eshwar Chawda
Description : Write a program to execute ls -Rl by the following system calls.
d. execv
Date: 27th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "/bin/ls";
    char *argv[] = {path,"-Rl",NULL};
    execv(path, argv);
    return 0;
}
/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ gcc 27d.c -o 27d
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ ./27d
.:
total 84
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:20 27a
-rw-rw-r-- 1 eshwar eshwar   893 Aug 30 20:21 27a.c
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:22 27b
-rw-rw-r-- 1 eshwar eshwar  1076 Aug 30 20:22 27b.c
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:23 27c
-rw-rw-r-- 1 eshwar eshwar   538 Aug 30 20:17 27c.c
-rwxrwxr-x 1 eshwar eshwar 16000 Aug 30 20:25 27d
-rw-rw-r-- 1 eshwar eshwar   465 Aug 30 20:17 27d.c
-rw-rw-r-- 1 eshwar eshwar   601 Aug 30 20:17 27e.c

*/
