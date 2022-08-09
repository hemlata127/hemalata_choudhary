/*
Problem Statement: Accept a filename from the user. Accept a number and display those many number of characters from the file
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//function declaration
void DisplayFile(char*,int);

//main function
int main(void)
{
	char filename[50] = "\0";
	int N = 0;
	
	printf("Enter file name: ");
	scanf("%[^\n]s",filename);
	getchar();
	printf("Enter number of characters to read: ");
	scanf("%d",&N);
	
	DisplayFile(filename,N);
	
	exit(0);
}

//function definition
void DisplayFile(char* filename,int N)
{
	int fd = 0;
	int size = 0;
	char buffer[512] = "\0";
	int count = 0;
	char* ch = NULL;
	
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return;
	}
	
	ch = (char*)malloc(N*sizeof(char));
		
	count = read(fd,ch,N);
	write(1,ch,count);
		
	close(fd);
}