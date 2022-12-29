/*
Program that demonstrates atomic write operation
use as: ./myexe Data.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		printf("use as: ./myexe Data.txt\n");
		return -1;
	}
	
	int fd = 0;
	int ret = 0;
	char buffer[30] = "Choudhary";
	
	fd = open(argv[1],O_WRONLY);
	if(fd == -1}
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	pwrite(fd,buffer,10,9);
	//1: File descriptor
	//2: Address of buffer 
	//3: No of bytes to write
	//4: offset from where we want to read(new parameter)
	
	printf("\n");
	
	close(fd);
	
	return 0;
}