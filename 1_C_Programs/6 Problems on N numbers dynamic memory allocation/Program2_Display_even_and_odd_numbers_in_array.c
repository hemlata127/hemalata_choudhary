/*
Problem Statement: Accept N numbers from the user and display the even and odd numbers among them
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void AcceptElements(int*,int);
void DisplayElements(int*,int);
void DisplayEvenElements(int*,int);
void DisplayOddElements(int*,int);

//entry point function
int main(void)
{
	int size = 0;
	int* arr = NULL;
	
	printf("Enter size, positive non zero number: ");
	scanf("%d",&size);
	
	//check for invalid size
	if(size<=0)
	{
		printf("Invalid size, non a positive non zero number\n");
		exit(-1);
	}
	
	//allocate the memory dynamically
	arr = (int*)malloc(size * sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//call function to accept the elements from the user
	AcceptElements(arr,size);
	
	//call function to display the entered elements
	DisplayElements(arr,size);
	
	//call function to display even elements
	DisplayEvenElements(arr,size);
	
	//call function to display the odd elements
	DisplayOddElements(arr,size);
	
	//exit from main
	exit(-1);
}

//function definition to accept the elements from the user
void AcceptElements(int* arr, int size)
{
	int i = 0;
	
	printf("Enter %d elements: \n",size);
	
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
}

//function definition to display the entered elements
void DisplayElements(int* arr, int size)
{
	int i = 0;
	
	printf("Entered elements are: \n");
	
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//function definition to display even elements
void DisplayEvenElements(int* arr, int size)
{
	int i = 0;
	
	printf("Even elements are: \n");
	
	for(i=0;i<size;i++)
	{
		if(arr[i]%2 == 0)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}

//function definition to display odd elements
void DisplayOddElements(int* arr, int size)
{
	int i = 0;
	
	printf("Odd elements are: \n");
	
	for(i=0;i<size;i++)
	{
		if(arr[i]%2 != 0)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}