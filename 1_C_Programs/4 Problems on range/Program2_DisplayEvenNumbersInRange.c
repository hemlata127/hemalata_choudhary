/*
Problem Statement: Accept a range from the user and display all the even numbers in that range
Input : 23 35 
Output : 24 26 28 30 32 34 
Input : -10 2
Output : -10 -8 -6 -4 -2 0 2 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayEvenNumbersInRange(int,int);

//entry point function
int main(void)
{
	int start_range = 0;
	int end_range = 0;
	
	printf("Enter start range: ");
	scanf("%d",&start_range);
	printf("Enter end range: ");
	scanf("%d",&end_range);
	
	DisplayEvenNumbersInRange(start_range,end_range);
	
	exit(0);
}

//function definition
void DisplayEvenNumbersInRange(int start_range, int end_range)
{
	if(start_range>end_range)
	{
		printf("Invalid range\n");
		return;
	}
	
	int i = 0;
	for(i=start_range;i<=end_range;i++)
	{
		if(i%2 == 0)
		{
			printf("%d ",i);
		}
	}
	
	printf("\n");
}