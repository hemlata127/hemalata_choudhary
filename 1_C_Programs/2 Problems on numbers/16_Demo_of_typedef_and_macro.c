/*
Problem Statement: Write a program to accept a number from the user and check if the number is greater than 100 or not
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
//macro definition
#define TRUE 1
#define FALSE 0
//typedef
typedef int BOOL;

//function declaration
BOOL CheckNumber(int);

//entry point function
int main(void)
{
	int num = 0;
	BOOL result = FALSE;

	printf("Enter number: ");
	scanf("%d",&num);
	
	result = CheckNumber(num);
	if(result == TRUE)
	{
		printf("%d is greater than 100\n",num);
	}
	else
	{
		printf("%d is not greater than 100\n",num);
	}
	
	exit(0);
}

//function definition
BOOL CheckNumber(int num)
{
	if(num>100)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}