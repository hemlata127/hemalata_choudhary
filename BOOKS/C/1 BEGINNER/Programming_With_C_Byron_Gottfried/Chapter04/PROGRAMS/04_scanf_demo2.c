/*
Demo of scanf function - input string with white spaces
*/

#include<stdio.h>

int main()
{
	char name[50];
	
	//Here scanf stops when it sees a whitespace
	printf("Enter full name: ");
	scanf("%s",name);
	printf("You entered: %s\n",name);
		
	exit(0);
}