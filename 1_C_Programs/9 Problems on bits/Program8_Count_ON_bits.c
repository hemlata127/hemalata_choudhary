/*
Problem Statement: Accept a number from the user and count the ON bits in that number
Enter number: 4042683594 (11110000111101100111010011001010)
Number of ON bits in 4042683594 = 18
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
int CountONBits(unsigned int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int count = 0;
	
	printf("Enter number: ");
	scanf("%u",&num);
	
	count = CountONBits(num);
	printf("Number of ON bits in %u = %d\n",num,count);
	
	exit(0);
}

//function definition
int CountONBits(unsigned int num)
{
	int i = 0;
	int count = 0;
	unsigned int mask = 0x00000001;
	unsigned int temp_mask = 0x00000001;
	
	for(i=1;i<=32;i++)
	{
		temp_mask = mask<<(i-1);
		if((num & temp_mask) == temp_mask)
		{
			count++;
		}
	}
	
	return count;
}