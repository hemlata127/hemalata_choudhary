/*
Write a program to display the following pattern:
Enter a positive number for row value: 8
Enter a positive value for column value: 8
*
**
***
****
*****
******
*******
********
********
********
********
********
********
********
********
********
********
 *******
  ******
   *****
    ****
     ***
      **
       *
*/

#include<stdio.h>
#include<stdlib.h>

void PrintPattern(int,int);

int main(void)
{
	int row = 0;
	int col = 0;
		
	printf("Enter a positive number for row value: ");
	scanf("%d",&row);
	printf("Enter a positive value for column value: ");
	scanf("%d",&col);
	
	if((row<=0)||(col<=0))
	{
		printf("Invalid row or column value\n");
		exit(1);
	}
	
	PrintPattern(row,col);
	
	exit(0);
}

void PrintPattern(int row, int col)
{
	int i = 0;
	int j = 0;
	
	//part1
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j<=i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	//part 2
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//part3
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j>=i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
}