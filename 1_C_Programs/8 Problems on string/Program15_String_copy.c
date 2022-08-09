/*
Problem Statement: Accept a string from the user and copy it into another string. Display both the strings.
Enter string: Unix Operating System
Source string = Unix Operating System
Destination string = Unix Operating System
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringCopy(char*,char*);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	
	StringCopy(dest,src);
	printf("Source string = %s\n",src);
	printf("Destination string = %s\n",dest);
	
	exit(0);
}

//function Definition
void StringCopy(char* dest,char*src)
{
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}	
}