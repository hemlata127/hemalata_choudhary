/*
Problem Statement: Accept a string from user and check if it contains a vowel
Enter string: Utkarsh
TRUE
Enter string: KPDS
FALSE
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define TRUE 1
#define FALSE 0

//typedef
typedef int BOOL;

//function declaration
BOOL CheckVowel(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	BOOL result = FALSE;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	result = CheckVowel(str);
	if(result == TRUE)
	{
		printf("TRUE\n");
	}
	else if(result == FALSE)
	{
		printf("FALSE\n");
	}
	
	exit(0);
}

BOOL CheckVowel(char *str)
{
	BOOL result = FALSE;
	
	while(*str != '\0')
	{
		if((*str == 'a')||(*str == 'e')||(*str == 'i')||(*str == 'o')||(*str == 'u')||(*str == 'A')||(*str == 'E')||(*str == 'I')||(*str == 'O')||(*str == 'U'))
		{
			result = TRUE;
		}
		str++;
	}
	return result;
}