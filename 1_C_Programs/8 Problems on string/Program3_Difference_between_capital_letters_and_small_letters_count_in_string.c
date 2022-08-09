/*
Problem Statement: Write a program which accept string from user and count number of small characters.
Enter string: Unix Operating System
Number of small letters = 16
Number of capital letters = 3
Difference between small and capital letters count = 13
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
void CountCharacters(char*,int*,int*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	int count_small = 0;
	int count_capital = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	CountCharacters(str,&count_small,&count_capital);
	printf("Number of small letters = %d\n",count_small);
	printf("Number of capital letters = %d\n",count_capital);
	printf("Difference between small and capital letters count = %d\n",count_small-count_capital);
	
	exit(0);
}

//function definition
void CountCharacters(char* str,int* count_small, int* count_capital)
{
	while(*str != '\0')
	{
		if((*str>='a')&&(*str<='z'))
		{
			(*count_small)++;
		}
		else if((*str>='A')&&(*str<='Z'))
		{
			(*count_capital)++;
		}
		str++;
	}
}
