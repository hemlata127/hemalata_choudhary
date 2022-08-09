/*
Problem Statement: Accept a number from the user. If the entered number is less than 10, print "Hello" otherwise print "World" on the screen
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//entry point function
int main(void)
{
	int num = 0;
	
	printf("Enter a number: ");
	scanf("%d",&num);
	
	if(num<10)
	{
		printf("Hello\n");
	}
	else
	{
		printf("World\n");
	}
	
	exit(0);
}