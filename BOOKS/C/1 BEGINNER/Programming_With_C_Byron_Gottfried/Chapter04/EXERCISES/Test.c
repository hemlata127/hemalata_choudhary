#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char text[80];
	scanf("%[^*]s",text);
	puts(text);
	exit(0);
}