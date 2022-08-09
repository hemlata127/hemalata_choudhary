/*
Problem Statement: Accept two strings from the user and concatenate the second string after the first string. Display both the strings.
Enter string1: Hemalata
Enter string2: Choudhary
After concatenation string1 = HemalataChoudhary
After concatenation string2 = Choudhary
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringConcat(char*,char*);

//entry point function
int main(void)
{
	char str1[80];
	char str2[80];
	
	printf("Enter string1: ");
	scanf("%[^\n]s",str1);
	getchar();
	printf("Enter string2: ");
	scanf("%[^\n]s",str2);
	
	StringConcat(str1,str2);
	
	printf("After concatenation string1 = %s\n",str1);
	printf("After concatenation string2 = %s\n",str2);
	
	exit(0);
}

//function definition
void StringConcat(char* str1,char* str2)
{
	while(*str1 != '\0')
	{
		str1++;
	}
	
	while(*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
}