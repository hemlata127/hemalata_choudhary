/*
Problem Statement: Accept two numbers from user and display first number second number of times
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayNumber(int,int);

//entry point function
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	
	printf("Enter first number: ");
	scanf("%d",&num1);
	
	printf("Enter second number (positive non zero number): ");
	scanf("%d",&num2);
	
	DisplayNumber(num1,num2);
	
	exit(0);
}

//function definition
void DisplayNumber(int num1, int num2)
{
	int i = 0;
	
	if(num2<=0)
	{
		printf("Second number is not a non zero number\n");
	}
	
	for(i=0;i<num2;i++)
	{
		printf("%d ",num1);
	}
	printf("\n");
}