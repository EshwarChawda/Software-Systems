/*
============================================================================
Name : 16.c
Author : Eshwar Chawda
Description : Write a program to perform mandatory locking. 
a. Implement write lock
b. Implement read lock
Date: 25th August, 2024.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/file.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	struct flock lock;
	int fd;
	fd=open("db",O_RDWR);
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before entering C.S.\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside critical sec\n");
    char *buff="writing in buffer";
    write(fd,buff,sizeof(buff));
    sleep(30);
	printf("Enter to unlock\n");
	getchar();
	printf("Unlocked\n");
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Finish\n");
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/16$ gcc 16.c -o 16
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/16$ ./16
Before entering C.S.
Inside critical sec
This is 16
Enter to unlock
Unlocked
Finish

*/
