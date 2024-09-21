/*
============================================================================
Name : 10b.c
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

void handle_sigint(int signum) {
    printf("Caught SIGINT (Ctrl+C). Exiting gracefully.\n");
    exit(0); 
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handle_sigint;

    sigemptyset(&sa.sa_mask);

    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Press Ctrl+C to trigger SIGINT and exit...\n");
    while (1) {
        printf("Running...\n");
        sleep(1);  
    }

    return 0;
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/10$ gcc 10b.c -o 10b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/10$ ./10b
Press Ctrl+C to trigger SIGINT and exit...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
Running...
^CCaught SIGINT (Ctrl+C). Exiting gracefully.

============================================================================
*/

