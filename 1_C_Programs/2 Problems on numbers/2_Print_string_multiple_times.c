/*
Accept a string from the user. Ask user how many times the string needs to be printed. Print the string that many number of times
*/

//inclusion of header files
#include<stdio.h>
#include<stdlib.h>

//function declaration
void DisplayString(char[],int);

//entry point function
int main(void)
{
	//local variable declaration
	char str[50] = "\0";
	int num = 0;
	
	//Accept input
	printf("Enter a string: ");
	scanf("%[^\n]s",str);
	
	printf("How many time you want to print this string, enter a positive non zero number: ");
	scanf("%d",&num);
	
	//call function to display string specified number of times
	DisplayString(str,num);
	
	//return from main
	exit(0);
}

//function definition
void DisplayString(char* arr,int num)
{
	int i = 0;
	
	if(num<=0)
	{
		printf("You did not enter a positive non zero number\n");
		return;
	}
	
	for(i = 0;i<num;i++)
	{
		printf("%s\n",arr);		
	}	
}