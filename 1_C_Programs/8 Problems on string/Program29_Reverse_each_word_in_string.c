/*
Problem Statement: Accept a string from the suer and reverse each word in the string
Enter string: Unix Operating System
xinU gnitarepO metsyS
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void ReverseEachWord(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	ReverseEachWord(str);
	
	printf("%s\n",str);
	
	exit(0);
}

//function definition
void ReverseEachWord(char* str)
{
	int i = 0;
	int len = 0;
	int start = 0;
	int end = 0;
	int j = 0;
	int k = 0;
	char temp = '\0';
	
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
		//check if the next character is a non space character - beginning of word
		start = 0;
		end = 0;
		if((str[i] != ' ')&&(i<len))
		{
			start = i;
			//traverse till space is wncountered
			while((str[i] != ' ')&&(i<len))
			{
				i++;
			}
			end = i;
			
			//logic to reverse the word - start intex = start, end index = end
			for(j=start,k=end-1;j<k;j++,k--)
			{
				temp = str[j];
				str[j] = str[k];
				str[k] = temp;
			}			
		}
		//if next character is space - skip all subsequent spaces
		else if((str[i] == ' ')&&(i<len))
		{
			while((str[i] ==  ' ')&&(i<len))
			{
				i++;
			}
		}
	}
}