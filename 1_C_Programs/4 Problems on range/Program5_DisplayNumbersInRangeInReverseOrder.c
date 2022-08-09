/*
Problem Statement: Write a C program that accepts a range from the user and displays numbers in that range in reverse order
Input : 23 35
Output : 35 34 33 32 31 30 29 28 27 26 25 24 23 
Input : -10 2
Output : 2 1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 -10
Input : 90 18
Output : Invalid range
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayNumbersInRangeInReverseOrder(int,int);

//entry point function
int main(void)
{
	int start_range = 0;
	int end_range = 0;
	
	printf("Enter start range: ");
	scanf("%d",&start_range);
	printf("Enter end range: ");
	scanf("%d",&end_range);
	
	DisplayNumbersInRangeInReverseOrder(start_range,end_range);
	
	exit(0);
}

//function definition
void DisplayNumbersInRangeInReverseOrder(int start_range,int end_range)
{
	if(start_range>end_range)
	{
		printf("Invalid range\n");
		return;
	}
	
	int i = 0;
	
	for(i=end_range;i>=start_range;i--)
	{
		printf("%d ",i);
	}
	
	printf("\n");
}