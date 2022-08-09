/*
Problem Statement: Write a program to accept a number from user and display the sum of its non factors
Input : 12
Output : 50
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindSumOfNonFactors(int);

//entry point function
int main(void)
{
	int num = 0;
	int ans = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	ans = FindSumOfNonFactors(num);
	
	printf("Answer is: %d\n",ans);
	
	exit(0);
}

//function definition
int FindSumOfNonFactors(int num)
{
	int sum = 0;
	int i = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	for(i=2;i<num;i++)
	{
		if(num%i != 0)
		{
			sum = sum+i;
		}
	}
	return sum;
}