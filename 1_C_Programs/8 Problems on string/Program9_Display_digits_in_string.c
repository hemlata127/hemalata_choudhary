/*
Problem Statement: Accept a string from the user and display all digits in that string
Enter string: Hello8gh765hh
8765
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayDigits(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	DisplayDigits(str);
	
	exit(0);
}

//function definition
void DisplayDigits(char *str)
{
	while(*str != '\0')
	{
		
		if((*str>='0')&&(*str<='9'))
		{
			printf("%c",*str);
		}
		str++;
	}
		
}