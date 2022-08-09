/*
Problem statement: Quadratic equation of single variable is given by:
a*x*x + b*x + c = 0;
where a,b,c are real numbers and a != 0
The roots of the equation are given by:
r1 = (-b+((b*b - 4*a*c)^1/2))/(2*a);
r2 = (-b-((b*b - 4*a*c)^1/2))/(2*a);
Write a program that will accept a,b,c from the user and print the roots.
Do the following validity checks:
a != 0
(b*b - 4*a*c) >= 0

Program execution:
Enter value of a: 1
Enter value of b: 1
Enter value of c: -20
r1 = 4.000
r2 = -5.000
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//entry point function
int main(void)
{
	float a = 0.0;
	float b = 0.0;
	float c = 0.0;
	float r1 = 0.0;
	float r2 = 0.0;
	float temp = 0.0;
	
	printf("Enter value of a: ");
	scanf("%f",&a);
	if(a == 0)
	{
		printf("Invalid value for a, should not be 0\n");
		exit(-1);
	}
	printf("Enter value of b: ");
	scanf("%f",&b);
	printf("Enter value of c: ");
	scanf("%f",&c);
	
	temp = (b*b)-(4*a*c);
	if(temp<0)
	{
		printf("Invalid inputs\n");
		exit(-1);
	}
	
	r1 = (-b+sqrt(temp))/(2*a);
	r2 = (-b-sqrt(temp))/(2*a);
	
	printf("r1 = %.3f\n",r1);
	printf("r2 = %.3f\n",r2);
	
	exit(0);
}