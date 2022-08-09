/*
Problem Statement: Accept N numbers from user and find the maximum and minimum numbers among them
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void AcceptElements(int*,int);
void DisplayElements(int*,int);
int FindMaxElement(int*,int);
int FindMinElement(int*,int);

//entry point function
int main(void)
{
	int size = 0;
	int* arr = NULL;
	int max_number = 0;
	int min_number = 0;
	
	//Accept the array size
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	//check for invalid array size
	if(size<=0)
	{
		printf("Invalid size, not a positive non zero number\n");
		exit(-1);
	}
	
	//allocate memory dynamically for array
	arr = (int*)malloc(size * sizeof(int));
	
	//check for memory failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//Accept the array elements
	AcceptElements(arr,size);
	
	//Display the array elements
	DisplayElements(arr,size);
	
	//find the maximum number in the array
	max_number = FindMaxElement(arr,size);
	printf("Maximum number = %d\n",max_number);
	
	//find the minimum element in the array
	min_number = FindMinElement(arr,size);
	printf("Minimum number = %d\n",min_number);
	
	exit(0);
}

//function definitions
void AcceptElements(int* arr,int size)
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
	
	printf("Entered array elements are: \n");
	
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int FindMaxElement(int* arr, int size)
{
	int i = 0;
	int max = arr[0];
	
	for(i=1;i<size;i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	
	return max;
}

int FindMinElement(int* arr, int size)
{
	int i = 0;
	int min = arr[0];
	
	for(i=1;i<size;i++)
	{
		if(arr[i]<min)
		{
			min = arr[i];
		}
	}
	
	return min;
}