/*
Problem Statement: Accept a string from the user and copy it to another string. Before copy toggle case of each character. Display both the strings
Enter string: Unix Operating System
Source string = Unix Operating System
Destination string = uNIX oPERATING sYSTEM
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringCopyToggleCase(char*,char*);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	
	StringCopyToggleCase(dest,src);
	
	printf("Source string = %s\n",src);
	printf("Destination string = %s\n",dest);
	
	exit(0);
}

//function definition
void StringCopyToggleCase(char* dest,char* src)
{
	while(*src != '\0')
	{
		if((*src>='A')&&(*src<='Z'))
		{
			*dest = *src+32;
		}
		else if((*src>='a')&&(*src<='z'))
		{
			*dest = *src-32;
		}
		else
		{
			*dest = *src;
		}
		
		dest++;
		src++;
	}
}