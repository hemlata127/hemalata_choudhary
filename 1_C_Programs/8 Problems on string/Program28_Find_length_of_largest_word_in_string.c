/*
Problem Statement: Accept a string from the user and display the length of the largest word in the string
Enter string: " unix   operating     system "
Largest word length = 9
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindLargestWordLength(char*);


//entry point function
int main(void)
{
	char str[80] = "\0";
	int result = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	result = FindLargestWordLength(str);
	printf("Largest word length = %d\n",result);
	
	exit(0);
}

//function definition
int FindLargestWordLength(char* str)
{
	int i = 0;
	int len = 0;
	int word_length = 0;
	int max = 0;
	
	//find the length of the string
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	
	//reset i
	i = 0;
	
	//traverse through the string
	while(i<len)
	{
		//if the next character is non zero - beginning of word
		if((str[i] != ' ')&&(i<len))
		{
			//reset the word length
			word_length = 0;
			//find the length of the word - traverse till you encounter next space
			while((str[i] != ' ')&&(i<len))
			{
				word_length++;
				i++;
			}
			//check if this word length is greater than max
			if(word_length>max)
			{
				max = word_length;
			}
		}
		//check if the next character is space
		else if((str[i] == ' ')&&(i<len))
		{
			//skip all subsequent spaces
			while((str[i] == ' ')&&(i<len))
			{
				i++;
			}
		}		
	}
	
	return max;	
}