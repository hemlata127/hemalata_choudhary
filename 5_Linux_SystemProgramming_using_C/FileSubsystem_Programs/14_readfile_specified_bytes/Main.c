/*
Problem statement: Write a program which accept file name and number of bytes from user and read that
number of bytes from file. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Error: Insufficient arguments\n");
		return -1;
	}
	
	int fd = 0;
	int rd = 0;
	int iNo = 0;
	char arr[20]={'\0'};
	
	fd = open(argv[1],O_RDWR);
	if(fd == -1)
	{
		printf("Error: Unable to open the file\n");
		return -1;
	}
	rd = read(fd,arr,atoi(argv[2]));
	if(rd == 0)
	{
		printf("Error: File is empty\n");
		return -1;
	}
	printf("Data from file: %s\n",arr);
	
	return 0;
}
