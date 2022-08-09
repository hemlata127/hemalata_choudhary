/*
Problem Statement: Coulomb's law governs the force of attraction or repulsion between two charged particles. Magnitude of force of attraction or repulsion between two charged particles is given by following formula:
F = (k*q1*q2)/(r*r);
where q1 = charged on first body, q2 = charge on second body, r = distance between the two bodies and k is Coulombs constant, k = 8.988*10^9
Write a program to accept q1, q2 and r from the user and find the force.
Also state if the force is that of attraction or repulsion
Do the necessary validation (r should not be zero or less than zero)

Program execution:
Enter charge on first particle in Coulombs, q1: 1
Enter charge on second particle in Coulombs, q2: 1.5
Enter distance between two charged particles in meters: 1
Force of attraction is = 13482000384.000000 N
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
float CalculateForceBetweenChargedParticles(float const, float, float, float);

//entry point function
int main(void)
{
	float q1 = 0.0;
	float q2 = 0.0;
	float r = 0.0;
	float const k = 8.988E9;
	float F = 0.0;
	
	printf("Enter charge on first particle in Coulombs, q1: ");
	scanf("%f",&q1);
	printf("Enter charge on second particle in Coulombs, q2: ");
	scanf("%f",&q2);
	printf("Enter distance between two charged particles in meters: ");
	scanf("%f",&r);
	if(r<=0)
	{
		printf("Invalid value for distance, should be positive non zero value\n");
		exit(-1);
	}
	
	F = CalculateForceBetweenChargedParticles(k,q1,q2,r);
	if(F<0)
	{
		printf("Force of repulsion is = %f N\n",F);
	}
	else if(F>0)
	{
		printf("Force of attraction is = %f N\n",F);
	}
	
	exit(0);
}

//function definition
float CalculateForceBetweenChargedParticles(float const k, float q1, float q2, float r)
{
	return (k*q1*q2)/(r*r);
}