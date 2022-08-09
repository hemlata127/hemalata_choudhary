/*
Problem Statement: Accept a a string from the user. Accept a word and check if it is present in the string
Run1:
Enter string: unix operating system
Enter search word: unix
TRUE
Run2:
Enter string: unix operating system
Enter search word: system
TRUE
Run3:
Enter string: unix operating system
Enter search word: Unix
FALSE
Run4
Enter sentence: a good cook can cook good food
Enter search word: foodd
Word is not present
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

//function declaration
BOOL CheckWord(char*,char*);

//main function
int main(void)
{
	char sentence[100] = "\0";
	char word[50] = "\0";
	BOOL result = FALSE;
	
	printf("Enter sentence: ");
	scanf("%[^\n]s",sentence);
	getchar();
	printf("Enter search word: ");
	scanf("%s",word);
	
	result = CheckWord(sentence,word);
	if(result  == TRUE)
	{
		printf("Word is present\n");
	}
	else if(result == FALSE)
	{
		printf("Word is not present\n");
	}
	
	exit(0);
}

//function definition
BOOL CheckWord(char* str, char* word)
{
	//sentence length
	int str_len = strlen(str);
	//search word length
	int search_word_len = strlen(word);
	//variable to track length of each word in sentence
	int word_len = 0;
	//index variable for sentence
	int i = 0;
	//index variable for search word
	int j = 0;
	//variable for search result
	BOOL result = FALSE;
	
	//outer while loop to navigate through the sentence
	while(i<str_len)
	{
		//reset the search result, word length, index for search word
		result = TRUE;
		word_len = 0;
		j = 0;
		//beginning of word 
		if((str[i] != ' ')&&(i<str_len))
		{
			//navigate till you get a space
			while((str[i] != ' ')&&(i<str_len))
			{
				if(str[i] != word[j])
				{
					result = FALSE;
				}
				word_len++;
				i++;
				j++;
			}
		}
		//after navigating through the word in the sentence
		if(word_len != search_word_len)
		{
			result = FALSE;
		}
		//return if the word is found
		if(result == TRUE)
		{
			return result;
		}
		//if you see space in sentence
		else if((str[i] == ' ')&&(i<str_len))
		{
			//skip all further spaces
			while((str[i] == ' ')&&(i<str_len))
			{
				i++;
			}
		}		
	}
	
	return result;
}