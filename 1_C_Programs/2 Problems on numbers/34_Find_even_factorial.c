/*
Problem Statement: Write a program to find the even factorial of a given number
Input : 5
Output : 8 (4 * 2)
Input : -5
Output : 8 (4 * 2)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindEvenFactorial(int);

//entry point function
int main(void)
{
	int num = 0;
	int even_factorial = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	even_factorial = FindEvenFactorial(num);
	
	printf("Even factorial of %d = %d\n",num,even_factorial);
	
	exit(0);
}

//function definition
int FindEvenFactorial(int num)
{
	if(num<0)
	{
		num = -num;
	}
	
	int i = 0;
	int result = 1;
	
	for(i=1;i<=num;i++)
	{
		if(i%2 == 0)
		{
			result = result * i;
		}
	}
	
	return result;
}