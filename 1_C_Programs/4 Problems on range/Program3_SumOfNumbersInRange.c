/*
Problem Statement: Write a program that accepts range from user and displays the sum of all numbers in that range, including the range.
Consider only positive range.
Input : 23 30
Output : 212
Input : -10 2
Output : Invalid range 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindSumOfNumbersInRange(int,int);

//entry point function
int main(void)
{
	int start_range = 0;
	int end_range = 0;
	int result = 0;
	
	printf("Enter start range: ");
	scanf("%d",&start_range);
	
	printf("Enter end range: ");
	scanf("%d",&end_range);
	
	if((start_range<0)||(end_range<0)||(start_range>end_range))
	{
		printf("Invalid range\n");
		exit(-1);
	}
	
	result = FindSumOfNumbersInRange(start_range,end_range);
	
	printf("Sum of numbers between %d and %d = %d\n",start_range,end_range,result);
	
	exit(0);
}

//function definition
int FindSumOfNumbersInRange(int start_range, int end_range)
{	
	int i = 0;
	int sum = 0;
	
	for(i=start_range;i<=end_range;i++)
	{
		sum = sum+i;
	}
	
	return sum;
}