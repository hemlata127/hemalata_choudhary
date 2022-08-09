/*
Problem Statement: Write a C program that accepts a number from the user and bit position in that number and checks if that bit is ON or OFF
Run1:
Enter a number: 299599 (1001001001001001111)
Enter bit position: 6
Bit at position 6 in 299599 is OFF
Run2:
Enter a number: 299599 (1001001001001001111)
Enter bit position: 7
64
Bit at position 7 in 299599 is ON

*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define TRUE 1
#define FALSE 0

//type def
typedef int BOOL;

//function declaration
BOOL CheckBitONOFF(unsigned int,int);

//entry point function
int main(void)
{
	unsigned int num = 0;
	int pos = 0;
	BOOL result = FALSE;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	printf("Enter bit position: ");
	scanf("%d",&pos);
	
	if((pos<1)||(pos>32))
	{
		printf("Invalid bit position, position should be between 1 and 32\n");
		exit(-1);
	}
	
	result = CheckBitONOFF(num,pos);
	
	if(result == TRUE)
	{
		printf("Bit at position %d in %u is ON\n",pos,num);
	}
	else
	{
		printf("Bit at position %d in %u is OFF\n",pos,num);
	}
	
	exit(0);
}

//function definition
BOOL CheckBitONOFF(unsigned int num, int pos)
{
	unsigned int mask = 0x00000001;
	
	mask = mask<<(pos-1);
	
	printf("%d\n",mask);
	
	if((num & mask) == mask)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}