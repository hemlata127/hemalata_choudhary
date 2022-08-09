/*
Problem Statement: Write a recursive program which accept number from user and return largest digit
Input : 87983
Output: 9
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindLargestDigit(int);

//entry point function
int main(void)
{
	int num = 0;
	int max = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	if(num<0)
	{
		max = FindLargestDigit(-num);
	}
	else
	{
		max = FindLargestDigit(num);
	}
	
	printf("Largest digit = %d\n",max);
	
	exit(0);
}

//function definition
int FindLargestDigit(int num)
{
	int static max = 0;
	if(num>0)
	{
		if((num%10)>max)
		{
			max = num%10;
		}
		num = num/10;
		FindLargestDigit(num);
	}
	
	return max;	
}