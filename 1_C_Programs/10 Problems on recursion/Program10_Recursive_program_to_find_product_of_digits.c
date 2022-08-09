/*
Write a recursive program which accept number from user and return its product of digits.
Input : 523
Output : 30
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
	int result = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	if(num<0)
	{
		result = MultiplyDigits(-num);
	}
	else
	{
		result = MultiplyDigits(num);
	}

	printf("Product of digits in %d  = %d\n",num,result);
	
	exit(0);
}

//function definition
int MultiplyDigits(int num)
{
	int static ans = 1;
	if(num>1)
	{
		ans = ans * num%10;
		num = num/10;
		MultiplyDigits(num);
	}
	
	return ans;
}