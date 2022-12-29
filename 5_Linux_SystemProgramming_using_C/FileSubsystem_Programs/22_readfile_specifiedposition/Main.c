/*
Problem statement: Write a program which accept file name and position from user and read 20 bytes from
that position.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void ReadFile(char *filename,int iPos)
{
	//variable for file descriptor
	int fd = 0;
	//variable to hold return value of read and write
	int iRet1 = 0,iRet2 = 0;
	//buffer to hold 20 bytes
	char buffer[20] = {'\0'};
	
	//open file
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file %s\n",filename);
		return;
	}
	
	//go to specified file position
	lseek(fd,iPos,SEEK_SET);
	
	//read 20 bytes from that position
	iRet1 = read(fd,buffer,20);
	if(iRet1 == -1)
	{
		printf("Unable to read file %s\n",filename);
		return;
	}
	
	//display read data on console
	iRet2 = write(1,buffer,iRet1);
	
	//close the file
	close(fd);
}


int main(int argc, char *argv[])
{
	//check for invalid number of arguments
	if(argc != 3)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as: ./myexe filename position\n");
		return -1;
	}
	
	ReadFile(argv[1],atoi(argv[2]));
		
	return 0;
}