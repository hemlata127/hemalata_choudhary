/*
Problem statement: Program that renames a file
use as: ./myexe oldname newname
If newname parameter is directory path, this works like move
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	//check for invalid number of arguments
	if(argc != 3)
	{
		printf("Error: Invalid number of arguments\n");
		printf("use as: ./myexe oldname newname\n");
		return -1;
	}
	
	int ret = 0;
	//			old filename	new filename
	ret = rename(argv[1],argv[2]);
	if(ret == -1)
	{
		printf("Error in rename\n");
		return -1;
	}
	
	printf("Rename successful\n");
	
	return 0;
}