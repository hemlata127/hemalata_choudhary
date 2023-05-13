#include<stdio.h>

#define MY_PI 3.1415926535897932

#define AMC_STRING "Astromedicomp RTR"

//If first constant is not assigned a value, it is assumed to be 0
	//And rest of the constants are assigned next consecutive value from 0 onwards

	//unnamed enums
enum
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
};

enum
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
};

//named enums
enum Numbers
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE = 5,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
};

enum boolean
{
	TRUE = 1,
	FALSE = 0,
};

int main(void)
{
	//local constant declarations
	const double epsilon = 0.000001;

	//code
	printf("\n\n");
	printf("Local constant epsilon = %lf\n", epsilon);

	printf("Sunday is Day number = %d\n", SUNDAY);
	printf("Monday is Day NUmber = %d\n", MONDAY);
	printf("Tuesday is Day Number = %d\n", TUESDAY);
	printf("Wednesday is Day Number = %d\n", WEDNESDAY);
	printf("Thursday is Day Number = %d\n", THURSDAY);
	printf("Friday is Day Number = %d\n", FRIDAY);
	printf("Saturday is Day Number = %d\n\n", SATURDAY);

	printf("One is Enum Number = %d\n", ONE);
	printf("Two is Enum Number = %d\n", TWO);
	printf("Three is Enum Number = %d\n", THREE);
	printf("Four is Enum Number = %d\n", FOUR);
	printf("Five is Enum Number = %d\n", FIVE);
	printf("Six is Enum Number = %d\n", SIX);
	printf("Seven is Enum Number = %d\n", SEVEN);
	printf("Eight is Enum Number = %d\n", EIGHT);
	printf("Nine is Enum Number = %d\n", NINE);
	printf("Ten is Enum Number = %d\n\n", TEN);

	printf("January is month number = %d\n", JANUARY);
	printf("February is month number = %d\n", FEBRUARY);
	printf("March is month number = %d\n", MARCH);
	printf("April is month number = %d\n", APRIL);
	printf("May is month number = %d\n", MAY);
	printf("June is month number = %d\n", JUNE);
	printf("July is month number = %d\n", JULY);
	printf("August is month number = %d\n", AUGUST);
	printf("September is month number = %d\n", SEPTEMBER);
	printf("October is month number = %d\n", OCTOBER);
	printf("November is month number = %d\n", NOVEMBER);
	printf("December is month number = %d\n\n", DECEMBER);

	printf("Value is True is = %d\n", TRUE);
	printf("Value os False is = %d\n\n", FALSE);

	printf("Value of Macro MY_PI is = %lf\n", MY_PI);
	printf("Area of circle of radius 2 is = %f\n", MY_PI * 2.0f * 2.0f);

	printf("\n\n");

	printf(AMC_STRING);

	printf("\n\n");

	return (0);
}
