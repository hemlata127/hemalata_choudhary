/*
Problem Statement: Write a recursive program which accept number from user and return largest digit
Input : 87983
Output: 9
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int FindSmallestDigit(int);

//entry point function
int main(void)
{
	int num = 0;
	int min = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	if(num<0)
	{
		min = FindSmallestDigit(-num);
	}
	else
	{
		min = FindSmallestDigit(num);
	}
	
	printf("Smallest digit = %d\n",min);
	
	exit(0);
}

//function definition
int FindSmallestDigit(int num)
{
	int static min = 9;
	if(num>0)
	{
		if(num%10<min)
		{
			min = num%10;
		}
		num = num/10;
		FindSmallestDigit(num);
	}
	
	return min;
}