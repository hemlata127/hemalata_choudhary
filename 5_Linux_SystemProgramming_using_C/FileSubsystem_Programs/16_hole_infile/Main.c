/*
Problem Statement: Write a program which create hole of size 1kb at the end of file. 
Note: hole can be created only at end of file
Use as: ./myexe Test.c
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	int ret = 0;
	
	if(argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as: ./myexe filename");
		return -1;
	}
	fd = open(argv[1],O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	//create hole of size 1024 bytes at end of file
	ret = lseek(fd,1024,SEEK_END);
	printf("%d\n",ret);
	
	//write a non printable character at end of hole
	write(fd," ",1);
	
	close(fd);
	
	return 0;
}