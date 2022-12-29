/*
Problem Statement: Write a program which writes structure in file. Structure should contains information of Employee.
Same program should read that structure from file
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct Employee
{
	char name[30];
	int salary;
	int age;
	char dept[20];
};

void WriteFile(struct Employee *ep,char filename[])
{
	int fd = 0;
	int iRet = 0;
	//create file to write data
	fd = creat(filename,0777);
	if(fd == -1)
	{
		printf("Unable to create the file %s\n",filename);
		return;
	}
	
	iRet = write(fd,ep,sizeof(*ep));
	if(iRet == -1)
	{
		printf("Unable to write to file %s\n",filename);
		return;
	}
	printf("Data written to file successfully\n");
	close(fd);
}

void ReadFile(char filename[])
{
	int fd = 0;
	int iRet1 = 0,iRet2 = 0;
	//buffer to read data
	struct Employee eobj1;
	//open file in read mode
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file %s\n",filename);
		return;
	}
	iRet1 = read(fd,&eobj1,sizeof(eobj1));
	printf("Employee name: %s\nEmployee salary: %d\nEmployee age: %d\nEmployee department: %s\n",eobj1.name,eobj1.salary,eobj1.age,eobj1.dept);
	
	close(fd);
}

int main(int argc, char *argv[])
{
	//create object of structure Employee
	struct Employee eobj;
	//variable to hold filename
	char fname[256] = {'\0'};
	
	//Accept employee details
	printf("Enter employee name:\n");
	scanf("%[^\n]s",eobj.name);
	
	printf("Enter employee salary:\n");
	scanf("%d",&eobj.salary);
	
	printf("Enter employee age:\n");
	scanf("%d",&eobj.age);
	
	printf("Enter employee department:\n");
	scanf("%s",eobj.dept);
	
	printf("Enter filename:\n");
	scanf("%s",fname);
	
	WriteFile(&eobj,fname);
	
	ReadFile(fname);
	
	return 0;
}