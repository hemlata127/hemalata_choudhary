/*
Problem Statement: Write a recursive program which accept string from user and count number of characters.
Input : Hello
Output : 5"
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindStringLength(char *);

//entry point function
int main(void)
{
	char str[50] = "\0";
	int len = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	len = FindStringLength(str);
	printf("String length = %d\n",len);
	
	exit(0);
}

//function definition
int FindStringLength(char *str)
{
	int static count = 0;
	if(*str != '\0')
	{
		count++;
		str++;
		FindStringLength(str);
	}
	
	return count;
}