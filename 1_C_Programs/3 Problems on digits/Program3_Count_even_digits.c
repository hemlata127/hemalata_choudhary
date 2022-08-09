/*
Problem Statement: Accept a number from the user and count the number of even digits in it
Input: 12346
Output: Number of even digits in 12346 = 3
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountEvenDigits(int);

//entry point function
int main(void)
{
	int num = 0;
	int count = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	count = CountEvenDigits(num);
	
	printf("Number of even digits in %d = %d\n",num,count);
	
	exit(0);
}

//function definition
int CountEvenDigits(int num)
{
	int count = 0;
	int digit = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	while(num>0)
	{
		digit = num%10;
		if(digit%2 == 0)
		{
			count++;
		}
		num = num/10;
	}
	
	return count;
}
