/*
Sample program to demonstrate getchar() and putchar() libraru functions
*/

#include<stdio.h>

int main()
{
	char ch1;
	char ch2;
	printf("Enter a character: ");
	ch1 = getchar();
	ch2 = toupper(ch1);
	putchar(ch2);
	
	exit(0);
}