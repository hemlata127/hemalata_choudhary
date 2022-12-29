/*
Problem statement: Implement file packer.
It reads all regular files in a directory and copies its contents in a file
Usage: filepacker dirname filename
file name file size, file contents of all regular files from directory dirname are copied to filename
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

//structure to hold file information
struct Fileinfo
{
	char Filename[256];
	int Filesize;
};

/*
argv[1] - directory name - open dir

*/
void Filepacker(char *dname, char *fname)
{
	//variable to hold return value of opendir, DIR is typedef of a structure 
	//this structure contains fd of directory and other directory information
	DIR *dp = NULL;
	//variable to hold return value of readdir system call, object of dirent structure
	struct dirent *dip = NULL;
	//object of struct stat
	struct stat sobj;
	//variable to hold path name of file
	char name[256] = {'\0'};
	//variable to hold return value of creat system call(fd of file)
	int fdsrc = 0, fddest = 0;
	int ret = 0;
	//create object of Fileinfo structure
	struct Fileinfo fobj;
	//buffer to read data
	char buffer[1024] = {'\0'};
		
	//open source directory
	dp = opendir(dname);
	if(dp == NULL)
	{
		printf("Error: Unable to open directory: %s\n",dname);
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
	
	while((dip = readdir(dp)) != NULL)
	{
		//printf("Filename: %s\t",dip->d_name);
		//generate path name of file
		sprintf(name,"%s/%s",dname,dip->d_name);
		//call stat function, pass file name and address of object of stat structure
		ret = stat(name,&sobj);
		//printf("Filesize: %ld\n",sobj.st_size);
		//iterate only for regular files
		if(S_ISREG(sobj.st_mode))
		{
			//fill file information in fobj
			strcpy(fobj.Filename,dip->d_name);		//copy file name
			fobj.Filesize = sobj.st_size;			//copy file size
			
			//write fobj (file information) to destination file
			write(fddest,&fobj,sizeof(fobj));
			
			//clean fobj memory
			memset(&fobj,0,sizeof(fobj));
			
			fdsrc = open(name,O_RDONLY);
			
			//write file contents to destination file
			while((ret = read(fdsrc,buffer,sizeof(buffer))) != 0)
			{
				write(fddest,buffer,ret);
			}
			
			//clean the buffer
			memset(buffer,0,sizeof(buffer));
			
			//close the source file
			close(fdsrc);
		}
	}
	//close destination file
	close(fddest);
	//close directory
	closedir(dp);
}

int main(int argc, char *argv[])
{
	//check for invalid number of arguments
	if(argc != 3)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Use as: filepacker dirname filename\n");
		printf("dirname: name of directory whose files should be packed\n");
		printf("filename: file that will have contents of packed files\n");
		return -1;
	}
	
	Filepacker(argv[1],argv[2]);
	
	return 0;
}