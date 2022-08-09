/*
Problem Statement: Accept two strings from the user. Accept a number x and compare first x characters of the two strings
Run1:
Enter string1: Unix Operating SYstem
Enter string2: Unix System
Enter number of characters to compare: 4
EQUAL
Run2:
Enter string1: Unix Operating System
Enter string2: Unix
Enter number of characters to compare: 7
Invalid value of x, should be positive non zero and lesser than length of string1 and string2
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define TRUE 1
#define FALSE 0

//typedef
typedef int BOOL;

//function declaration
BOOL StringCompareN(char*,char*,int);

//entry point function
int main(void)
{
	char str1[80] = "\0";
	char str2[80] = "\0";
	BOOL result = FALSE;
	int x = 0;
	
	printf("Enter string1: ");
	scanf("%[^\n]s",str1);
	getchar();
	printf("Enter string2: ");
	scanf("%[^\n]s",str2);
	getchar();	
	printf("Enter number of characters to compare: ");
	scanf("%d",&x);
		
	result = StringCompareN(str1,str2,x);
	if(result == TRUE)
	{
		printf("EQUAL\n");
	}
	else if(result == FALSE)
	{
		printf("UNEQUAL\n");
	}
	
	exit(0);
}

BOOL StringCompareN(char* str1,char* str2,int x)
{
	int i = 0;
	int len1 = 0;
	int len2 = 0;
	BOOL result = TRUE;
	
	//find length of string1
	while(str1[i] != '\0')
	{
		len1++;
		i++;
	}
	
	//find length of string2
	i = 0;
	while(str2[i] != '\0')
	{
		len2++;
		i++;
	}
	
	//check for invalid value of x
	if((x<=0)||(x>len1)||(x>len2))
	{
		printf("Invalid value of x, should be positive non zero and lesser than length of string1 and string2\n");
		return(-1);
	}
	
	//compare the two strings for first x characters
	for(i=0;i<x;i++)
	{
		if(str1[i] != str2[i])
		{
			result = FALSE;
			break;
		}
	}
	
	return result;
}