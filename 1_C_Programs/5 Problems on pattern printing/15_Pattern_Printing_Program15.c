/*
Problem Statement: Accept number of rows and number of columns from user and display below pattern.
Input : iRow = 3 iCol = 5
Output :
 A A A A A
 B B B B B
 C C C C C
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function type declaration
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
	
	int i = 0;
	int j = 0;
	char ch = 'A';
	
	for(i=1;i<=iRow;i++)
	{
		for(j=1;j<=iCol;j++)
		{
			printf("%c ",ch);
		}
		printf("\n");
		ch++;
	}
	printf("\n");
}