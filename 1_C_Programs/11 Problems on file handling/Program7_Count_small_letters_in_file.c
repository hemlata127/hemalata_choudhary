/*
Problem Statement: Accept filename from the user and display the number of small letters in the file
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

//function declaration
int CountSmallLettersInFile(char*);

//main function
int main(void)
{
	char filename[50] = "\0";
	int count_small = 0;
	
	printf("Enter filename: ");
	scanf("%[^\n]s",filename);
	
	count_small = CountSmallLettersInFile(filename);
	if(count_small != -1)
	{
		printf("Number of small letters = %d\n",count_small);
	}
	
	exit(0);
}

//function definition
int CountSmallLettersInFile(char* filename)
{
	int fd = 0;
	int count = 0;
	int count_small = 0;
	char buffer[512] = "\0";
	int i = 0;
	
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	while((count = read(fd,buffer,sizeof(buffer))) != 0)
	{
		for(i=0;i<count;i++)
		{
			if((buffer[i] >= 'a')&&(buffer[i] <= 'z'))
			{
				count_small++;
			}
		}
	}
	
	close(fd);
	
	return count_small;
}