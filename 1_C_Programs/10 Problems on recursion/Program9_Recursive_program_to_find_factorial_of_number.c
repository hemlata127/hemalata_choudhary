/*
Program Statement: Write a recursive program which accept number from user and return its
factorial.
Input : 5
Output : 120
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindFactorial(int);

//entry point function
int main(void)
{
	int num = 0;
	int result = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	if(num<0)
	{
		result = FindFactorial(-num);
	}
	else
	{
		result = FindFactorial(num);
	}
	
	printf("Factorial of %d = %d\n",num,result);
	
	exit(0);
}

//function definition
int FindFactorial(int num)
{
	int static fact = 1;
	
	if(num>1)
	{
		fact = fact * num;
		num = num-1;
		FindFactorial(num);
	}
	
	return fact;
}
