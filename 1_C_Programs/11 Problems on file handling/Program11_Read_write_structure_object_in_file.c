/*
Problem Statement: Write a program which accepts information of students from user and write that information into the file.
It also reads the file based on user choice
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

//structure declaration to store student information
struct student
{
	char name[25];
	int age;
	int marks;
};

//function declaration
void WriteStudentInformation(char*,struct student*);
void ReadStudentInformation(char*);

//main function
int main(void)
{
	char filename[50] = "\0";
	int choice = 1;
	struct student sobj;
	printf("Enter file name: ");
	scanf("%[^\n]s",filename);
	
	while(choice != 0)
	{
		printf("Enter your choice: \n");
		printf("1: Write data\n");
		printf("2: Read data\n");
		printf("0: Exit\n");
		
		scanf("%d",&choice);
		getchar();
		
		switch(choice)
		{
			case 1:
				printf("Enter student name: ");
				scanf("%[^\n]s",sobj.name);
				getchar();
				printf("Enter student age: ");
				scanf("%d",&sobj.age);
				getchar();
				printf("Enter student marks: ");
				scanf("%d",&sobj.marks);
				getchar();
				WriteStudentInformation(filename,&sobj);
				break;
			
			case 2:
				ReadStudentInformation(filename);
				break;
			
			case 0:
				printf("Thank you!!!\n");
				break;
				
			default:
				printf("Invalid choice\n");
		}
	}
	
	exit(0);
}

//function definition
void WriteStudentInformation(char* filename,struct student* sobj)
{
	int fd = 0;
	int ret = 0;
	
	fd = open(filename,O_RDWR | O_CREAT,0777);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return;
	}
	
	lseek(fd,0,SEEK_END);
	ret = write(fd,sobj,sizeof(*sobj));
	if(ret == -1)
	{
		printf("Write to file failed\n");
	}
	else
	{
		printf("Data successfully written to file\n");
	}
	
	close(fd);	
}

void ReadStudentInformation(char* filename)
{
	int fd = 0;
	int count = 0;
	struct student robj;
	
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return;
	}
	
	while((count = read(fd,&robj,sizeof(robj))) != 0)
	{
		printf("Student name = %s\n",robj.name);
		printf("Student age = %d\n",robj.age);
		printf("Student marks = %d\n",robj.marks);
	}
	
	close(fd);
}
