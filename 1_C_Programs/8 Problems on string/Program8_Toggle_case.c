/*
Problem Statement: Accept a string from the user and toggle its case
Enter string: Unix Operating System
String after toggling case = uNIX oPERATING sYSTEM
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void ToggleCase(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	ToggleCase(str);
	printf("String after toggling case = %s\n",str);
	
	exit(0);
}

//function definition
void ToggleCase(char* str)
{
	while(*str != '\0')
	{
		if((*str>='A')&(*str<='Z'))
		{
			*str = (*str) + 32;
		}
		else if((*str>='a')&& (*str<='z'))
		{
			*str = (*str) - 32;
		}
		str++;
	}
}