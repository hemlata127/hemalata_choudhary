/*
Accept a string from the user and check if it is a pallindrome or not
Run1:
Enter string: Malayalam
Pallindrome
Run2:
Enter string: Unix
Not a pallindrome
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//macro definition
#define TRUE 1
#define FALSE 0

//typedef
typedef int BOOL;

//function declaration
BOOL CheckPallindrome(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	BOOL result = FALSE;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	result = CheckPallindrome(str);
	if(result == TRUE)
	{
		printf("Pallindrome\n");
	}
	else
	{
		printf("Not a pallindrome\n");
	}	
	
	exit(0);
}

//function definition
BOOL CheckPallindrome(char *str)
{
	int i = 0;
	int j = 0;
	int len = 0;
	BOOL result = TRUE;
	
	//find the length of the string
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	
	//check pallindrome
	for(i=0,j=len-1;i<j;i++,j--)
	{
		if(toupper(str[i]) != toupper(str[j]))
		{
			result = FALSE;
			break;
		}
	}
	
	return result;
}