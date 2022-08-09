/*
Problem Statement: Write a program to accept temperature in fahrenheit and convert it to celcius celsius. (1 celsius = (Fahrenheit -32) * (5/9))
Input : 10
Output : -12.2222 (10 - 32) * (5/9)
Input : 34
Output : 1.11111 (34 - 32) * (5/9)
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
float ConvertTemperaturs(float);

//entry point function
int main(void)
{
	float temperature_in_fahrenheit = 0.0;
	float temperature_in_celcius = 0.0;
	
	printf("Enter temperature in fahrenheit: ");
	scanf("%f",&temperature_in_fahrenheit);
	
	temperature_in_celcius = ConvertTemperaturs(temperature_in_fahrenheit);
	
	printf("Temperature in celcius = %.4f\n",temperature_in_celcius);
	
	exit(0);
}

//function definition
float ConvertTemperaturs(float temperature_in_fahrenheit)
{
	return((temperature_in_fahrenheit - (float)32) * ((float)5/(float)9));
}