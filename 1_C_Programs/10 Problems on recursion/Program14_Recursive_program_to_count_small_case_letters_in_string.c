/*
Problem Statement: Write a recursive program which accept string from user and count number of small characters.
Input : HElloWOrlD
Output : 5
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountSmallCaseLetters(char*);

//entry point function
int main(void)
{
	char str[50] = "\0";
	int count_small_case = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	count_small_case = CountSmallCaseLetters(str);
	printf("Number of small case letters = %d\n",count_small_case);
	
	exit(0);
}

//function definition
int CountSmallCaseLetters(char* str)
{
	int static count = 0;
	if(*str != '\0')
	{
		if((*str>='a')&&(*str<='z'))
		{
			count++;
		}
		str++;
		CountSmallCaseLetters(str);
	}
	
	return count;
}