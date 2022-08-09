/*
Write a recursive program which accept string from user and count white spaces.
Input : HE llo WOr lD
Output : 3"
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountWhitespaces(char*);

//entry point function
int main(void)
{
	char str[50] = "\0";
	int whitespace_count = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	whitespace_count = CountWhitespaces(str);
	
	printf("Number of whitespaces in string = %d\n",whitespace_count);
	
	exit(0);
}

//function definition
int CountWhitespaces(char *str)
{
	int static count = 0;
	if(*str != '\0')
	{
		if((*str == ' ')||(*str == '\t'))
		{
			count++;
		}
		str++;
		CountWhitespaces(str);
	}
	
	return count;
}