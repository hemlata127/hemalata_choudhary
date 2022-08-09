/*
Problem Statement: Write a C program that accepts a range from the user and displays the sum of all even numbers in that range
Input : 23 30
Output : 108
Input : 10 18
Output : 70
Input : -10 2
Output : Invalid range 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindSumOfEvenNumbersInRange(int,int);

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
	
	result = FindSumOfEvenNumbersInRange(start_range,end_range);
	
	printf("Sum of even numbers between %d and %d = %d\n",start_range,end_range,result);	
	
	exit(0);
}

//function definition
int FindSumOfEvenNumbersInRange(int start_range,int end_range)
{
	int i = 0;
	int sum = 0;
	
	for(i=start_range;i<=end_range;i++)
	{
		if(i%2 == 0)
		{
			sum = sum+i;
		}
	}
	
	return sum;
}