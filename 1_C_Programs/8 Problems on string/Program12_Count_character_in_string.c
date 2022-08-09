/*
Problem Statement: Accept a string from the user, accept another character and count that character in the entered string
Enter string: Unix Operating System
Enter character to count:m
m occurs 1 times
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountCharacter(char*,char);

//entry point function
int main(void)
{
	char str[80] = "\0";
	char ch = '\0';
	int count = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	getchar();
	printf("Enter character to count:");
	scanf("%c",&ch);
	
	count = CountCharacter(str,ch);
	printf("%c occurs %d times\n",ch,count);
	
	exit(0);
}

//function definition
int CountCharacter(char* str,char ch)
{
	int count = 0;
	
	while(*str != '\0')
	{
		if(*str == ch)
		{
			count++;
		}
		str++;
	}
	
	return count;
}