/*
============================================================================
Name : 10a.c
Author : Eshwar Chawda
Description :Write a separate program using sigaction system call to catch the following signals.
 a. SIGSEGV
 b. SIGINT
 c. SIGFPE
Date: 14th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void segfault_handler(int signum) {
    printf("Caught SIGSEGV: Segmentation Fault occurred.\n");
    exit(1);
}

int main() {

    struct sigaction sa;

    sa.sa_handler = segfault_handler;

    sigemptyset(&sa.sa_mask);

    sa.sa_flags = 0;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Raising SIGSEGV by dereferencing a NULL pointer...\n");

    int *p = NULL;
    *p = 42;  
    printf("This line will not be printed.\n");

    return 0;
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/10$ gcc 10a.c -o 10a
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/10$ ./10a
Raising SIGSEGV by dereferencing a NULL pointer...
Caught SIGSEGV: Segmentation Fault occurred.
============================================================================
*/

