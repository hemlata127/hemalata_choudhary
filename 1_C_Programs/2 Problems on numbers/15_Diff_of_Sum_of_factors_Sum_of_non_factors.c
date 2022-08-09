/*
Problem Statement: Write a program to accept a number from the user and display the difference of sum of its factors and non factors
Input : 12
Output : -22 (28 - 50) 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//fuction declaration
int DiffOfSumOfFactorsAndNonFactors(int);

//entry point function
int main(void)
{
	int num = 0;
	int ans = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	ans = DiffOfSumOfFactorsAndNonFactors(num);
	
	printf("Answer is: %d\n",ans);
	
	exit(0);
}

//function definition
int DiffOfSumOfFactorsAndNonFactors(int num)
{
	int i = 0;
	int sum_of_factors = 0;
	int sum_of_non_factors = 0;
	
	if(num<0)
	{
		num = -num;
	}
	
	for(i=1;i<=num;i++)
	{
		if(num%i == 0)
		{
			sum_of_factors = sum_of_factors + i;
		}
		else
		{
			sum_of_non_factors = sum_of_non_factors + i;
		}
	}
	return(sum_of_factors - sum_of_non_factors);
}
