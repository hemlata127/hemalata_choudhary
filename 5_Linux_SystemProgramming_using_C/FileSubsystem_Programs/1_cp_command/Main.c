/*
Implementation of cp command:
Problem Statement: Implement cp command which is used to copy contents from one file into another file.
Usage:
cp File1.txt File2.txt
We have to create File2.txt and write all the data from File1.txt into it.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//cp Demo.txt Hello.txt
//cp argv[1] argv[2]
//argv[1] - open file in read mode
//argv[2] - create new file

int CP_Command(char *src, char *dest)
{
	int fdsrc = 0, fddest = 0;
	int iRet1 = 0,iRet2 = 0;
	char buffer[1024] = {'\0'};
	
	//open source file in read mode
	fdsrc = open(src,O_RDONLY);
	if(fdsrc == -1)
	{
		printf("Inable to open source file: %s\n",src);
		return -1;
	}
	
	//create destination file
	fddest = creat(dest,0777);
	if(fddest == -1)
	{
		printf("Unable to create destination file: %s\n",dest);
		close(fdsrc);
		return -1;
	}
	
	//copy contents from source file into destination file in chunks of 1024 bytes
	while((iRet1 = read(fdsrc,buffer,sizeof(buffer))) != 0)
	{
		write(fddest,buffer,iRet1);
	}
	
	close(fdsrc);
	close(fddest);
	
	printf("Copy successful\n");
	
	return 0;
}

int main(int argc, char *argv[])
{
	
	//check for invalid number of arguments
	if(argc != 3)
	{
		printf("Error: Invalid Arguments\n");
		printf("Usage: cp Source.txt Destination.txt\n");
		return -1;
	}
	
	CP_Command(argv[1],argv[2]);
	
	return 0;
}