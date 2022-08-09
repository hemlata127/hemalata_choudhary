/*
Problem Statement: Accept a string from the user and accept filename. Write the string at the end of the file.
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//function declaration
void AppendStringToFile(char*, char*);

//main function
int main(void)
{
	char filename[50] = "\0";
	char str[100] = "\0";
	
	printf("Enter file name: ");
	scanf("%[^\n]s",filename);
	
	getchar();
	
	printf("Enter string to append: ");
	scanf("%[^\n]s",str);
	
	AppendStringToFile(filename,str);
	
	exit(0);
}

//function definition
void AppendStringToFile(char* filename,char* str)
{
	int fd = 0;
	
	fd = open(filename,O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return;
	}
	
	//move to the end of the file
	lseek(fd,0,SEEK_END);
	
	write(fd,str,sizeof(str));	
	
	close(fd);
}