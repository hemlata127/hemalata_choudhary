/*
printf() demo - use of minimum field width specifier and precison specifier
*/

#include<stdio.h>

int main()
{
	int x = 12345;
	float y = 345.678;
	
	printf("%3d %5d %8d\n",x, x, x);
	printf("%3f %10f %15f\n",y, y, y);
	printf("%3e %13e %16e\n",y, y, y);
	//minimum field width specifier and precision specifier
	printf("%3.3f %10.5f %15.6f\n",y, y, y);
	printf("%3.3e %13.5e %16.6e\n",y, y, y);
	
	exit(0);
}