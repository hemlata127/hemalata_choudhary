/*
Problem Statement: Accept three numbers from the user and display its product.
Input : 5 4 7
Output : 140
Input : 5 0 7
Output : 35 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int MultiplyNumbers(int, int, int);

//entry point function
int main(void)
{
	int num1 = 0, num2 = 0, num3 = 0;
	int ans = 0;
	
	printf("Enter number1: ");
	scanf("%d",&num1);
	printf("Enter number2: ");
	scanf("%d",&num2);
	printf("Enter number3: ");
	scanf("%d",&num3);
	
	ans = MultiplyNumbers(num1,num2,num3);
	
	printf("Answer is: %d\n",ans);
	
	exit(0);
}

//function definition
int MultiplyNumbers(int num1, int num2, int num3)
{
	if((num1 == 0)&&(num2 == 0)&&(num3 == 0))
	{
		return 0;
	}
	if(num1 == 0)
	{
		num1 = 1;
	}
	if(num2 == 0)
	{
		num2 = 1;
	}
	if(num3 == 0)
	{
		num3 = 1;
	}
	
	return (num1*num2*num3);
}