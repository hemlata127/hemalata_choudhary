#include<stdio.h>

int main(void)
{
	//code 
	printf("\n\n");

	printf("Size of 'int' - %zu bytes\n", sizeof(int));
	printf("Size of 'unsigned int' = %zu bytes\n", sizeof(unsigned int));
	printf("Size of 'long' = %zu bytes\n", sizeof(long));
	printf("Size of 'long long' = %zu bytes\n", sizeof(long long));
	
	printf("Size of 'float' = %zu bytes\n", sizeof(float));
	printf("Size of 'double' = %zu bytes\n", sizeof(double));
	printf("Size of 'long double' = %zu bytes\n", sizeof(long double));

	printf("\n\n");

	return (0);
}
