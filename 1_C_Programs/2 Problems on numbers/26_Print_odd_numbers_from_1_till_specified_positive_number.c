/*
Problem Statement: Write a program to accept a positive non zeror number and display all odd numbers till that number
Input : 18
Output : 1 3 5 7 9 11 13 15 17
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void PrintOddNumbers(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter positive non zeror number: ");
	scanf("%d",&num);
	
	PrintOddNumbers(num);
	
	exit(0);
}

//function definition
void PrintOddNumbers(int num)
{
	if(num<=0)
	{
		printf("%d is not positive non zero number\n",num);
		return;
	}
	
	int i = 0;
	
	for(i=1;i<=num;i++)
	{
		if(i%2 != 0)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}