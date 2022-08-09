/*
Problem Statement: Write a program which accept number from user and print that number of $ & *
on screen.
Input : 5
Output : $ * $ * $ * $ * $ * 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayPattern(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	DisplayPattern(num);
	
	exit(0);
}

//function definition
void DisplayPattern(int num)
{
	int i = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	for(i=1;i<=num;i++)
	{
		printf("$ * ");
	}
	printf("\n");
}