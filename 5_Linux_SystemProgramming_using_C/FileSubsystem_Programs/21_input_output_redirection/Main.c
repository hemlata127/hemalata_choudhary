/*
Program to demonstrate IO redirection
Use as: ./myexe <Input.txt >Output.txt 2>Error.txt
*/
#include<stdio.h>


int main()
{
	int no1 = 0,no2 = 0,no3 = 0;
	int ans = 0;
	printf("Enter three numbers:\n");
	scanf("%d%d%d",&no1,&no2,&no3);
	ans = no1+no2+no3;
	printf("Addition is %d\n",ans);
	return 0;
}