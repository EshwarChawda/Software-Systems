/*
============================================================================
Name : 7.c
Author : Eshwar Chawda
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 25th August, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
          int fd_read=open("file_7a.txt",O_RDONLY);
	  int fd_write=open("file_7b.txt",O_WRONLY|O_CREAT,0644);
	  if(fd_write==-1||fd_read==-1)
		  printf("Useless");
	  while(1)
	  {
	  char buf;
	 int char_read=read(fd_read,&buf,1);
	 if (char_read==0)
		break;
	 int char_written=write(fd_write,&buf,1);
	  }
	  int fd_read_close=close(fd_read);
	  int fd_write_close=close(fd_write);

	  if(fd_read_close==-1||fd_write_close==-1)
		  printf("Totally useless");
	return 0;
}
