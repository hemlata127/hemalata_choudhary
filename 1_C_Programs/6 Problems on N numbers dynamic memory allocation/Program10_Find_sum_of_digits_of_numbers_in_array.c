/*
Problem Statement: Accept N numbers from the user. Display sum of digits of each numbers
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void AcceptElements(int*, int);
void DisplayElements(int*, int);
int SumDigits(int);
void DisplaySumfDigits(int*,int);

//entry point function
int main(void)
{
	int size = 0;
	int* arr = NULL;
	
	//Accept the array size
	printf("Enter array size: ");
	scanf("%d",&size);
	
	//check for invalid array size
	if(size<=0)
	{
		printf("Invalid array size, not a positive non zero number\n");
		exit(-1);
	}
	
	//dynamically allocate memory for array
	arr = (int*)malloc(size*sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//Accept the elements
	AcceptElements(arr,size);
	
	//Display the elements
	DisplayElements(arr,size);
	
	//display sum of digits of numbers in array
	DisplaySumfDigits(arr,size);
	
	exit(0);
}

//function definition
void AcceptElements(int* arr, int size)
{
	int i = 0;
	
	printf("Enter %d elements: \n",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
}

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

int SumDigits(int num)
{
	int sum = 0;
	
	while(num>0)
	{
		sum = sum + (num%10);
		num = num/10;
	}
	
	return sum;
}

void DisplaySumfDigits(int* arr, int size)
{
	int i = 0;
	
	printf("Sum of digits of number in array: \n");
	
	for(i=0;i<size;i++)
	{
		printf("%d ",SumDigits(arr[i]));
	}
	printf("\n");
}