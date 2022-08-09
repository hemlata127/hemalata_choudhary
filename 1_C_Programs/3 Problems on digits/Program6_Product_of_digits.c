/*
Problem Statement: Write a C program that accepts a number from user and displays product of the digits in the number ignoring 0
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int MultiplyDigits(int);

//entry point function
int main(void)
{
	int num = 0;
	int ans = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	ans = MultiplyDigits(num);
	
	printf("Product of digits = %d\n",ans);
	
	exit(0);
}

//function definition
int MultiplyDigits(int num)
{
	int result = 1;
	int digit = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	while(num>0)
	{
		digit = num%10;
		
		if(digit == 0)
		{
			digit = 1;
		}
		
		result = result * digit;
		num = num/10;
	}
	
	return result;
}
