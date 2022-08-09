/*
Problem Statement: Accept a string from the user and convert it to lower case
Enter string: Unix Operating System
Entered string in lower case = unix operating system
*/

//header file
#include<stdio.h>
#include<stdlib.h>

//function declaration
void ConvertToLower(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	ConvertToLower(str);
	printf("Entered string in lower case = %s\n",str);
	
	exit(0);
}

//function definition
void ConvertToLower(char* str)
{
	while(*str != '\0')
	{
		if((*str>='A')&&(*str<='Z'))
		{
			*str = (*str + 32);
		}
		str++;
	}
}
