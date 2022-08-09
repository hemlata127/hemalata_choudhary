/*
Problem Statement: Write a program to accept filename from the user and display its file size
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int FindFilesize(char*);

int main(void)
{
	char filename[50] = "\0";
	int size = 0;
	
	printf("Enter file name: ");
	scanf("%[^\n]s",filename);
	
	size = FindFilesize(filename);
	if(size != -1)
	{
		printf("File size = %d bytes\n",size);
	}
	
	exit(0);
}

int FindFilesize(char* filename)
{
	int fd = 0;
	int count = 0;
	
	//open the file
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	//use lseek to fetch last byte offset of the file
	count = lseek(fd,0,SEEK_END);
	
	//close the file
	close(fd);
	
	return count;
}