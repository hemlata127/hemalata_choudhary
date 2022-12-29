/*
3. Write a aprogram which accept directory name and file name from user and create file in
that directory.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void CreateFile(char *dirname,char *filename)
{
	char *name[256] = {'\0'};
	int ret = 0;
	//create pathname
	sprintf(name,"%s/%s",dirname,filename);
	//create file
	ret = creat(name,0777);
	if(ret == -1)
	{
		printf("Error: Unable to create file\n");
		return;
	}
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as: myexe dirname filename\n");
		return -1;
	}
	
	CreateFile(argv[1],argv[2]);
	
	return 0;
}

