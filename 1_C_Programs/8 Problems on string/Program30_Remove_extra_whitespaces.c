/*
Problem Statement: Accept a string from the user and copy it to another string. Remove any extra whitespaces from it while copying.
Enter string: "Unix   operating      system"
Sources string = Unix   operating      system
Destination string = Unix operating system
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void CopyStringRemoveExtraWhitespaces(char*,char*);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	
	CopyStringRemoveExtraWhitespaces(src,dest);
	printf("Sources string = %s\n",src);
	printf("Destination string = %s\n",dest);
	
	exit(0);
}

//function definition
void CopyStringRemoveExtraWhitespaces(char* src, char* dest)
{
	int i = 0;
	
	//traverse the whole string
	while(src[i] != '\0')
	{
		//check if the next character is non space
		if((src[i] != ' ')&&(src[i] != '\0'))
		{
			//copy all characters till space is encountered
			while((src[i] != ' ')&&(src[i] != '\0'))
			{
				*dest = *src;
				dest++;
				src++;
			}
		}
		else if((src[i] == ' ')&&(src[i] != '\0'))
		{
			//add one white space - end of the word
			*dest = ' ';
			dest++;
			//skip all white spaces
			while((src[i] == ' ')&&(src[i] != '\0'))
			{
				src++;
			}
		}
	}
	
	
	
}