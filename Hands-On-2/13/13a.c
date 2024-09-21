/*
============================================================================
Name : 13a.c
Author : Eshwar Chawda
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 14th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
void print()
{
    printf("Received SIGSTOP");
}
void main()
{

    __sighandler_t status = signal(SIGSTOP, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler");
    }
    sleep(15);
}/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/13$ gcc 13a.c -o 13a
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/13$ ./13a &
[1] 17598
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/13$ Error while assigning signal handler: Invalid argument
gcc 13b.c -o 13b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/13$ ./13b
Enter process id
17598
Error while sending kill signal!: No such process
[1]+  Done                    ./13a

============================================================================
*/
