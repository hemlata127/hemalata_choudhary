/*
Sample program to display the functioning of the input output library functions in C program
*/

//include the library function - stdio.h which contains information about the standard IO library functions
#include<stdio.h>

int main()
{
	int a, b;
	float x;
	char c;
	
	c = getchar();
	scanf("%d %d",&a, &b);
	scanf("%f",&x);
		
	printf("a = %d\nb = %d\n",a,b);
	printf("x = %3.5f\n",x);
	putchar(c);
	
	exit(0);	
}