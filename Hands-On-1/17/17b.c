/*
============================================================================
Name : 17b.c
Author : Eshwar Chawda
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
    int ticketNumber;
    int fileDescriptor = open("file_17.txt", O_RDWR);
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
    read(fileDescriptor, &ticketNumber, sizeof(ticketNumber));
    ticketNumber++;
    lseek(fileDescriptor, 0, SEEK_SET);
    write(fileDescriptor, &ticketNumber, sizeof(ticketNumber));
    flock(fileDescriptor, LOCK_UN);
    close(fileDescriptor);
    printf("New ticket number: %d\n", ticketNumber);
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/17$ gcc 17b.c -o 17b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/17$ ./17b
file open succesfully
lock applied successfully
New ticket number: 2

*/
