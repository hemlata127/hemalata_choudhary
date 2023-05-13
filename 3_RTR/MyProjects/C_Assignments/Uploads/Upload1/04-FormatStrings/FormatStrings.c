#include<stdio.h>

int main(void)
{
	//code
	printf("\n\n");
	printf("******************************************************");
	printf("\n\n");

	printf("Hello World !!!\n");

	int a = 13;
	printf("Integer decimal value of a = %d\n", a);
	printf("Octal value of a = %o\n", a);
	printf("Hexadecimal value of a (hexadecimal letter in lower case) = %x\n", a);
	printf("Hexadecimal value of a (hexadecimal letter in upper case) = %X\n", a);

	char ch = 'A';
	printf("Character ch = %c\n", ch);
	char str[] = "Astromedicomp's Real Time Rendering Batch";
	printf("String str = %s\n\n", str);

	long num = 30121995L;
	printf("Long integer = %ld\n\n", num);

	unsigned int b = 7;
	printf("Unsigned int b = %u\n", b);

	float f_num = 3012.1995f;
	printf("Floating point number with just %%f = %f\n", f_num);
	printf("Floating point number with %%4.2f = %4.2f\n", f_num);
	printf("Floating point number with %%6.5f = %6.5f\n\n", f_num);

	double d_pi = 3.14159265358979323846;
	printf("Double Precision Floating Point Number without exponential = %g\n", d_pi);
	printf("Double Precision Floating Point Number with exponent in small case = %e\n", d_pi);
	printf("Double Precision Floating Point Number with exponent in upper case = %E\n", d_pi);
	printf("Double Hexadecimal value of d_pi with hexadecimal letter in small case= %a\n", d_pi);
	printf("Double Hexadecimal value of d_pi with hexadecimal letter in upper case = %A\n\n", d_pi);

	printf("******************************************************");

	printf("\n\n");

	return (0);
}
