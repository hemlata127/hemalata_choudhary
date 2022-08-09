/*
Problem Statement: Accept a number from the user and reverse its digits
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int ReverseDigits(int);

//entry point function
int main(void)
{
	int num = 0;
	int result = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	result = ReverseDigits(num);
	
	printf("Reverse of %d is: %d\n",num,result);
	
	exit(0);
}

//function definition
int ReverseDigits(int num)
{
	int reverse = 0;
	int digit = 0;
	
	if(num<0)
	{
		num = -num;
		while(num > 0)
		{
			digit = num%10;
			reverse = (reverse*10) + digit;
			num = num/10;
		}
		return -reverse;
	}
	else
	{
		while(num > 0)
		{
			digit = num%10;
			reverse = (reverse*10) + digit;
			num = num/10;
		}
		return reverse;
	}	
}