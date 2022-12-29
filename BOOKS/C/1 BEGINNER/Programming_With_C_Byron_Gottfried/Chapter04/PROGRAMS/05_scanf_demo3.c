/*
Demo of scanf function to accept string with white space
*/

#include<stdio.h>

int main()
{
	char name[50];
	
	//one way to enter string with white spaces
	printf("Enter full name: ");
	//space before A will ignore any character from previous input
	scanf("%[ ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz]",name);
	printf("You entered: %s\n",name);
	
	exit(0);
}