/*
Problem Statement: Accept a string from the user and copy its reversed string into another string. Display both the strings
Enter string: Unix Operating System
Source string = Unix Operating System
Destination string = metsyS gnitarepO xinU
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringCopyReverse(char*,char*);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	
	StringCopyReverse(dest,src);
	
	printf("Source string = %s\n",src);
	printf("Destination string = %s\n",dest);
	
	exit(0);
}

//function definition
void StringCopyReverse(char* dest,char* src)
{
	int len = 0;
	int i = 0;
	
	while(src[i] != '\0')
	{
		len++;
		i++;
	}
	
	for(i=len-1;i>=0;i--)
	{
		*dest = src[i];
		dest++;
	}
}