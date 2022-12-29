/*
Problem statement: File unpacker
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

//structure to hold file information
struct Fileinfo
{
	char Filename[256];
	int Filesize;
};

void Fileunpacker(char *fname)
{
	//file descriptor for source file
	int fdsrc = 0;
	//file descriptor for destination file
	int fddest = 0;
	//buffer to read data
	char *buffer = NULL;
	//object of Fileinfo structure
	struct Fileinfo fobj;
	int iRet = 0;
	
	//open the file
	fdsrc = open(fname,O_RDONLY);
	if(fdsrc == -1)
	{
		printf("Unable to open the file %s",fname);
		return;
	}
	
	//read file information structure from source file
	while((iRet = read(fdsrc,&fobj,sizeof(fobj))) != 0)
	{
		//printf("Filename: %s\tFilesize: %d\n",fobj.Filename,(int)fobj.Filesize);
		//lseek(fdsrc,fobj.Filesize,SEEK_CUR);
		
		//create file with the read file name
		fddest = creat(fobj.Filename,0777);
		if(fddest == -1)
		{
			printf("Error: Unable to create file %s",fobj.Filename);
			return;
		}
				
		//buffer to read file contents
		buffer  = (char*) malloc(fobj.Filesize);
		//read file contents
		read(fdsrc,buffer,fobj.Filesize);
		//write read contents
		write(fddest,buffer,fobj.Filesize);
		
		//clean the buffer
		memset(buffer,0,sizeof(buffer));
		
		free(buffer);
		close(fddest);
	}
	close(fdsrc);
}

int main(int argc, char *argv[])
{
	//check for invalid number of arguments
	if(argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as fileunpacker filenam\n");
		printf("filename is the name of the file that we want to unpack\n");
		return -1;
	}
	
	Fileunpacker(argv[1]);
	
	return 0;
}
