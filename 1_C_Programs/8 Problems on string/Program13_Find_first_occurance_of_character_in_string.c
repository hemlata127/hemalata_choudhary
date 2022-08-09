/*
Problem Statement: Accept a string from the user, accept a character. Display the index of first occurance of this character in the string
Enter string: Unix Operating System
Enter character to search: e
e occurs first at 7 index
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindFirstOccurance(char*,char);

//entry point function
int main(void)
{
	char str[80] = "\0";
	char ch = '\0';
	int first_index = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	getchar();
	printf("Enter character to search: ");
	scanf("%c",&ch);
	
	first_index = FindFirstOccurance(str,ch);
	if(first_index == -1)
	{
		printf("%c does not occur\n",ch);
	}
	else
	{
		printf("%c occurs first at %d index\n",ch,first_index);
	}
	
	exit(0);
}

//function definition
int FindFirstOccurance(char* str,char ch)
{
	int i = 0;
	int index = 0;
	
	while(str[i] != '\0')
	{
		if(str[i] == ch)
		{
			index = i;
			break;
		}
		i++;
	}
	if(str[i] == '\0')
	{
		index = -1;
	}
	return index;
}