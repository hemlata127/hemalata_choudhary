/*
Problem Statement: Accept a number from the user and count the OFF bits in that number
Enter a number: 4042683594 (11110000111101100111010011001010)
Number of OFF bits in 4042683594 = 14
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountOFFBits(unsigned int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int count = 0;
	
	printf("Enter a number: ");
	scanf("%u",&num);
	
	count = CountOFFBits(num);
	printf("Number of OFF bits in %u = %d\n",num,count);
	
	exit(0);
}

//function definition
int CountOFFBits(unsigned int num)
{
	int i = 0;
	int count = 0;
	unsigned int mask = 0x00000001;
	unsigned int temp_mask = 0x00000000;
	
	for(i=1;i<=32;i++)
	{
		temp_mask = mask<<(i-1);
		if((temp_mask&num)!=temp_mask)
		{
			count++;
		}
	}
	return count;
}