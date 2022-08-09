/*
Problem Statement: Accept a string from the user and reverse it.
Enter string: Unix OS
Reversed string = SO xinU
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void ReverseString(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	ReverseString(str);
	
	printf("Reversed string = %s\n",str);
	
	exit(0);
}

//function definition
void ReverseString(char* str)
{
	int i = 0;
	int j = 0;
	int count = 0;
	char temp = '\0';
	
	//find length of the string
	while(str[i] != '\0')
	{
		count++;
		i++;
	}
	
	//reverse the string
	for(i=0,j=count-1;i<j;i++,j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}