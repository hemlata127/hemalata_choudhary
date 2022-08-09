/*
Problem Statement: Accept number of rows and number of columns from user and display below pattern.
Input : iRow = 4 iCol = 4
Output :
 A B C D
 A B C D
 A B C D
 A B C D 
*/

//include the header files
#include<stdio.h>
#include<stdlib.h>

//function type declaration
void DisplayPattern(int, int);

//entry point function
int main(void)
{
	int iRow = 0;
	int iCol = 0;
	
	printf("Enter row value (positive non zero number): ");
	scanf("%d",&iRow);
	printf("Enter column value (positive non zero number): ");
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
	char ch = '\0';
	
	for(i=1;i<=iRow;i++)
	{
		ch = 'A';
		for(j=1;j<=iCol;j++)
		{
			printf("%c ",ch);
			ch = ch+1;
		}
		printf("\n");
	}
	printf("\n");
}