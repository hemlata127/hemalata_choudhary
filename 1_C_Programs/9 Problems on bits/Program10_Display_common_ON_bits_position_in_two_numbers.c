/*
Problem Statement: Accept two numbers from the user. Display positions which have ON bits in both the numbers
Enter first number: 4042683594  (11110000111101100111010011001010)
Enter second number: 4042683000 (11110000111101100111001001111000)
Bits at following position are ON in both 4042683594 and 4042683000:
4 7 13 14 15 18 19 21 22 23 24 29 30 31 32
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayONBitsPositions(unsigned int, unsigned int);

//entry point function
int main(void)
{
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	
	printf("Enter first number: ");
	scanf("%u",&num1);
	printf("Enter second number: ");
	scanf("%u",&num2);
	
	DisplayONBitsPositions(num1,num2);
	
	exit(0);
}

//function definition
void DisplayONBitsPositions(unsigned int num1, unsigned int num2)
{
	int i = 0;
	unsigned int mask = 0x00000001;
	unsigned int temp_mask = 0x00000000;
	
	printf("Bits at following position are ON in both %u and %u:\n",num1,num2);
	
	for(i=1;i<=32;i++)
	{
		temp_mask = mask<<(i-1);
		if(((temp_mask&num1) == temp_mask)&&((temp_mask&num2) == temp_mask))
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	
}