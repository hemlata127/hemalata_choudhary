/*
Problem Statement: Write a program that accepts a number from user and finds the difference between its even factorial and odd factorial
Input : 5
Output : -7 (8 - 15)
Input : -5
Output : -7 (8 - 15)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindEvenFactorailOddFactorialDifference(int);

//entry point function
int main(void)
{
	int num = 0;
	int result = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	result = FindEvenFactorailOddFactorialDifference(num);
	
	printf("Answer = %d\n",result);
	
	exit(0);
}

//function definition
int FindEvenFactorailOddFactorialDifference(int num)
{
	int even_factorial = 1;
	int odd_factorial = 1;
	int i = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	for(i=1;i<=num;i++)
	{
		if(i%2==0)
		{
			even_factorial = even_factorial * i;
		}
		else
		{
			odd_factorial = odd_factorial * i;
		}
	}
	return (even_factorial - odd_factorial);
}