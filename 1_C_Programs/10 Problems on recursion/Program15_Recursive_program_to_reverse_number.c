/*
Problem Statement: Write a recursive program which accept number from user and return its reverse number.
Input : 523
Output : 325
*/

//header function
#include<stdio.h>
#include<stdlib.h>

//funcion declaration
int ReverseNumber(int);

//entry point function
int main(void)
{
	int num = 0;
	int reverse_number = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	if(num<0)
	{
		reverse_number = ReverseNumber(-num);
		printf("Reverse number = %d\n",-reverse_number);
	}
	else
	{
		reverse_number = ReverseNumber(num);
		printf("Reverse number = %d\n",reverse_number);
	}
	
	exit(0);
}

//function definition
int ReverseNumber(int num)
{
	int static ans = 0;
	if(num>0)
	{
		ans = ((ans*10) + (num%10));
		num = num/10;
		ReverseNumber(num);
	}
	
	return ans;
}