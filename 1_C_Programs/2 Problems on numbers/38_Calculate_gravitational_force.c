/*
Problem Statement: According to Newton's law of gravity, gravitational force of attraction can be calculated using the following formula:
F = (G*m1*m2)/(r*r);
G is the gravitational constant whose value is given by:
G = 6.67 * 10^-11
Write a program to accept m1, m2 and r form the user and find the gravitational force of attraction
Do neccessary validity checks, values of m1, m2 and r should be positive

Program execution:
Enter mass of first body in kilograms, m1: 5.8E24
Enter mass of second body in kilograms, m2: 70
Enter distance between the two bodies in meter, r: 6.39E6
Gravitational force of attraction for the given values of m1, m2 and r = 663.208557 N
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
float CalculateGravitationalConstant(float const,float,float,float);

//entry point function
int main(void)
{
	float m1 = 0.0;
	float m2 = 0.0;
	float r = 0.0;
	float const G = 6.67E-11;
	float F = 0.0;
	
	//accept the imputs and do necessary validations
	printf("Enter mass of first body in kilograms, m1: ");
	scanf("%f",&m1);
	if(m1<=0)
	{
		printf("Invalid value for m1, should be positive non zero value\n");
		exit(-1);
	}
	printf("Enter mass of second body in kilograms, m2: ");
	scanf("%f", &m2);
	if(m2<=0)
	{
		printf("Invalid value for m2, should be positive non zero value\n");
		exit(-1);
	}
	printf("Enter distance between the two bodies in meter, r: ");
	scanf("%f",&r);
	if(r<=0)
	{
		printf("Invalid value for r, should be a positive non zero value\n");
		exit(-1);
	}
	
	F = CalculateGravitationalConstant(G,m1,m2,r);
	printf("Gravitational force of attraction for the given values of m1, m2 and r = %f N\n",F);
	
	exit(0);
}

//function definition
float CalculateGravitationalConstant(float const G, float m1, float m2, float r)
{
	return (G*m1*m2)/(r*r);
}