/*
Problem Statement: Write a program that accepts a number and displays its first 5 multiples
Input : 4
Output : 4 8 12 16 20
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void FindMultiples(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	FindMultiples(num);
	
	exit(0);
}

//function definition
void FindMultiples(int num)
{
	int i = 0;
	for(i=1;i<=5;i++)
	{
		printf("%d ",num*i);
	}
	printf("\n");
}