/*
3. Write a program which accept two file names from user and check whether contents of
that two files are equal are not. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL FileCompare(char *file1,char *file2)
{
	int fd1 = 0,fd2 = 0;
	fd1 = open(file1,O_RDONLY);
	if(fd1 == -1)
	{
		printf("Unable to open file %s",file1);
		return -1;
	}
	fd2 = open(file2,O_RDONLY);
	if(fd2 == -1)
	{
		printf("Unable to open file %s",file2);
		close(fd1);
		return -1;
	}
	
	BOOL bRet = TRUE;
	int ret1 = 0, ret2 = 0;
	int i = 0;
	char buffer1[1024] = {'\0'};
	char buffer2[1024] = {'\0'};
	while((ret1 = read(fd1,buffer1,sizeof(buffer1))) != 0)
	{
		ret2 = read(fd2,buffer2,sizeof(buffer2));
		for(i=0;i<ret1;i++)
		{
			if(buffer1[i] != buffer2[i])
			{
				bRet = FALSE;
				break;
			}
		}
	}
	return bRet;
}

int main(int argc, char *argv[])
{
	//check for invalid number of arguments
	if(argc != 3)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as filecmp file1 file2");
		return -1;
	}
	
	BOOL bRet = FALSE;
	bRet = FileCompare(argv[1],argv[2]);
	
	if(bRet==TRUE)
	{
		printf("Equal\n");
	}
	else
	{
		printf("Unequal\n");
	}
	
	return 0;
}