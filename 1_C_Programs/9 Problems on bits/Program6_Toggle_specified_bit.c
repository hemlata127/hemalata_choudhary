/*
Problem Statement: Accept a number from the user and a bit position. Toggle the bit at the specified position and display the resulting number
Enter a number: 16151745 (111101100111010011000001)
Enter bit position to toggle (between 1 ans 32): 3
Number after toggling bit 3 = 16151749 (111101100111010011000101)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
unsigned int ToggleBit(unsigned int, int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int pos = 0;
	unsigned int result = 0;
	
	printf("Enter a number: ");
	scanf("%u",&num);
	
	printf("Enter bit position to toggle (between 1 ans 32): ");
	scanf("%d",&pos);
	
	if((pos<1)||(pos>32))
	{
		printf("Invalid bit position, should be between 1 and 32\n");
		exit(-1);
	}
	
	result = ToggleBit(num,pos);
	printf("Number after toggling bit %d = %u\n",pos,result);
	
	exit(0);
}

unsigned int ToggleBit(unsigned int num,int pos)
{
	unsigned int mask = 0x00000001;
	
	//required mask
	mask = mask<<(pos-1);
	
	num = num^mask;
	
	return num;
}