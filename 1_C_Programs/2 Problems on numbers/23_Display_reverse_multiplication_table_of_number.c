/*
Problem Statement: Write a program to accept a number from user and display its reverse multiplication table
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayReverseTable(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	DisplayReverseTable(num);
	
	exit(0);
}

//function definition
void DisplayReverseTable(int num)
{
	int i = 0;
	
	for(i=10;i>=1;i--)
	{
		printf("%d ",num*i);
	}
	printf("\n");
}