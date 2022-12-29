/*
demo of printf function using %f to print decimal number in floating point format and %e to print decimal in scientific notation
*/

#include<stdio.h>

int main()
{
	double x = 5000.0;
	double y = 0.0025;
	
	printf("%f %f %f %f\n\n",x+y, x-y, x*y, x/y);
	printf("%e %e %e %e\n",x+y, x-y, x*y, x/y);
	
	exit(0);
}