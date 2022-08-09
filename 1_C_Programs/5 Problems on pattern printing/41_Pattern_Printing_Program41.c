/*
Problem Statement: Write a program which accept string from user and print below pattern.
Input : "Adventurous"
Output :
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
A D V E N T U R O U S
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function declaration
void DisplayPattern(char*);

//entry point function
int main(void)
{
	char str[] = "Adventurous";
	
	DisplayPattern(str);
	
	exit(0);
}

//function definition
void DisplayPattern(char* arr)
{
	int i = 0;
	int j = 0;
	int count = 0;
	
	while(arr[i] != '\0')
	{
		count++;
		i++;
	}
	
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			printf("%c ",toupper(arr[j]));
		}
		printf("\n");
	}	
}