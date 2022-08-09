/*
Problem Statement: Accept a string from the user and copy only the capital letters into another string. Display both the string.
Enter string: Unix Operating System
Source string = Unix Operating System
Destination string = UOS
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringCopyCapitalLetters(char*,char*);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	
	StringCopyCapitalLetters(dest,src);
	
	printf("Source string = %s\n",src);
	printf("Destination string = %s\n",dest);
	
	exit(0);
}

//function definition
void StringCopyCapitalLetters(char* dest, char* src)
{
	while(*src != '\0')
	{
		if((*src>='A')&&(*src<='Z'))
		{
			*dest = *src;
			dest++;
		}
		src++;
	}
}