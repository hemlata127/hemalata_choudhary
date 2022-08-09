/*
Problem Statement: Accept number of rows and number of columns from user and display below pattern.
Input : iRow = 6 iCol = 5 
Output :
 *  *  *  *  *
 *  @  @  @  *
 *  @  @  @  *
 *  @  @  @  *
 *  @  @  @  *
 *  *  *  *  *
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
	
	printf("Enter row value: ");
	scanf("%d",&iRow);
	printf("Enter column value: ");
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
			if((i==1)||(i==iRow)||(j==1)||(j==iCol))
			{
				printf("* ");
			}
			else
			{
				printf("@ ");
			}
		}
		printf("\n");
	}
}