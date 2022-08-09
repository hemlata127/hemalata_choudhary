/*
Problem Statement: Accept a string from user and display the number of whitespaces in it
Enter string: Unix      Operating System
Number of whitespaces in entered string = 2
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountWhitespaces(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	int count_whitespaces = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	count_whitespaces = CountWhitespaces(str);
	printf("Number of whitespaces in entered string = %d\n",count_whitespaces);
	
	exit(0);
}

//function definition
int CountWhitespaces(char* str)
{
	int count = 0;
	
	while(*str != '\0')
	{
		if((*str == ' ')||(*str == '\t'))
		{
			count++;
		}
		str++;
	}
	return count;
}