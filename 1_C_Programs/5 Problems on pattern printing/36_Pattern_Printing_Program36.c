/*
Problem Statement: Accept number of rows and number of columns from user and display below pattern.
Input : iRow = 6 iCol = 6
Output :
 * * * * * *
 * # # # * *
 * # # * $ *
 * # * $ $ *
 * * $ $ $ *
 * * * * * *
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
	printf("Enter column value, positive non zeror number, same as row value: ");
	scanf("%d",&iCol);
	
	DisplayPattern(iRow,iCol);
	
	exit(0);
}

//function definition
void DisplayPattern(int iRow, int iCol)
{
	if((iRow<=0)||(iCol<=0)||(iRow!=iCol))
	{
		printf("INvalid row or column value\n");
		return;
	}
	
	int i = 0;
	int j = 0;
	
	for(i=iRow;i>=1;i--)
	{
		for(j=1;j<=iCol;j++)
		{
			if((i==1)||(i==iRow)||(j==1)||(j==iCol)||(i==j))
			{
				printf("* ");
			}
			else if(j<i)
			{
				printf("# ");
			}
			else
			{
				printf("$ ");
			}
		}
		printf("\n");
	}	
}