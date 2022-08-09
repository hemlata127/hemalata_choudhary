/*
Problem Statement: Accept number of rows and number of columns from user and display below pattern.
Input : iRow = 4 iCol = 4
Output :
 1 2 3 4
 5 6 7 8
 9 1 2 3
 4 5 6 7 
*/

//include header files
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
	printf("Enter column value, positive non zeror value: ");
	scanf("%d",&iCol);
	
	DisplayPattern(iRow, iCol);
	
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
	int num = 1;
	
	for(i=1;i<=iRow;i++)
	{
		for(j=1;j<=iCol;j++)
		{
			printf("%d ",num);
			if(num == 9)
			{
				num = 1;
			}
			else
			{
				num++;
			}
		}
		printf("\n");
	}
	printf("\n");	
}