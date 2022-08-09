/*
Accept a positive number from the user and print numbers starting from that number till 1
*/

//header file inclusion for te library functions used in the program
#include<stdio.h>
#include<stdlib.h>

//function declaration
void PrintNumber(int);

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter a positive non zero number: ");
	scanf("%d",&num);
	
	PrintNumber(num);
	
	exit(0);
}

//function definition
void PrintNumber(int no)
{
	int i = 0;
	
	//check for invalid input
	if(no<=0)
	{
		printf("You have not entered a positive non zero number\n");
		return;
	}
	
	for(i=no;i>=1;i--)
	{
		printf("%d ",i);
	}
	printf("\n");
}