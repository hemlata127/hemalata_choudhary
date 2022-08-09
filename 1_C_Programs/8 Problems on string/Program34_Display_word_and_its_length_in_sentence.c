/*
Problem Statement: Accept a sentence from the user and display each word along with its length
Enter sentence: a good cook can cook good food
a = 1
good = 4
cook = 4
can = 3
cook = 4
good = 4
food = 4

Enter sentence: unix opearting system
unix = 4
opearting = 9
system = 6
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayWordsAndLength(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter sentence: ");
	scanf("%[^\n]s",str);
	
	DisplayWordsAndLength(str);
	
	exit(0);
}

//function definition
void DisplayWordsAndLength(char* str)
{
	int i = 0;
	int len = 0;
	int word_count = 0;
	
	//find length of string
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	
	//reset i
	i = 0;
	
	//traverse the sentence
	while(i<len)
	{
		word_count = 0;
		if((str[i] != ' ')&&(i<len))
		{
			while((str[i] != ' ')&&(i<len))
			{
				printf("%c",str[i]);
				i++;
				word_count++;
			}
			printf(" = %d\n",word_count);
		}
		else if((str[i] == ' ')&&(i<len))
		{
			while((str[i] == ' ')&&(i<len))
			{
				i++;
			}
		}			
	}
}
