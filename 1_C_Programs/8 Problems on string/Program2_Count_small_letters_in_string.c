/*
Problem Statement: Write a program which accept string from user and count number of small characters.
Enter string: Unix Operating System
Number of small letters = 16
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountSmallLetters(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	int count_small_letters = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	count_small_letters = CountSmallLetters(str);
	printf("Number of small letters = %d\n",count_small_letters);
	
	exit(0);
}

//function definition
int CountSmallLetters(char* str)
{
	int count = 0;
	
	while(*str != '\0')
	{
		if((*str>='a')&&(*str<='z'))
		{
			count++;
		}
		str++;
	}
	
	return count;
}