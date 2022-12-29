/*
Demo of scanf function
*/

#include<stdio.h>

int main()
{
	int a, b;
	float f;
	char arr[50];
	
	printf("Enter 2 integers, one float and one string: \n");
	
	//note no & needed for an array data item
	scanf("%d %d %f %s",&a,&b,&f,arr);
	
	printf("a = %d\nb = %d\nf = %f\narr = %s\n",a,b,f,arr);
	
	exit(0);
}