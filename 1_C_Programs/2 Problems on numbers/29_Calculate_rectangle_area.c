/*
Problem Statement: Write a program to accept length and breadth of a rectangle from user and calculate its area (Area = Width * Height)
Input : 5.3 9.78
Output : 51.834 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
float CalculateRectangleArea(float,float);

//entry point function
int main(void)
{
	float length = 0.0;
	float breadth = 0.0;
	float area = 0.0;
	
	printf("Enter length: ");
	scanf("%f",&length);
	printf("Enter breadth: ");
	scanf("%f",&breadth);
	
	if((length<=0)||(breadth<=0))
	{
		printf("Invalid dimensions\n");
		exit(-1);
	}
	
	area = CalculateRectangleArea(length,breadth);
	
	printf("Area = %.4f\n",area);
	
	exit(0);
}

//function definition
float CalculateRectangleArea(float length, float breadth)
{
	return (length*breadth);
}