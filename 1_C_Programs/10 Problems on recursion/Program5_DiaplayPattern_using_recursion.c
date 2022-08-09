/*
Problem Statement: Write a recursive program which display below pattern.
Input : 6
Output : a b c d e f
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
	static char ch = 'a';
	if(num>0)
	{
		printf("%c ",ch);
		ch = ch+1;
		num = num-1;
		DisplayPattern(num);
	}
}