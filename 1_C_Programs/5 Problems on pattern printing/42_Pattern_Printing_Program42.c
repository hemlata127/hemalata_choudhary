/*
Problem Statement: Write a program which accept string from user and print below pattern.
Input : "Adventurous"
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
a d v e n t u r o u s
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function declaration
void DisplayPattern(char*);

int main(void)
{
	char str[] = "Adventurous";
	
	DisplayPattern(str);
	
	exit(0);
}

//function definition
void DisplayPattern(char *arr)
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
			printf("%c ",tolower(arr[j]));
		}
		printf("\n");
	}
}