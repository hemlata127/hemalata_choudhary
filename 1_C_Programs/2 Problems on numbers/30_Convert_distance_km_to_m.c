/*
Problem Statement: Write a program to accept distance in km and convert it to meter (1km = 1000m)
Input : 5
Output : 5000 
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
float ConvertDistance(float);

//entry point function
int main(void)
{
	float distance_in_km = 0.0;
	float distance_in_m = 0.0;
	
	printf("Enter distance in kilimeter: ");
	scanf("%f",&distance_in_km);
	
	if(distance_in_km <= 0)
	{
		printf("Invaid distance\n");
		exit(-1);
	}
	
	distance_in_m = ConvertDistance(distance_in_km);
	
	printf("Distance in meter = %.2f\n",distance_in_m);
	
	exit(0);
}

//function definition
float ConvertDistance(float distance_in_km)
{
	return (distance_in_km * 1000);
}