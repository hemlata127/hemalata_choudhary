/*
Problem Statement: Accept a filename from the user. Accept a character and display number of times that character appears in the file
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

//function declaration
int CountCharacterInFile(char*, char);

//main function
int main(void)
{
	char filename[50] = "\0";
	char search_character = '\0';
	int count_character = 0;
	
	printf("Enter filename: ");
	scanf("%[^\n]s",filename);
	
	getchar();
	
	printf("Enter character to search: ");
	scanf("%c",&search_character);
	
	count_character = CountCharacterInFile(filename,search_character);
	if(count_character != -1)
	{
		printf("%c appears %d times\n",search_character,count_character);
	}
	
	exit(0);
}

//function definition
int CountCharacterInFile(char* filename, char search_character)
{
	int fd = 0;
	char buffer[512] = "\0";
	int i = 0;
	int count_character = 0;
	int count = 0;
	
	fd = open(filename,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	while((count = read(fd,buffer,sizeof(buffer))) != 0)
	{
		for(i=0;i<count;i++)
		{
			if(buffer[i] == search_character)
			{
				count_character++;
			}
		}
	}
	
	close(fd);
	return count_character;
}