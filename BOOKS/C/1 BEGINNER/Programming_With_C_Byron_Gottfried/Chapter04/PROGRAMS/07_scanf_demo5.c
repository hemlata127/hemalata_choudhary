/*
Demo of scanf function - use of field width
*/

#include<stdio.h>

int main()
{
	char name[50];
	int a,b;
	float f;
	
	printf("Enter a string, two integers, one float\n");
	scanf("%50s %3d %3d %3f",name, &a, &b, &f);
	printf("name = %s\na = %d\nb = %d\nf = %f\n",name,a,b,f);
	
	exit(0);
}