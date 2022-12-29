/*
Problem Statement: Implementation of the mkdir command
Use as: ./mkdir dirname
dirname is name of directory to be created
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

void CreateDir(char *dname)
{
	//variable to hold return value of mkdir system call
	int iRet = 0;
	iRet = mkdir(dname,0775);
	if(iRet == -1)
	{
		printf("Error: Unable to create directory\n");
		return;
	}
}

int main(int argc,char *argv[])
{
	//check for invalid number of arguments
	if(argc != 2)
	{
		printf("Error: Invaid number of arguments\n");
		printf("Use as: mkdir dirname\n");
		printf("dirname is the name of directory to be created\n");
		return -1;
	}
	
	CreateDir(argv[1]);
	
	return 0;
}