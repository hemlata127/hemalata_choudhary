/*
Problem Statement: Accept number from user and display below pattern.
Input : 8
Output : 2 4 6 8 10 12 14 16 
*/

//include the header files that contains type declaration of library functions
#include<stdio.h>
#include<stdlib.h>

//type declaration of function
void DisplayPattern(int);

//entry point function - program execution begins from here
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
	int temp = 2;
	int i = 0;
	for(i=1;i<=num;i++)
	{
		printf("%d ",temp);
		temp = temp + 2;
	}
	printf("\n");
}