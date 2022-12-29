/*
demo of puts and gets
*/

#include<stdio.h>

int main()
{
	char name[50];
	
	printf("Enter a string\n");
	
	gets(name);
	puts(name);
	
	exit(0);
}