/*
Problem Statement: Write a program that accepts a number from the user and displays the difference between the sum of even digits and sum of odd digits
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindSum(int);

//entry point function
int main(void)
{
	int num = 0;
	int result = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	result = FindSum(num);
	
	printf("Difference between the sum of even digits and sum of odd digits in %d is: %d\n",num, result);
	
	exit(0);
}

//function definition
int FindSum(int num)
{
	int sum_of_even_digits = 0;
	int sum_of_odd_digits = 0;
	int digit = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	while(num>0)
	{
		digit = num%10;
		if(digit%2 == 0)
		{
			sum_of_even_digits = sum_of_even_digits + digit;
		}
		else
		{
			sum_of_odd_digits = sum_of_odd_digits + digit;
		}
		num = num/10;
	}
	
	return (sum_of_even_digits - sum_of_odd_digits);
}
