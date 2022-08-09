/*
Problem Statement: Accept a string from the user and copy only the small letters into another string. Display both the strings
Enter string: Unix Operating System
Source string = Unix Operating System
Destination string = nixperatingystem
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringCopySmallLetters(char*,char*);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	
	StringCopySmallLetters(dest,src);
	
	printf("Source string = %s\n",src);
	printf("Destination string = %s\n",dest);
	
	exit(0);
}

//function definition
void StringCopySmallLetters(char* dest,char* src)
{
	while(*src != '\0')
	{
		if((*src>='a')&&(*src<='z'))
		{
			*dest = *src;
			dest++;
		}
		src++;
	}
	
	
}