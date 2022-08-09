/*
Problem Statement: Accept a number from the user. Accept a bit position and turn ON that bit. Display the number after turning ON the specified bit
Enter number: 16151745                   (111101100111010011000001)
Enter bit position (between 1 and 32): 5
Number after turning ON bit 5 = 16151761 (111101100111010011010001)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
unsigned int TurnONBit(unsigned int,int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int pos = 0;
	unsigned int result = 0;
	
	printf("Enter number: ");
	scanf("%u",&num);
	printf("Enter bit position to turn ON (between 1 and 32): ");
	scanf("%d",&pos);
	
	if((pos<1)||(pos>32))
	{
		printf("Invalid bit position, should be between 1 and 32\n");
		exit(-1);
	}
	
	result = TurnONBit(num,pos);
	printf("Number after turning ON bit %d = %u\n",pos,result);
	
	exit(0);
}

//function definition
unsigned int TurnONBit(unsigned int num, int pos)
{
	unsigned int mask = 0x00000001;
	
	//required mask
	mask = mask<<(pos-1);
	
	num = num|mask;
	
	return num;
}