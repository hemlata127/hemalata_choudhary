/*
Write a recursive program which display below pattern.
Input : 5
Output : * * * * * 
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
		printf("* ");
		num--;
		DisplayPattern(num);
	}
}