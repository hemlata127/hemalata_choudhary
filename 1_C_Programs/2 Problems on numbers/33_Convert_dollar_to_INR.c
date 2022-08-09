/*
Problem Statement: Write a program to accept amount in dollor and return its value in indian rupees. COnsider 1$ = 74 rupees
Input : 10
Output : 740
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int ConvertCurrency(int);

//entry point function
int main(void)
{
	int amount_in_dollar = 0;
	int amount_in_rupees = 0;
	
	printf("Enter amount in dollar: ");
	scanf("%d",&amount_in_dollar);
	
	if(amount_in_dollar < 0)
	{
		printf("Invalid input\n");
		exit(-1);
	}
	
	amount_in_rupees = ConvertCurrency(amount_in_dollar);
	
	printf("Amount in rupees = %d\n",amount_in_rupees);
	
	exit(0);
}

//function definition
int ConvertCurrency(int amount_in_dollar)
{
	return (amount_in_dollar * 74);
}