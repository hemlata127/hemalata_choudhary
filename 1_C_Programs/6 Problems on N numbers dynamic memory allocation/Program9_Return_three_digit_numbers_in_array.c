/*
Problem Statement: Accept N numbers from user and return three digit numbers amongst them
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void AcceptElements(int*,int);
void DisplayElements(int*,int);
int CountDigits(int);
void DisplayThreeDigitNumbers(int*,int);

//entry point function - program execution begins here
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
	
	//dynamically allocate memory for accepted array size
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
	
	//Display three digit numbers
	DisplayThreeDigitNumbers(arr,size);
	
	exit(0);
}

void AcceptElements(int* arr, int size)
{
	int i = 0;
	
	printf("Enter %d numbers: \n",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
}

void DisplayElements(int* arr, int size)
{
	int i = 0;
	printf("Entered numbers are: \n");
	
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int CountDigits(int num)
{
	int count = 0;
	
	while(num>0)
	{
		count++;
		num = num/10;
	}
	
	return count;
}

void DisplayThreeDigitNumbers(int* arr, int size)
{
	int i = 0;
	int count = 0;
	
	printf("Three digit numbers from the array are: \n");
	for(i=0;i<size;i++)
	{
		if((count = CountDigits(arr[i])) == 3)
		{
			printf("%d ",arr[i]);
		}
	}
	
	printf("\n");
}
