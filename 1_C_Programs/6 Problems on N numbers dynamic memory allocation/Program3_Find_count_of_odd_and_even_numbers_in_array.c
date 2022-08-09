/*
Problem Statement: Accept N numbers from user and display the count of odd and even numbers among them
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declarations
void AcceptElements(int*,int);
void DisplayElements(int*,int);
int CountEvenElements(int*,int);
int CountOddElements(int*,int);

//entry point function
int main(void)
{
	int size = 0;
	int* arr = NULL;
	int even_count = 0;
	int odd_count = 0;
	
	//accept the size from the user
	printf("Enter size of array, positive non zeror number: ");
	scanf("%d",&size);
	
	//check for invalid array size
	if(size<=0)
	{
		printf("Invalid size, not a positive non zero number\n");
		exit(-1);
	}
	
	//allocate memory for array dynamically
	arr = (int*)malloc(size*sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//Accept the array elements
	AcceptElements(arr,size);
	
	//Display the accepted elements
	DisplayElements(arr,size);
	
	//Find count of even numbers in the array
	even_count = CountEvenElements(arr,size);
	printf("Number of even elements: %d\n",even_count);
	
	//Find count of odd numbers in the array
	odd_count = CountOddElements(arr,size);
	printf("Number of odd elements: %d\n",odd_count);
	
	exit(0);
}

//function definitions
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

int CountEvenElements(int* arr,int size)
{
	int i = 0;
	int count = 0;
	
	for(i=0;i<size;i++)
	{
		if(arr[i]%2 == 0)
		{
			count++;
		}
	}
	return count;
}

int CountOddElements(int* arr,int size)
{
	int i = 0;
	int count = 0;
	
	for(i=0;i<size;i++)
	{
		if(arr[i]%2 != 0)
		{
			count++;
		}
	}
	return count;
}
