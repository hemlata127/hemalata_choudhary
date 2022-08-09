/*
Problem Statement: Accept two numbers from the user. Check if first number is divisible by the second number
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//handle boolean data type
#define TRUE 1
#define FALSE 0
typedef int BOOL;

//function type declaration
BOOL CheckDivisibility(int,int);

//entry point function
int main(void)
{
	int num1 = 0, num2 = 0;
	BOOL result = FALSE;
	
	//Accept the inputs
	printf("Enter first number: ");
	scanf("%d",&num1);
	
	printf("Enter second number (non zero): ");
	scanf("%d",&num2);
	
	//call to the function to check divisibility
	result = CheckDivisibility(num1,num2);
	
	//display result based on its value
	if(result == TRUE)
	{
		printf("%d is divisible by %d\n",num1,num2);
	}
	else if(result == FALSE)
	{
		printf("%d is not divisible by %d\n",num1,num2);
	}
	
	exit(0);
}

//function definition
BOOL CheckDivisibility(int num1, int num2)
{
	//check for invalid divisor
	if(num2 == 0)
	{
		printf("Divisor(second number) cannot be zero\n");
		return -1;
	}
	
	//Divisibility logic
	if(num1%num2 == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}