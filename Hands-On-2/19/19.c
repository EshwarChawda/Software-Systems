/*
============================================================================
Name : 19.c
Author : Eshwar Chawda
Description : Create a FIFO file by
    a.mknod command
    b.mkfifo command
    c.use strace command to find out,which command(mknod or mkfifo) is better.
    d.mknod system call
    e.mkfifo library function
Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
int main()
{
    int o = mkfifo("./mkfifo_syscall", S_IRWXU);
    if (o == 0)
    {
        printf("fifo special file is created\n");
    }

    int f = mknod("./fifo_using_mknode_sys_call", S_IRWXU | S_IFIFO, 0);
    if (f == 0)
    {
        printf("fifo special file is created\n");
    }
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/19$ gcc 19.c -o 19
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/19$ ./19
fifo special file is created
fifo special file is created
============================================================================
*/
