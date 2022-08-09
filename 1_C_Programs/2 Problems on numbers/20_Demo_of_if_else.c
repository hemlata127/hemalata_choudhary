/*
Problem Statement: Write a program which accept number from user and if number is less than 50 then print SMALL, if it is greater than 50 and less than 100 then print MEDIUM, if it is greater than 100 then print LARGE. 
Input : 75
Output : Medium 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
	if(num<=50)
	{
		printf("SMALL\n");
	}
	else if((num>50)&&(num<100))
	{
		printf("MEDIUM\n");
	}
	else
	{
		printf("LARGE\n");
	}
	
	exit(0);
}
