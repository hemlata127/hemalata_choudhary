/*
Problem Statement: Accept a string from the user and capitalise first character of each word
Enter string: "unix operating   system"
Resulting string = Unix Operating   System
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void CapitaliseFirstCharacterOfWord(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	CapitaliseFirstCharacterOfWord(str);
	
	printf("Resulting string = %s\n",str);
	
	exit(0);
}

//function definition
void CapitaliseFirstCharacterOfWord(char* str)
{
	//traverse the whole string	
	while(*str != '\0')
	{
		//check if the next character is non space
		if((*str != ' ')&&(*str != '\0'))
		{
			//capitalise
			if((*str>='a')&&(*str<='z'))
			{
				*str = *str-32;
			}
			//skip rest of the characters
			while((*str != ' ')&&(*str != '\0'))
			{
				str++;
			}
		}
		//check if next character is space
		else if((*str == ' ')&&(*str != '\0'))
		{
			while((*str == ' ')&&(*str != '\0'))
			{
				str++;
			}
		}
	}
	
	
}