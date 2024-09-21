/*
============================================================================
Name : 25.c
Author : Eshwar Chawda
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call)
Date: 27th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
    int status;
    pid_t pid,child_pid[3];
    pid_t pid1,pid2,pid3;
    pid1=fork();
    if(pid1==-1){
        printf("fork failed for pid1");
    }else{
        printf("child process 1\n");
    }
    pid2=fork();
    if(pid2==-1){
        printf("fork failed for pid1");
    }else{
        sleep(10);
        printf("child process 2\n");
    }
    pid3=fork();
    if(pid3==-1){
        printf("fork failed for pid1");
    }else{
        printf("child process 3\n");
    }
    pid_t pickpid=pid2;
    printf("parent waiting for pid%d\n",pickpid);
    pid=waitpid(pickpid, &status, 0);
    if(pid==-1){
        printf("waitpid error\n");
    }
    if(WIFEXITED(status)){
        printf("Parent: Child with PID %d exited with status %d\n",pid,WIFEXITED(status));
    }
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/25$ gcc 25.c -o 25
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/25$ ./25
child process 1
child process 1
child process 2
child process 3
parent waiting for pid21904
child process 3
parent waiting for pid21904
waitpid error
Parent: Child with PID -1 exited with status 1
child process 2
child process 2
child process 3
parent waiting for pid21905
child process 3
parent waiting for pid0
child process 3
parent waiting for pid21905
waitpid error
Parent: Child with PID -1 exited with status 1
child process 3
parent waiting for pid0
waitpid error
Parent: Child with PID -1 exited with status 1
Parent: Child with PID 21914 exited with status 1
Parent: Child with PID 21904 exited with status 1
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/25$ child process 2
child process 3
parent waiting for pid0
child process 3
parent waiting for pid0
waitpid error
Parent: Child with PID -1 exited with status 1
Parent: Child with PID 21915 exited with status 1
Parent: Child with PID 21905 exited with status 1

*/
