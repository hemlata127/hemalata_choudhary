/*
Problem Statement: Write a program which accept file name from user and print all information about that file. 
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	//object of structure stat
	struct stat fobj;
	//variable to hold return value of stat function
	int iRet = 0;
	
	if(argc != 2)
	{
		printf("Error: Insufficient arguments\n");
		return -1;
	}
	
	//stat system call - returns statistics of file
	//first argument - file name
	//second argument - address of object of stat structure
	iRet = stat(argv[1],&fobj);
	if(iRet == -1)
	{
		printf("Unable to retrieve file information\n");
		return -1;
	}
	printf("Inode number: %d\n",(int)fobj.st_ino);
	printf("Reference count of hard links: %d\n",(int)fobj.st_nlink);
	printf("Userid: %d\n",(int)fobj.st_uid);
	printf("Groupid: %d\n",(int)fobj.st_gid);
	
	return 0;
}
