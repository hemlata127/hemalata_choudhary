/*
Accept a string from the user and reverse it and also toggle case of each character
Enter string: Unix Operating System
Reversed string = METSYs GNITAREPo XINu
*/

//header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
void ReverseStringToogleCase(char*);

//entry point function
int main(void)
{
	char str[80] = "\0";
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	
	ReverseStringToogleCase(str);
	printf("Reversed string = %s\n",str);	
	
	exit(0);
}

//function definition
void ReverseStringToogleCase(char* str)
{
	int i = 0;
	int j = 0;
	char temp = '\0';
	int len = 0;
	
	//find the length of the string
	while(str[i] != '\0')
	{
		i++;
		len++;
	}
	
	//reverse string and toggle case
	for(i=0,j=len-1;i<=j;i++,j--)
	{
		//toggle the central character only once
		if(i==j)
		{
			if((str[i]>='A')&&(str[i]<='Z'))
			{
				str[i] = str[i] + 32;
			}
			else if((str[i]>='a')&&(str[i]<='z'))
			{
				str[i] = str[i] - 32;
			}
		}
		
		else
		{
			//toggle case of str[i]
			if((str[i]>='A')&&(str[i]<='Z'))
			{
				str[i] = str[i] + 32;
			}
			else if((str[i]>='a')&&(str[i]<='z'))
			{
				str[i] = str[i] - 32;
			}
		
			//toggle case of str[j]
			if((str[j]>='A')&&(str[j]<='Z'))
			{
				str[j] = str[j] + 32;
			}
			else if((str[j]>='a')&&(str[j]<='z'))
			{
				str[j] = str[j] - 32;
			}
		}
		
		//swap str[i] and str[j]
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;		
	}
}