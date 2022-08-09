/*
Write a program to display the following pattern:
Enter a positive number: 7
       *
      ***
     *****
    *******
   *********
  ***********
 *************
***************
 *************
  ***********
   *********
    *******
     *****
      ***
       *
*/

#include<stdio.h>
#include<stdlib.h>

void PrintPattern(int);

int main(void)
{
	int num = 0;
		
	printf("Enter a positive number: ");
	scanf("%d",&num);
		
	if(num<=0)
	{
		printf("Invalid value\n");
		exit(1);
	}
	
	PrintPattern(num);
	
	exit(0);
}

void PrintPattern(int num)
{
	int row = num;
	int col = (num * 2) + 1;
	
	int i = 0;
	int j = 0;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if((j>=((col/2)-i))&&(j<=((col/2)+i)))
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
	for(i=row;i>=0;i--)
	{
		for(j=0;j<col;j++)
		{
			if((j>=((col/2)-i))&&(j<=((col/2)+i)))
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