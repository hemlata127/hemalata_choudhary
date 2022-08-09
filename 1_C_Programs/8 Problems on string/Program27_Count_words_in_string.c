/*
Problem Statement: Accept a string from the user and count number of words in the string
Enter string:"     Unix  Operating     system ""
Number of word = 3
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountWord(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	int word_count = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	word_count = CountWord(str);
	printf("Number of word = %d\n",word_count);
	
	exit(0);
}

//function definition
int CountWord(char* str)
{
	int word_count = 0;
	int i = 0;
	int len = 0;
	
	//find the length of the string
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	//reset i
	i = 0;
	
	//traverse the entire string
	while(i<len)
	{
		//check if next character is non space - in that case skip all characters
		if((str[i] != ' ')&&(i<len))
		{
			//increment the word count
			word_count++;
			//skip remaining spaces
			while((str[i] != ' ')&&(i<len))
			{
				i++;
			}
		}
		//check if next character is space - in that case skip all spaces
		else if((str[i] == ' ')&&(i<len))
		{
			while((str[i] == ' ')&&(i<len))
			{
				i++;
			}
		}
	}
	
	return word_count;
}