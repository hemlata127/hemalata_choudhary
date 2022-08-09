/*
Problem Statement: Write a program which accept string from user and print below pattern.
Input : "adventurous"
Output : 
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

//function declaration
void DisplayPattern(char* arr);

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
	
	for(i=1;i<=count;i++)
	{
		for(j=0;j<=count;j++)
		{
			printf("%c ",arr[j]);
		}
		printf("\n");
	}
}