/*
Problem Statement: Write a program which accept file name and mode from user and then open that file in
specified mode
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Error: Insufficient arguments\n");
		return -1;
	}
	int mode = atoi(argv[2]);
	int fd = 0;
	
	switch(mode)
	{
		case 1:
			fd = open(argv[1],O_RDONLY);
			if(fd == -1)
			{
				printf("Error: Unable to open the file\n");
				return -1;
			}
			else
			{
				printf("File successfully opened in READ only mode with FD %d\n",fd);
			}
			break;
			
		case 2:
			fd = open(argv[1],O_WRONLY);
			if(fd == -1)
			{	
				printf("Error: Unable to open the file\n");
				return -1;
			}
			else
			{
				printf("File successfully opened in WRITE only mode with FD %d\n",fd);
			}
			break;
			
		case 3:
			fd = open(argv[1],O_RDWR);
			if(fd == -1)
			{
				printf("Error: Unable to open the file\n");
				return -1;
			}
			else
			{
				printf("File successfully opened in READ WRITE mode with FD %d\n",fd);
			}
			break;
			
		case 4:
			fd = open(argv[1],O_APPEND);
			if(fd == -1)
			{
				printf("Error: Unable to open the file\n");
				return -1;
			}
			else
			{
				printf("File successfully opened in APPEND mode with FD %d\n",fd);
			}
			break;
			
		default:
			printf("Error: Incorrect mode\n");
			return -1;
	}
	
	close(fd);
	
	return 0;
}