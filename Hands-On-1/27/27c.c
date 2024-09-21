/*
============================================================================
Name : 27.c
Author : Eshwar Chawda
Description : Write a program to execute ls -Rl by the following system calls.
c. execle
Date: 27th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    char *args[] = {"ls", "-Rl", NULL};
    char *env[] = {NULL};  // Passing an empty environment

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execle("/bin/ls", "ls", "-Rl", NULL, env);
        
        // If execle fails
        perror("execle failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Wait for the child to complete
        wait(NULL);
    }
    
    /*
    eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ gcc 27c.c -o 27c
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/27$ ./27c
.:
total 100
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:20 27a
-rw-rw-r-- 1 eshwar eshwar   893 Aug 30 20:21 27a.c
-rwxrwxr-x 1 eshwar eshwar 15952 Aug 30 20:22 27b
-rw-rw-r-- 1 eshwar eshwar  1076 Aug 30 20:22 27b.c
-rwxrwxr-x 1 eshwar eshwar 16208 Aug 30 20:39 27c
-rw-rw-r-- 1 eshwar eshwar  1037 Aug 30 20:38 27c.c
-rwxrwxr-x 1 eshwar eshwar 16000 Aug 30 20:25 27d
-rw-rw-r-- 1 eshwar eshwar  1067 Aug 30 20:26 27d.c
-rwxrwxr-x 1 eshwar eshwar 16000 Aug 30 20:31 27e
-rw-rw-r-- 1 eshwar eshwar  1314 Aug 30 20:32 27e.c
-rw-rw-r-- 1 eshwar eshwar     0 Aug 30 20:28 file_27c.txt

    */

    return 0;
}


