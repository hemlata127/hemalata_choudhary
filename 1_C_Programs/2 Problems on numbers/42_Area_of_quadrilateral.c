/*
Problem statement: 
Consider sides of a quadrilateral - a,b,c,d
Accept the lengths of the sides of the quadrilateral from the user.
Print the perimeter of the quadrilateral, s = a+b+c+d;
Print the area of the quadrilateral, a = sqrt((s-a)*(s-b)*(s-c)*(s-d));
Do the validity check, a>0, b>0, c>0, d>0
Sum of any three sides of a quadrilateral should be greater than the fourth side

Program execution:
Enter a: 4
Enter b: 4
Enter c: 4
Enter d: 4
Perimeter = 16.000000
Area = 144.000000
*/

//header files
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//main function
int main(void)
{
	float a = 0.0;
	float b = 0.0;
	float c = 0.0;
	float d = 0.0;
	float s = 0.0;
	float area = 0.0;
	
	printf("Enter a: ");
	scanf("%f",&a);
	printf("Enter b: ");
	scanf("%f",&b);
	printf("Enter c: ");
	scanf("%f",&c);
	printf("Enter d: ");
	scanf("%f",&d);
	
	if((a<=0)||(b<=0)||(c<=0)||(d<=0))
	{
		printf("Invalid value for a or b or c or d, side should be positive non zero value\n");
		exit(-1);
	}
	if(((a+b+c)<d)||((b+c+d)<a)||((c+d+a)<b)||((d+a+b)<c))
	{
		printf("Invalid value for the quadrilateral sides, sum of three sides should be greater than the fourth side\n");
		exit(-1);
	}
	
	s = a+b+c+d;
	area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
	
	printf("Perimeter = %f\n",s);
	printf("Area = %f\n",area);
	
	exit(0);
}