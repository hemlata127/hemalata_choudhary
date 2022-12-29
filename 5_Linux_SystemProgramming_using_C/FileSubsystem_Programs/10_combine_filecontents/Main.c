/*
4. Write a program which accept directory name from user and combine all contents of file
from that directory into one file named as AllCombine. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

void CombineAll(char *dname,char *fname)
{
	//pointer to hold return value of opendir
	DIR *dp = NULL;
	//pointer to hold return value of readdir
	struct dirent *dip = NULL;
	//variable to hold fd for source and destination files
	int fddest = 0,fdsrc = 0;
	//object of structure stat - to hold file information
	struct stat sobj;
	//variable to hold return value of stat
	int ret = 0;
	//buffer to read, write file data
	char buffer[1024] = {'\0'};
	//variable to hod file path
	char name[256] = {'\0'};
	
	//open directory
	dp = opendir(dname);
	if(dp == NULL)
	{
		printf("Error: Unable to open directory %s\n",dname);
		return;
	}
	
	//create destination file
	fddest = creat(fname,0777);
	if(fddest == -1)
	{
		printf("Error: Unable to create file %s\n",fname);
		closedir(dp);
		return;
	}
	
	//read directory - iterate through directory entries
	while((dip = readdir(dp)) != NULL)
	{
		//create file path - as stat system call needs file path as parameter
		sprintf(name,"%s/%s",dname,dip->d_name);
		ret = stat(name,&sobj);
		//iterate through regular files
		if(S_ISREG(sobj.st_mode))
		{
			fdsrc = open(name,O_RDONLY);
			if(fdsrc == -1)
			{
				printf("Unable to open file %s\n",name);
				break;
			}
			//read the entire source file and write in destination file
			while((ret = read(fdsrc,buffer,sizeof(buffer))) != 0)
			{
				write(fddest,buffer,ret);
			}
			//close the source file after contents are read
			close(fdsrc);
		}
	}
	//close directory
	closedir(dp);
}

int main(int argc, char *argv[])
{
	//check for invalid number of arguments
	if(argc != 3)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as: ./myexe dirname filename");
		return -1;
	}
	
	CombineAll(argv[1],argv[2]);
	
	return 0;
}