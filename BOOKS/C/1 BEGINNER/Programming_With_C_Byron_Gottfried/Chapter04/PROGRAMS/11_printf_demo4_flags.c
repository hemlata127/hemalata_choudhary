/*
printf() demo using flags
*/

#include<stdio.h>

int main()
{
	int x = 123;
	int y = -34;
	float z = 123.456;
	char name[] = "Hemalata";
	
	printf("%5d %5d %5.8f\n",x, y, z);
	//puts explicit sign
	printf("%+5d %+5d %+5.8f\n",x, y, z);
	//displays left justified
	printf("%-5d %-5d %-5.8f\n",x, y, z);
	//fills left spaces with 0
	printf("%05d %05d %05.5f\n",x, y, z);
	
	exit(0);
}