/*
Problem Statement: Accept number of rows and number of columns from user and display below pattern.
Input : iRow = 5 iCol = 5
Output :
 2 4 6 8 10
 1 3 5 7 9
 2 4 6 8 10
 1 3 5 7 9 
 2 4 6 8 10
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayPattern(int,int);

//entry point function
int main(void)
{
	int iRow = 0;
	int iCol = 0;
	
	printf("Enter row value, positive non zero number: ");
	scanf("%d",&iRow);
	printf("Enter column value, positive non zero number: ");
	scanf("%d",&iCol);
	
	DisplayPattern(iRow,iCol);
	
	exit(0);
}

//function definition
void DisplayPattern(int iRow, int iCol)
{
	if((iRow<=0)||(iCol<=0))
	{
		printf("Invalid row or column value\n");
		return;
	}
	
	int i = 0, j = 0;
	int num = 0;
	
	for(i=1;i<=iRow;i++)
	{
		if(i%2 == 0)
		{
			num = 1;
		}
		else 
		{
			num = 2;
		}
		for(j=1;j<=iCol;j++)
		{
			printf("%d ",num);
			num = num+2;
		}
		printf("\n");
	}
}