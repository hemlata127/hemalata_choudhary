/*
Problem Statement: Accept a number from the user and check if its first and last bits are ON or OFF
Enter number: 2152043086 (10000000010001011001001001001110)
Bit at first position in 2152043086 is OFF
Bit at last position in 2152043086 is ON
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void CheckFirstLastBitsONOFF(unsigned int,int,int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int first_pos = 1;
	int last_pos = 32;
	
	printf("Enter number: ");
	scanf("%u",&num);
	
	CheckFirstLastBitsONOFF(num,first_pos,last_pos);
	
	exit(0);
}

//function definition
void CheckFirstLastBitsONOFF(unsigned int num,int first_pos, int last_pos)
{
	unsigned int mask1 = 0x00000001;
	unsigned int mask2 = mask1<<(last_pos-1);
	
	if((num&mask1) == mask1)
	{
		printf("Bit at first position in %u is ON\n",num);
	}
	else
	{
		printf("Bit at first position in %u is OFF\n",num);
	}
	
	if((num&mask2) == mask2)
	{
		printf("Bit at last position in %u is ON\n",num);
	}
	else
	{
		printf("Bit at last position in %u is OFF\n",num);
	}	
}