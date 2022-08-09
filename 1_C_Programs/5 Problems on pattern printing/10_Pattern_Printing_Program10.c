/*
Problem Statement: Accept number of rows and number of columns from user and display
below pattern.
Input : iRow = 3 iCol = 5
Output :
 5 4 3 2 1
 5 4 3 2 1
 5 4 3 2 1 
*/

//include the header files
#include<stdio.h>
#include<stdlib.h>

//type declaration of function
void DisplayPattern(int, int);

//entry point function
int main(void)
{
	int iRow = 0;
	int iCol = 0;
	
	printf("Enter row value(non zero positive number): ");
	scanf("%d",&iRow);
	printf("Enter column value(non zero positive number)");
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
	}
	
	int i = 0;
	int j = 0;
	
	for(i=1;i<=iRow;i++)
	{
		for(j=iCol;j>=1;j--)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
	printf("\n");
}