/*
Problem Statement: Accept a filename from the user. Create file using that name.

Program execution:
Enter file name: test.txt
File created successfully
Use file descriptor 3 for further read write operations
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//function declaration
void CreateFile(char*);

//entry point function
int main(void)
{
	char filename[50] = "\0";
	
	printf("Enter filename: ");
	scanf("%[^\n]s",filename);
	
	CreateFile(filename);
	
	exit(0);
}

//function definition
void CreateFile(char* filename)
{
	int fd = 0;
	
	fd = creat(filename,0777);
	
	if(fd == -1)
	{
		printf("File creation failed\n");
	}
	else
	{
		printf("File created successfully\n");
		printf("Use file descriptor %d for further read write operations\n",fd);
	}
	
	close(fd);
}