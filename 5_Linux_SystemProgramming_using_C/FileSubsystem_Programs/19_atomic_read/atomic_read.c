/*
Program to demonstrate atomic read operation
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd = 0;
	int ret = 0;
	char buffer[30] = {'\0'};
	char path[60] = {'\0'};
	
	fd = open("Data.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	//lseek(fd,10,SEEK_SET);
	//ret = read(fd,buffer,30);	//we get data of targeted file
	
	//atomic read operation
	ret = pread(fd,buffer,30,10);
	//1: File descriptor
	//2: Address of buffer 
	//3: No of bytes to read
	//4: offset from where we want to read(new parameter)
	
	printf("Data is:\n");
	write(1,buffer,ret);
	
	printf("\n");
	
	close(fd);
	
	return 0;
}