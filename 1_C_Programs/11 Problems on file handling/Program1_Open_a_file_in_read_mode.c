/*
Problem Statement: Accept a file name form the user and open that file in read mode
Enter file to open: readme.txt
File opened successfully with file descriptor 3
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//function declaration
void OpenFile(char*);

//entry point function
int main(void)
{
	char filename[50] = "\0";
	
	printf("Enter file to open: ");
	scanf("%[^\n]s",filename);
	
	OpenFile(filename);
	
	exit(0);
}

//function definition
void OpenFile(char* filename)
{
	int fd = 0;
	
	//open the file
	fd = open(filename,O_RDONLY);
	
	if(fd == -1)
	{
		printf("File not opened\n");
	}
	else
	{
		printf("File opened successfully with file descriptor %d\n",fd);
	}
	
	//close the file
	close(fd);
}