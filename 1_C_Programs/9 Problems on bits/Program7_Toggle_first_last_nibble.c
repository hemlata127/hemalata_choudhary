/*
Problem Statement: Accept a number from the user and toggle its first and last nibble. Display the resulting number
Enter number: 16151749                                     (00000000111101100111010011000101)
16151749 after toggling first and last nibble = 4042683594 (11110000111101100111010011001010)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
unsigned int ToggleFirstLastNibble(unsigned int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	unsigned int result = 0;
	
	printf("Enter number: ");
	scanf("%u",&num);
	
	result = ToggleFirstLastNibble(num);
	
	printf("%u after toggling first and last nibble = %u\n",num,result);
	
	exit(0);
}

unsigned int ToggleFirstLastNibble(unsigned int num)
{
	unsigned int mask = 0xF000000F;
	
	return (num^mask);	
}