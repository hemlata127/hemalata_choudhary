/*
Problem Statement: Write a program to accept area in square feet and convert it to area in square meter (1 square feet = 0.0929 Square meter)
Input : 5
Output : 0.464515
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
float ConvertArea(float);

//entry point function
int main(void)
{
	float area_in_sq_feet = 0.0;
	float area_in_sq_meter = 0.0;
	
	printf("Enter area in square feet: ");
	scanf("%f",&area_in_sq_feet);
	
	if(area_in_sq_feet <= 0)
	{
		printf("Invalid input\n");
		exit(-1);
	}
	
	area_in_sq_meter = ConvertArea(area_in_sq_feet);
	
	printf("Area in square meter = %f\n",area_in_sq_meter);
	
	exit(0);
}

//function definition
float ConvertArea(float area_in_sq_feet)
{
	return (area_in_sq_feet * 0.0929);
}