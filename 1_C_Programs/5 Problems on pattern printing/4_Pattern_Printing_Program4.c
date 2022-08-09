/*
Problem Statement: Accept number from user and display below pattern.
Input : 5
Output : 5 # 4 # 3 # 2 # 1 #
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayPattern(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	DisplayPattern(num);
	
	exit(0);
}

//function definition
void DisplayPattern(int num)
{
	if(num<0)
	{
		num = -num;
	}
	
	int i = 0;
	
	for(i=num;i>0;i--)
	{
		printf("%d # ",i);
	}
	printf("\n");
}