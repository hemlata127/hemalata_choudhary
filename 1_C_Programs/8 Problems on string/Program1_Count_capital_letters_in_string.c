/*
Problem Statement: Write a program which accept string from user and count number of capital characters.
Enter string: Unix Operating System
Number of capital letters = 3
*/

//include header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountCapitalLetters(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	int count_capital = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	count_capital = CountCapitalLetters(str);
	printf("Number of capital letters = %d\n",count_capital);
	
	exit(0);
}

//function definiton
int CountCapitalLetters(char* str)
{
	int count = 0;
	while(*str != '\0')
	{
		if((*str>='A')&&(*str<='Z'))
		{
			count++;
		}
		str++;
	}
	
	return count;
}