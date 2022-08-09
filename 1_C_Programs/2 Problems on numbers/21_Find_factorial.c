/*
Problem Statement: Write a program to accept a number from user and find factorial of that number
Input : 5
Output : 120 (5 * 4 * 3 * 2 * 1) 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function definition
int FindFactorial(int);

//entry point function
int main(void)
{
	int num = 0;
	int ans = 0;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	ans = FindFactorial(num);
	
	printf("Factorial = %d\n",ans);
	
	exit(0);
}

//function definition
int FindFactorial(int num)
{
	int fact = 1;
	int i = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	for(i=2;i<=num;i++)
	{
		fact = fact * i;
	}
	return fact;
}