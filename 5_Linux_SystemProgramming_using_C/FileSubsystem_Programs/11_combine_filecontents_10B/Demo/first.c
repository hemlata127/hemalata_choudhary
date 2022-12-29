//demo.c
#include<stdio.h>
int main()
{
	char crr[10];
	char *p = &crr;
	printf("From printf: Hello\n");
	sprintf(p,"Hello\n");
	printf("From sprintf: %s",crr);
	return 0;
}
