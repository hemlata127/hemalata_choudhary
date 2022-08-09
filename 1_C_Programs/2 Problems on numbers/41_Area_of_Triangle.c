/*
Problem Statement: Let a,b,c be sides of the triangle.
Perimeter = a+b+c;
Semi perimeter s = (a+b+c)/2;
Area = (s*(s-a)*(s-b)*(s-c))^(1/2);
Measure of angle A = cos inverse((b*b+c*c-a*a)/(2*b*c))
Measure of angle B = cos inverse((c*c+a*a-b*b)/(2*c*a))
Measure of angle C = cos inverse((a*a+b*b-c*c)/(2*a*b))
(use acos function for cos inverse)
Display measure of angles in degrees and radians
1 radian = 57.2958 degrees
Do the validation check - sum of any two sides of a triangle should be greater than the third side

Program execution:
Enter a: 4
Enter b: 4
Enter c: 4
Perimeter = 12.000000
Area = 6.928203
Measure of angle A in radians = 1.047198
Measure of angle A in degrees = 60.000023
Measure of angle B in radians = 1.047198
Measure of angle B in degrees = 60.000023
Measure of angle C in radians = 1.047198
Measure of angle C in degrees = 60.000023

Enter a: 1
Enter b: 1
Enter c: 6
Invalid input for triangle sides
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
	float perimeter = 0.0;
	float s = 0.0;
	float area = 0.0;
	float Angle_A = 0.0;
	float Angle_B = 0.0;
	float Angle_C = 0.0;
	
	//accept the input
	printf("Enter a: ");
	scanf("%f",&a);
	printf("Enter b: ");
	scanf("%f",&b);
	printf("Enter c: ");
	scanf("%f",&c);
	
	//validations
	if((a<=0)||(b<=0)||(c<=0))
	{
		printf("Invalid value for a or b or c\n");
		exit(-1);
	}
	
	if(((a+b)<c)||((b+c)<a)||((c+a)<b))
	{
		printf("Invalid input for triangle sides\n");
		exit(-1);
	}
	
	perimeter = a+b+c;
	s = perimeter/2;
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	
	Angle_A = acos((b*b+c*c-a*a)/(2*b*c));
	Angle_B = acos((c*c+a*a-b*b)/(2*a*c));
	Angle_C = acos((b*b+a*a-c*c)/(2*a*b));
	
	printf("Perimeter = %f\n",perimeter);
	printf("Area = %f\n",area);
	
	printf("Measure of angle A in radians = %f\n",Angle_A);
	printf("Measure of angle A in degrees = %f\n",Angle_A*57.2958);
	printf("Measure of angle B in radians = %f\n",Angle_B);
	printf("Measure of angle B in degrees = %f\n",Angle_B*57.2958);
	printf("Measure of angle C in radians = %f\n",Angle_C);
	printf("Measure of angle C in degrees = %f\n",Angle_C*57.2958);
	
	exit(0);
}