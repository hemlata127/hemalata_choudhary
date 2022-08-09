/*
Problem Statement: Accept two strings from the suer and check if they are equal
Run1:
Enter first string: Unix
Enter second string: Unix Operating System
Strings are not equal
Run2:
Enter first string: Unix Operating System
Enter second string: Unix
Strings are not equal
Run3:
Enter first string: Unix Operating System
Enter second string: Unix Operating System
Strings are equal
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
BOOL StringCompare(char*,char*);

//entry point function
int main(void)
{
	char str1[80] = "\0";
	char str2[80] = "\0";
	BOOL result = FALSE;
	
	printf("Enter first string: ");
	scanf("%[^\n]s",str1);
	getchar();
	printf("Enter second string: ");
	scanf("%[^\n]s",str2);
	
	result = StringCompare(str1,str2);
	
	if(result == TRUE)
	{
		printf("Strings are equal\n");
	}
	else
	{
		printf("Strings are not equal\n");
	}
	
	exit(0);
}

BOOL StringCompare(char* str1,char* str2)
{
	BOOL result = TRUE;
	int len1 = 0;
	int len2 = 0;
	int i = 0;
	
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
	
	//consider length of bigger string to run the loop
	if(len1>=len2)
	{
		for(i=0;i<len1;i++)
		{
			if(str1[i] != str2[i])
			{
				result = FALSE;
				break;
			}
		}
	}
	else
	{
		for(i=0;i<len2;i++)
		{
			if(str1[i] != str2[i])
			{
				result = FALSE;
				break;
			}
		}
	}
	
	return result;
}