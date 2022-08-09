/*
Problem Statement: Accept N numbers from user and return product of odd elements in the array
Enter array size: 5
Enter 5 elements:
12
3
4
2
5
Entered elements are:
12 3 4 2 5
Product of odd elements of array: 15
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void AcceptElements(int*,int);
void DisplayElements(int*,int);
int ProductOfOddElements(int*,int);

//entry point function - program execution begins here
int main(void)
{
	int size = 0;
	int* arr = NULL;
	int odd_product = 0;
	
	//Accept the size of array
	printf("Enter array size: ");
	scanf("%d",&size);
	
	//check for invalid array size
	if(size<=0)
	{
		printf("Invalid array size\n");
		exit(-1);
	}
	
	//dynamically allocate memory for accepted number of elements
	arr = (int*)malloc(size*sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//Accept the array elements
	AcceptElements(arr,size);
	
	//Display the entered elemnts
	DisplayElements(arr,size);
	
	//call function to find product of odd elements
	odd_product = ProductOfOddElements(arr,size);

	printf("Product of odd elements of array: %d\n",odd_product);
	
	exit(0);
}

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

int ProductOfOddElements(int* arr, int size)
{
	int result = 1;
	int i = 0;
	
	for(i=0;i<size;i++)
	{
		if(arr[i]%2 != 0)
		{
			result = result * arr[i];
		}
	}
	
	return result;
}