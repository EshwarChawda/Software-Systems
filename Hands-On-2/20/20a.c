/*
============================================================================
Name : 20a.c
Author : Eshwar Chawda
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 14th Sep, 2024.
============================================================================
*/
#include <sys/types.h> // Import for `mkfifo` & `open`
#include <sys/stat.h>  // Import for `mkfifo` & `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>     // Import for `perror`

void main()
{
    char *s; // Data to be sent through the buffer
    int fd;  // File descriptor of the FIFO file
    long int size = 100;
    char *file = "./20-fifo";
    mkfifo(file, S_IRWXU);
    while (1)
    {
        fd = open(file, O_WRONLY);
        if (fd == -1)
            perror("Error");
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }
    }
}
/*
============================================================================
  TERMINAL: 1
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/20$ gcc 20a.c -o 20a
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/20$ ./20a
enter message:
eshwar

  TERMINAL: 2
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/20$ gcc 20b.c -o 20b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/20$ ./20b
eshwar

============================================================================
*/
