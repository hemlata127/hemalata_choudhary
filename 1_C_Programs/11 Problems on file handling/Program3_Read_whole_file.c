/*
Problem Statement:
Write a program to accept file name from the user and display contents of that file
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//function declaration
void DisplayFileContents(char*);

//main function
int main(void)
{
	char filename[50] = "\0";
	
	printf("Enter file name: ");
	scanf("%[^\n]s",filename);
	
	DisplayFileContents(filename);	
	
	exit(0);
}

//function definition
void DisplayFileContents(char* filename)
{
	int fd = 0;
	int count = 0;
	char buffer[512] = "\0";
	
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Failure in opening the file\n");
		return;
	}
	
	while((count = read(fd,buffer,sizeof(buffer))) != 0)
	{
		write(1,buffer,count);
	}
	
	close(fd);
}