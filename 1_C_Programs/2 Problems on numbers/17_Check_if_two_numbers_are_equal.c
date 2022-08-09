/*
Problem Statement: Accept two numbers from the user and check if they are equal
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define TRUE 1
#define FALSE 0

//type def
typedef int BOOL;

//function definition
BOOL CheckEqual(int,int);

//entry point function
int main(void)
{
	int num1 = 0, num2 = 0;
	BOOL result = FALSE;
	
	printf("Enter number: ");
	scanf("%d",&num1);
	
	printf("Enter number: ");
	scanf("%d",&num2);
	
	result = CheckEqual(num1,num2);
	
	if(result == TRUE)
	{
		printf("Numbers are equal\n");
	}
	else
	{
		printf("Numbers are not equal\n");
	}
	
	exit(0);
}

//function definition
BOOL CheckEqual(int num1, int num2)
{
	if(num1 == num2)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}