/*
Problem Statement: Write a program to accept total marks and obtained marks and calculate the percentage
Input : 1000 745
Output : 74.5% 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
float FindPercentage(float, float);

//entry point function
int main(void)
{
	float total_marks = 0.0;
	float obtained_marks = 0.0;
	float percentage = 0.0;
	
	printf("Enter total marks: ");
	scanf("%f",&total_marks);
	printf("Enter obtained marks: ");
	scanf("%f",&obtained_marks);
	
	if((total_marks<=0)||(obtained_marks<0)||(total_marks<obtained_marks))
	{
		printf("Invalid input\n");
		exit(-1);
	}
	
	percentage = FindPercentage(total_marks, obtained_marks);
	
	printf("Percentage: %.2f%%\n",percentage);
	
	exit(0);
}

//function definition
float FindPercentage(float total_marks, float obtained_marks)
{
	return ((obtained_marks/total_marks)*100);
}