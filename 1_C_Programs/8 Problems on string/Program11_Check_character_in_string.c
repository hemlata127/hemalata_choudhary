/*
Problem Statement: Accept a string from the user and accept another character and check if the character is present in the string
Enter string: Hemalata Choudhary
Enter character to search: t
t is present
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define TRUE 1
#define FALSE 0

//typedef
typedef int BOOL;

//function declaration
BOOL CheckCharacter(char*,char);

//entry point function
int main(void)
{
	char str[80] = "\0";
	char ch = '\0';
	BOOL result = FALSE;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	getchar();
	printf("Enter character to search: ");
	scanf("%c",&ch);
	
	result = CheckCharacter(str,ch);
	if(result == TRUE)
	{
		
		printf("%c is present\n",ch);
	}
	else if(result == FALSE)
	{
		printf("%c is not present\n",ch);
	}
	
	exit(0);
}

//function definition
BOOL CheckCharacter(char* str, char ch)
{
	BOOL result = FALSE;
	while(*str != '\0')
	{
		if(*str == ch)
		{
			result = TRUE;
			break;
		}
		str++;
	}
	
	return result;
}