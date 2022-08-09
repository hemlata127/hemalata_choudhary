/*
Problem Statement: Accept a filename from the user and count the number of whitespaces in itoa
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

//function declaration
int CountWhitespacesInFile(char*);

//main function
int main(void)
{
	char filename[50] = "\0";
	int count_whitespaces = 0;
	
	printf("Enter filename: ");
	scanf("%[^\n]s",filename);
	
	count_whitespaces = CountWhitespacesInFile(filename);
	if(count_whitespaces != -1)
	{
		printf("Number of whitespaces in the file = %d\n",count_whitespaces);
	}
	
	exit(0);
}

//function definition
int CountWhitespacesInFile(char* filename)
{
	int fd = 0;
	char buffer[512] = "\0";
	int count = 0;
	int count_whitespaces = 0;
	int i = 0;
	
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	while((count = read(fd,buffer,sizeof(buffer))) != 0)
	{
		for(i=0;i<count;i++)
		{
			if((buffer[i] == ' ')||(buffer[i] == '\t')||(buffer[i] == '\n'))
			{
				count_whitespaces++;
			}
		}
	}
	
	close(fd);
	
	return count_whitespaces;	
}