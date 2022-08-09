/*
Problem Statement: Write a program that accepts a number from the user and displays its non factors
Input : 12
Output : 5 7 8 9 10 11 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayNonFactors(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	DisplayNonFactors(num);
	
	exit(0);
}

//function definition
void DisplayNonFactors(int num)
{
	if(num<0)
	{
		num = -num;
	}
	int i = 0;
	
	for(i=2;i<num;i++)
	{
		if(num%i != 0)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	
}