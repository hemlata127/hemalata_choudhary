/*
Problem Statement: Accept a number from the user and accept two positions. Check if the bits at the specified position are ON or OFF
Enter number: 4559439
Enter position1: 7
Enter position2: 15
Bit at position 7 in 4559439 is ON
Bit at position 15 in 4559439 is OFF
*/

//include the header files
#include<stdio.h>
#include<stdlib.h>

//function declarations
void CheckBitONOFF(unsigned int,int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int pos1 = 0;
	int pos2 = 0;
	
	printf("Enter number: ");
	scanf("%u",&num);
	printf("Enter position1: ");
	scanf("%d",&pos1);
	if((pos1<1)||(pos1>32))
	{
		printf("Invalid bit position, position should be between 1 and 32\n");
		exit(-1);
	}
	printf("Enter position2: ");
	scanf("%d",&pos2);
	if((pos2<1)||(pos2>32))
	{
		printf("Invalid bit position, position should be between 1 and 32\n");
		exit(-1);
	}
	
	CheckBitONOFF(num,pos1);
	CheckBitONOFF(num,pos2);
	
	exit(0);
}

//function definition
void CheckBitONOFF(unsigned int num, int pos)
{
	//initialise a mask
	unsigned int mask = 0x00000001;
	
	//design the required mask
	mask = mask<<(pos-1);
	
	//check if the bit is ON or OFF
	if((num&mask) == mask)
	{
		printf("Bit at position %d in %u is ON\n",pos,num);
	}
	else
	{
		printf("Bit at position %d in %u is OFF\n",pos,num);
	}	
}