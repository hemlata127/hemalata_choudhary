/*
Problem Statement: Write a program to accept a positive number from user and print numbers from 1 till that number
Input : 8
Output : 1 2 3 4 5 6 7 8 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void PrintNumbers(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter positive non zero number: ");
	scanf("%d",&num);
	
	PrintNumbers(num);
	
	exit(0);
}

//function definition
void PrintNumbers(int num)
{
	int i = 0;
	
	if(num<=0)
	{
		printf("%d is not positive non zero number\n",num);
		return;
	}
	
	for(i=1;i<=num;i++)
	{
		printf("%d ",i);
	}
	printf("\n");	
}