/*
Problem Statement: Write a program to find the largest of the three given numbers
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindLargest(int,int,int);

//entry point function
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int result = 0;
	
	printf("Enter number1: ");
	scanf("%d",&num1);
	printf("Enter number2: ");
	scanf("%d",&num2);
	printf("Enter number3: ");
	scanf("%d",&num3);
	
	result = FindLargest(num1,num2,num3);
	
	printf("%d is largest\n",result);
	
	exit(0);
}

//function definition
int FindLargest(int num1, int num2, int num3)
{
	int largest = 0;
	
	if((num1>num2)&&(num1>num3))
	{
		largest = num1;
	}
	else if((num2>num1)&&(num2>num3))
	{
		largest = num2;
	}
	else
	{
		largest = num3;
	}
	
	return largest;
}