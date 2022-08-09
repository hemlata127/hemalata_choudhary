/*
Problem Statement: Write a program to accept a positive non zero number from user and display number line
Input : 4
Output : -4 -3 -2 -1 0 1 2 3 4 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void PrintNumberLine(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter a positive non zero number: ");
	scanf("%d",&num);
	
	if(num<=0)
	{
		printf("%d is not positive non zero number\n",num);
		exit(-1);
	}
	
	PrintNumberLine(num);
	
	exit(0);
}

//function definition
void PrintNumberLine(int num)
{
	int i = 0;
	
	for(i=-num;i<=num;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
}