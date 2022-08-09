/*
Problem Statement: Accept a number from user and check if it is even or odd
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define TRUE 1
#define FALSE 0

//type def
typedef int BOOL;

//function declaration
BOOL CheckEven(int);

//entry point function
int main(void)
{
	int num = 0;
	BOOL result = FALSE;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	result = CheckEven(num);
	if(result == TRUE)
	{
		printf("%d is even\n",num);
	}
	else
	{
		printf("%d is odd\n",num);
	}
	
	exit(0);
}

//function definition
BOOL CheckEven(int num)
{
	if(num%2 == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}