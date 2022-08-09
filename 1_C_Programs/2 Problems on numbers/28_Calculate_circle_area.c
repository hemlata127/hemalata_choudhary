/*
Problem Statement: Write a program that accepts radius from user and calculates the area of circle
Consider value of PI as 3.14. (Area = PI * Radius * Radius)
Input : 5.3
Output : 88.2026
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define PI 3.14

//function declaration
float FindCircleArea(float);

//entry point function
int main(void)
{
	float radius = 0.0;
	float area = 0.0;
	
	printf("Enter radius of circle: ");
	scanf("%f",&radius);
	
	if(radius<=0)
	{
		printf("Invalid radius\n");
		exit(-1);
	}
	
	area = FindCircleArea(radius);
	
	printf("Area = %.3f\n",area);
	
	exit(0);
}

float FindCircleArea(float radius)
{
	return (PI * radius * radius);
}