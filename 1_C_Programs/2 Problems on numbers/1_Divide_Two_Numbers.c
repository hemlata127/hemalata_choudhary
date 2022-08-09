/*
Problem statement: Write a program to accept two numbers from user and print the result of their division
*/

//header file that contains type declaration of printf() and scanf() functions
#include<stdio.h>
//include header file that contains type declaration of exit() function
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

//function declaration
BOOL Divide(int,int,float*);

//entry point function
int main(void)
{
	//local variable declaration
	int num1 = 0;
	int num2 = 0;
	float answer = 0.0;
	BOOL result = FALSE;
	
	//accept input from user
	printf("Enter number1: ");
	scanf("%d",&num1);
	
	printf("Enter number2: ");
	scanf("%d",&num2);
	
	//call the function to compute division
	result = Divide(num1,num2,&answer);
	
	//print the output if result is TRUE
	if(result == TRUE)
	{
		printf("Result: %.3f\n",answer);
	}
	
	//return from main, terminate the program
	exit(0);
}

//function definition
BOOL Divide(int no1, int no2, float* ans)
{
	//check for divide by zero error
	if(no2 == 0)
	{
		printf("Divisor cannot be zero\n");
		return FALSE;
	}
	
	//compute the division
	*ans = (float)no1/(float)no2;
	
	return TRUE;	
}
