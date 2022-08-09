/*
Problem Statement: Write a program to accept a number from the user and display its multiplication table
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayTable(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	DisplayTable(num);	
	
	exit(0);
}

//function definition
void DisplayTable(int num)
{
	int i = 0;
	
	for(i=1;i<=10;i++)
	{
		printf("%d * %d = %d\n",num,i,num*i);
	}
}