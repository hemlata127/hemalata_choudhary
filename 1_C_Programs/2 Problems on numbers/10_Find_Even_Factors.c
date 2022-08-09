/*
Problem Statement: Write a C program to accept a number from user and display its even factors
*/
//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void FindEvenFactors(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	FindEvenFactors(num);
	
	exit(0);
}

//function definition
void FindEvenFactors(int num)
{
	if(num<0)
	{
		num = -num;
	}
	
	int i = 0;
	for(i = 2;i<=num/2;i++)
	{
		if(num%i == 0)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}