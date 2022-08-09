/*
Problem Statement: Accept a number from the user and print * that many number of times on the console
*/

//header file inclusion for printf(), scanf() and exit() functions
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayCharacter(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	DisplayCharacter(num);
	
	exit(0);
}

//function definition
void DisplayCharacter(int no)
{
	int i = 0;
	if(no<=0)
	{
		printf("Entered number is not a positive number\n");
		return;
	}
	
	for(i=0;i<no;i++)
	{
		printf("* ");
	}
	printf("\n");
}