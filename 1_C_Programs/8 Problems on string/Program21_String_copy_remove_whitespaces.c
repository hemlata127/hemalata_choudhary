/*
Program Statement: Accept a string from the user. Copy it into another string skipping the whitespaces
Enter string: Unix Operating System
Source string = Unix Operating System
Destination string = UnixOperatingSystem
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringCopyRemoveWhitespaces(char*,char*);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	
	StringCopyRemoveWhitespaces(dest,src);
	
	printf("Source string = %s\n",src);
	printf("Destination string = %s\n",dest);
	
	exit(0);
}

//function definition
void StringCopyRemoveWhitespaces(char* dest,char* src)
{
	while(*src != '\0')
	{
		if(*src != ' ')
		{
			*dest = *src;
			dest++;
		}
		src++;
	}
	
}