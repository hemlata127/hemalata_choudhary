/*
Problem statment: Write a program which accept file name from user and write string in that file
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Error: Insufficient arguments\n");
		return -1;
	}
	
	char arr[] = "Hemalata Choudhary";
	int fd = 0;
	int iRet = 0;
	
	fd = open(argv[1],O_WRONLY | O_CREAT,0777);
	
	iRet = write(fd,arr,sizeof(arr));
	
	close(fd);
	
	return 0;
}