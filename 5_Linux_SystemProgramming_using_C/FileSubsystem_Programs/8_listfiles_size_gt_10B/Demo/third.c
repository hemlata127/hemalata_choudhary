//Problem statement: Program to divide two numbers
#include"header.h"		//local header file inclusion
int main()		//entry point function
{
	int num1 = 0;		//local variables
	int num2 = 0;
	float ans = 0.0;
	printf("Enter first number: ");
	scanf("%d",&num1);
	printf("Enter second number: ");
	scanf("%d",&num2);
	ans = Divide(num1,num2);		//function call
	printf("Quotient of %d/%d is %f",num1,num2,ans);
	return 0;
}