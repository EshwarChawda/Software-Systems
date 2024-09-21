/*
============================================================================
Name : 20b.c
Author : Eshwar Chawda
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 14th Sep, 2024.
============================================================================
*/
#include <sys/types.h> // Import for `open`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `read`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    char *file = "./20-fifo";
    int fd = open(file, O_RDONLY); // File descriptor of the FIFO file

    while (1)
    {
        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
        }
        close(fd);
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
