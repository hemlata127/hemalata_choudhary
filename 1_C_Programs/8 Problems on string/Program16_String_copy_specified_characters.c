/*
Problem Statement: Accept a string from the user. Accept a number, copy specified those many characters into another string. If number entered is more than length of string, copy the entire string. Display original string and copied string.
Run1:
Enter string: Unix Operating System
Enter number of characters to copy: 6
Source string = Unix Operating System
Copied string = Unix O
Run2:
Enter string: Unix Operating System
Enter number of characters to copy: 23
Source string = Unix Operating System
Copied string = Unix Operating System
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void StringCopyN(char*,char*,int);

//entry point function
int main(void)
{
	char src[80] = "\0";
	char dest[80] = "\0";
	int num = 0;;
	
	printf("Enter string: ");
	scanf("%[^\n]s",src);
	getchar();
	printf("Enter number of characters to copy: ");
	scanf("%d",&num);
	
	if(num<=0)
	{
		printf("Invalid value, not a positive non zero number\n");
		exit(-1);
	}
	
	StringCopyN(dest,src,num);
	
	printf("Source string = %s\n",src);
	printf("Copied string = %s\n",dest);
	
	exit(0);
}

//function definition
void StringCopyN(char* dest, char* src, int num)
{
	int i = 0;
	int len = 0;
	
	//caluclate length of source string
	while(src[i] != '\0')
	{
		len++;
		i++;
	}
	
	len = len-1;
	
	if(num<len)
	{
		for(i=0;i<num;i++)
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	else
	{
		for(i=0;i<=len;i++)
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
}