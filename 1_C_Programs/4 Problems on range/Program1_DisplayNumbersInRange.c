/*
Problem Statement: Accept a range from user and display all numbers in that range including the range
Write a program which accept range from user and display all numbers in between
that range.
Input : 23 35
Output : 23 24 25 26 27 28 29 30 31 32 33 34 35 
Input : -10 2
Output : -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayNumbersInRange(int,int);

//entry point function - program execution begins here
int main(void)
{
	int start_range = 0;
	int end_range = 0;
	
	printf("Enter start range: ");
	scanf("%d",&start_range);
	
	printf("Enter end range: ");
	scanf("%d",&end_range);
	
	DisplayNumbersInRange(start_range,end_range);
	
	exit(0);
}

//function definition
void DisplayNumbersInRange(int start_range,int end_range)
{
	if(start_range>end_range)
	{
		printf("Invalid range\n");
		return;
	}
	
	int i = 0;
	
	for(i=start_range;i<=end_range;i++)
	{
		printf("%d ",i);
	}
	
	printf("\n");
}