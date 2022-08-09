/*
Problem Statement: Write a C program that accepts a number from user and displays its factors in decreasing order
Input : 12
Output : 6 4 3 2 1
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayFactors(int);

//entry point function
int main(void)
{
	int num;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	DisplayFactors(num);
	
	exit(0);
}

//function definition
void DisplayFactors(int num)
{
	if(num<0)
	{
		num = -num;
	}
	
	int i = 0;
	
	for(i = num/2;i>0;i--)
	{
		if(num%i == 0)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}