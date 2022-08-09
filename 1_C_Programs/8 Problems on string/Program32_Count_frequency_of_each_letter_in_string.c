/*
Program32_Count_frequency_of_each_letter_in_string
Problem Statement: Accepta a string from the user and find frequency of each letter in the string
Enter string: a good cook can cook good food
a = 2
g = 2
o = 10
d = 3
c = 3
k = 2
n = 1
f = 1
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayCharacterFrequency(char*);

//main function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	DisplayCharacterFrequency(str);
	
	exit(0);
}

//function definition
void DisplayCharacterFrequency(char* str)
{
	int i = 0;
	int len = 0;
	int count = 0;
	int j = 0;
	
	//find length of string
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	
	//reset i
	i = 0;
	
	//traverse the string
	while(i<len)
	{
		count = 1;
		if((str[i] != ' ')&&(i<len))
		{
			for(j=i+1;j<len;j++)
			{
				if(str[i] == str[j])
				{
					count++;
					str[j] = ' ';
				}
			}
			printf("%c = %d\n",str[i],count);
			i++;
		}
		else
		{
			i++;
		}
	}
}