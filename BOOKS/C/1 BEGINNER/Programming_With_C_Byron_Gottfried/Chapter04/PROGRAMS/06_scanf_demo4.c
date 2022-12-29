/*
Demo of scanf function to accept string with whitespace
*/

#include<stdio.h>

int main()
{
	char name[50];
	
	printf("Enter full name: ");
	//accept all characeters from keyboard except \n - stop when you see \n
	scanf("%[^\n]",name);
	printf("You entered %s\n",name);	
	
	exit(0);
}