/*
============================================================================
Name : 10c.c
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

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE: Floating-point exception occurred.\n");
    exit(1);  
}

int main() {
  
    struct sigaction sa;

    sa.sa_handler = handle_sigfpe;

    sigemptyset(&sa.sa_mask);

    sa.sa_flags = 0;

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Triggering division by zero to raise SIGFPE...\n");

    int a = 10;
    int b = 0;
    int c = a / b; 

    printf("This line will not be printed, result: %d\n", c);

    return 0;
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/10$ gcc 10c.c -o 10c
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/10$ ./10c
Triggering division by zero to raise SIGFPE...
Caught SIGFPE: Floating-point exception occurred.
============================================================================
*/
