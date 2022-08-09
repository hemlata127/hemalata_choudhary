/*
Problem Statement: Write a recursive program which display below pattern.
Input : 5
Output : 1 2 3 4 5 
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
	if(num>0)
	{
		int temp = num;
		num = num-1;
		DisplayPattern(num);
		printf("%d ",temp);
	}
}