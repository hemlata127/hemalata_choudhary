/*
Problem Statement: Write a recursive program which accept number from user and return summation of its digits
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int SumDigits(int);

//entry point function
int main(void)
{
	int num = 0;
	int result = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	if(num<0)
	{
		result = SumDigits(-num);
	}
	else
	{
		result = SumDigits(num);
	}
	
	printf("Sum of digits in %d = %d\n",num,result);
	
	exit(0);
}

//function definition
int SumDigits(int num)
{
	int static sum = 0;
	if(num>0)
	{
		sum = sum + num%10;
		num = num/10;
		SumDigits(num);
	}
	
	return sum;
}