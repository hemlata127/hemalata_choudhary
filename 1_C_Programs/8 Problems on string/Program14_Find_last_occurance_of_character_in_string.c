/*
Problem Statement: Accept a string from the user, accept another character. Display the index of last occurance of this character in the string
Enter string: Unix Operating System
Enter character to search: t
t occurs last at 18 index
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
BOOL FindLastOccurance(char*,char,int*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	char ch = '\0';
	int last_index = 0;
	BOOL result = FALSE;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	getchar();
	printf("Enter character to search: ");
	scanf("%c",&ch);
	
	result = FindLastOccurance(str,ch,&last_index);
	if(result == FALSE)
	{
		printf("%c is not present\n",ch);
	}
	else if(result == TRUE)
	{
		printf("%c occurs last at %d index\n",ch,last_index);
	}
	
	exit(0);
}

//function definition
BOOL FindLastOccurance(char* str,char ch,int* index)
{
	int i = 0;
	int count = 0;
	BOOL ans = FALSE;
	
	//find the string length
	while(str[i] != '\0')
	{
		count++;
		i++;
	}
	
	for(i=count-1;i>=0;i--)
	{
		if(str[i] == ch)
		{
			*index = i;
			ans = TRUE;
			break;
		}
	}
		
	return ans;
}