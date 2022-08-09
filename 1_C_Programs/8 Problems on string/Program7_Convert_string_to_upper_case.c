/*
Problem Statement: Accept a string from the user and convert it to upper case
Enter string: Unix Opearting System
Entered string in upper case = UNIX OPEARTING SYSTEM
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void ConvertToUpper(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	ConvertToUpper(str);
	
	printf("Entered string in upper case = %s\n",str);
	
	exit(0);
}

//function definition
void ConvertToUpper(char* str)
{
	while(*str != '\0')
	{
		if((*str>='a')&&(*str<='z'))
		{
			*str = ((*str) - 32);
		}
		str++;
	}
}