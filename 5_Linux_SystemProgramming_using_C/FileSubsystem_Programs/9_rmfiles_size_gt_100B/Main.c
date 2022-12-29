/*
4. Write a program which accept directory name from user and delete all such files whose
size is greater than 100 bytes. 
Usage: ./myexe dirname
dirname is name of directory whose files are to be deleted
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>

void DeleteFiles(char *dname)
{
	//pointer of type DIR - to hold return value of opendir
	DIR *dp = NULL;
	//pointer of type struct dirent - to hold return value of readdir
	struct dirent *dip = NULL;
	//variable to hold file path
	char name[256] = {'\0'};
	//object of stat structure - to hold file information
	struct stat sobj;
	//variable to hold return value of stat system call
	int ret = 0;
	
	//open directory
	dp = opendir(dname);
	if(dp == NULL)
	{
		printf("Unable to open directory: %s\n",dname);
		return;
	}
	
	//read directory and delete files greater than 100B
	while((dip = readdir(dp)) != NULL)
	{
		//create path from file name
		sprintf(name,"%s/%s",dname,dip->d_name);
		//call stat system call with filename to fetch file information
		ret = stat(name,&sobj);
		//iterate for regular files only
		if(S_ISREG(sobj.st_mode))
		{
			//check for file size
			if(sobj.st_size > 100)
			{
				//delete file
				ret = unlink(name);
				if(ret != 0)
				{
					printf("Could not delete file %s\n",name);
				}
			}
		}
	}
	
	//close directory
	closedir(dp);
}

int main(int argc, char *argv[])
{
	//check for invalid number of arguments
	if(argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as: ./myexe dirname\n");
		return -1;
	}
	
	DeleteFiles(argv[1]);
	
	return 0;
}