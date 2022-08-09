/*
Problem Statement: Write a program to find the odd factorial of a given number
Input : 5
Output : 15 (5 * 3 * 1)
Input : -5
Output : 15 (5 * 3 * 1)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindOddFactorial(int);

//entry point function
int main(void)
{
	int num = 0;
	int odd_factorial = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	odd_factorial = FindOddFactorial(num);
	
	printf("Odd factorial of %d = %d\n",num, odd_factorial);
	
	exit(0);
}

//function definition
int FindOddFactorial(int num)
{
	int result = 1;
	int i = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	for(i=1;i<=num;i++)
	{
		if(i%2 != 0)
		{
			result = result * i;
		}
	}
	return result;
}