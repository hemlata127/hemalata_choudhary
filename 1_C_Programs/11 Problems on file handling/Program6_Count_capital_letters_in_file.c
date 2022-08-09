/*
Problem Statement: Accept a filename from the user and count capital characters in that file
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

//function declaration
int CountCapital(char*);

//main function
int main(void)
{
	char filename[50] = "\0";
	int count_capital = 0;
	
	printf("Enter file name: ");
	scanf("%[^\n]s",filename);
	
	count_capital = CountCapital(filename);
	if(count_capital != -1)
	{
		printf("Number of capital letters in file = %d\n",count_capital);
	}
	
	exit(0);
}

//function definition
int CountCapital(char* filename)
{
	int fd = 0;
	int count = 0;
	int count_capital = 0;
	int i = 0;
	char buffer[512];
	
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
			if((buffer[i] >= 'A')&&(buffer[i]<='Z'))
			{
				count_capital++;
			}
		}
	}
	
	close(fd);
	
	return count_capital;
}
