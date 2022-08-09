/*
Problem Statement: Write a program which accept string from user and print below pattern.
Input : "adventurous"
Output :
a d v e n t u r o u s
a d v e n t u r o u
a d v e n t u r o
a d v e n t u r
a d v e n t u
a d v e n t
a d v e n
a d v e
a d v
a d
a
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayPattern(char*);

//entry point function
int main(void)
{
	char str[] = "adventurous";
	
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
	
	for(i=count;i>=0;i--)
	{
		for(j=0;j<=i-1;j++)
		{
			printf("%c ",arr[j]);
		}
		printf("\n");
	}
}