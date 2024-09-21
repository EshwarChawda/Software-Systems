/*
============================================================================
Name : 21b.c
Author : Eshwar Chawda
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 14th Sep, 2024.
============================================================================
*/
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *s; 
    int fd;  
    long int size = 100;
    char *file = "./21a-fifo";
    while (1)
    {
        fd = open(file, O_RDONLY); 

        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
            close(fd);
        }

        fd = open(file, O_WRONLY);
        if (fd == -1){
            perror("Error");
        }
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
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/21$ gcc 21a.c -o 21a
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/21$ ./21a
enter message:
eshwar
chawda

enter message:

  TERMINAL: 2
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/21$ gcc 21b.c -o 21b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/21$ ./21b
eshwar

enter message:
chawda
============================================================================
*/
