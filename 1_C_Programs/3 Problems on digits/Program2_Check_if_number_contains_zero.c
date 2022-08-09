/*
Problem Statement: Write a program which accept number from user and check whether it contains 0 in it or not
Input : 2395
Output : There is no Zero
Input : 1018
Output : It Contains Zero 
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
BOOL CheckZero(int);

//entry point function
int main(void)
{
	int num = 0;
	BOOL result = FALSE;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	result = CheckZero(num);
	
	if(result == TRUE)
	{
		printf("%d contains zero\n",num);
	}
	else
	{
		printf("%d does not contain zero\n",num);
	}
	
	exit(0);
}

//function definition
BOOL CheckZero(int num)
{
	BOOL result = FALSE;
	int digit = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	while(num>0)
	{
		digit = num%10;
		if(digit == 0)
		{
			result = TRUE;
			break;
		}
		num = num/10;
	}
	return result;
}