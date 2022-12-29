/*
Problem statement: Write a program to calculate area of a circle
*/

//header file that contains type declarations of printf() and scanf() functions
#include<stdio.h>

//header file that contains type declaration of exit() function
#include<stdlib.h>

//preprocessor directive
#define PI 3.14

int main(void)
{
	//variable definition
	float radius = 0.0;
	float area = 0.0;
	
	//take the input
	printf("Enter radius: ");
	scanf("%f",&radius);
	
	//computing of the area
	area = PI * radius * radius;
	
	//print the output
	printf("Area of circle is: %.3f\n",area);
	
	//return from main - call the exit function to clear the memory and resoures taken by the program
	exit(0);
}