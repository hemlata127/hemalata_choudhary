/*
Problem Statement: Accept a number from user and display those many number of even numbers starting from 2
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayEvenNumbers(int);

//entry point function
int main(void)
{
	int num;
	
	printf("Enter a positive non zero number: ");
	scanf("%d",&num);
	
	DisplayEvenNumbers(num);
	
	exit(0);
}

//function definition
void DisplayEvenNumbers(int num)
{
	if(num<=0)
	{
		printf("%d is not positive non zero number\n",num);
		return;
	}
	
	int count = num;
	int temp = 2;
	while(count>0)
	{
		printf("%d ",temp);
		temp = temp+2;
		count = count-1;
	}
	printf("\n");
}