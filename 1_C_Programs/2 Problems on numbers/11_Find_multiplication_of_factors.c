/*
Problem Statement: Write a program to accept a number from user and display multiplication of its factors
Input : 12
Output : 144 (1 * 2 * 3 * 4 * 6)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int MultiplyFactors(int);

//entry point function
int main(void)
{
	int num = 0;
	int result = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	result = MultiplyFactors(num);
	
	printf("Answer is: %d\n",result);
	
	exit(0);
}

//function definition
int MultiplyFactors(int num)
{
	if(num<0)
	{
		num = -num;
	}
	if(num == 0)
	{
		return 0;
	}
	
	int i = 0;
	int ans = 1;
	
	for(i=2;i<=num/2;i++)
	{
		if(num%i == 0)
		{
			ans = ans * i;
		}
	}
	return ans;
}