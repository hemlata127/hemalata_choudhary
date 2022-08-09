/*
Problem Statement: Write a program which accept string from user and print below pattern.
Input : "Adventurous"
Output :
A
d d
v v v
e e e e
n n n n n
t t t t t t
u u u u u u u
r r r r r r r r
o o o o o o o o o
u u u u u u u u u u
s s s s s s s s s s s
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function type declaration
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
	
	for(i=0;i<=count;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%c ",arr[i]);
		}
		printf("\n");
	}	
}