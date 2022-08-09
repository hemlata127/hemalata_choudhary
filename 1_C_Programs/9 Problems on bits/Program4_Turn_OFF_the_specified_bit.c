/*
Problem Statement: Accept a number from the user and bit position in that number. Turn OFF that bit and display the resulting number
Enter number: 16151721 (111101100111010010101001)
Enter bit position (between 1 and 32): 11
Number after turning off bit 11 = 16150697 (111101100111000010101001)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
unsigned int TurnOFFBit(unsigned int,int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int pos = 0;
	unsigned int result = 0;
	
	printf("Enter number: ");
	scanf("%u",&num);
	
	printf("Enter bit position to turn OFF (between 1 and 32): ");
	scanf("%d",&pos);
	
	if((pos<1)||(pos>32))
	{
		printf("Invalid bit position, should be between 1 and 32\n");
		exit(-1);
	}
	
	result = TurnOFFBit(num,pos);
	printf("Number after turning off bit %d = %u\n",pos,result);	
	
	exit(0);
}

//function definition
unsigned int TurnOFFBit(unsigned int num, int pos)
{
	unsigned int mask = 0x00000001;
	mask = ~(mask<<(pos-1));
	
	num = num&mask;
	
	return num;
}