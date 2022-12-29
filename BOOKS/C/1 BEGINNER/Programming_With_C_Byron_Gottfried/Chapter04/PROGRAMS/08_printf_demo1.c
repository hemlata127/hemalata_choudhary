/*
Demo of printf function - control groups, format specifiers
*/

#include<stdio.h>

int main()
{
	int no1, no2;
	float f;
	char name[50];
	
	printf("Enter two integers, one float, one string: ");
	//four control groups
	scanf("%d %d %f %s",&no1,&no2,&f,name);
	//printf function combining multilple format specifiers in single string
	printf("no1 = %d\nno2 = %d\nf = %f\nname = %s\n",no1,no2,f,name);	
	
	exit(0);
}