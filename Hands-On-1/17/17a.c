/*
============================================================================
Name : 17.c
Author : Eshwar chawda
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 26th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

int main() {
    int ticketNumber = 1;
    int fileDescriptor = open("file_17a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fileDescriptor == -1) {
        perror("Failed to open the file");
        return 1;
    }else{
        printf("file open succesfully\n");
    }
    if (flock(fileDescriptor, LOCK_EX) == -1) {
        perror("Failed to lock the file");
        return 1;
    }else{
        printf("lock applied successfully\n");
    }
    write(fileDescriptor, &ticketNumber, sizeof(ticketNumber));
    flock(fileDescriptor, LOCK_UN);
    close(fileDescriptor);
    
    printf("Ticket reservation successful.\n");
    
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/17$ gcc 17a.c -o 17a
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/17$ ./17a
file open succesfully
lock applied successfully
Ticket reservation successful.

*/
