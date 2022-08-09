/*
Problem Statement: Accept number of rows and number of columns from user and display below pattern.
Input : iRow = 5 iCol = 5
Output :
  1  2  3  4  5
 -1 -2 -3 -4 -5
  1  2  3  4  5
 -1 -2 -3 -4 -5
  1  2  3  4  5
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
	
	printf("Enter row value, positive non zero value: ");
	scanf("%d",&iRow);
	printf("Enter column value, positive non zero value: ");
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
	
	int i = 0;
	int j = 0;
	
	for(i=1;i<=iRow;i++)
	{
		for(j=1;j<=iCol;j++)
		{
			if(i%2 == 0)
			{
				printf("%d ",-j);
			}
			else
			{
				printf(" %d ",j);
			}
		}
		printf("\n");
	}
	
}