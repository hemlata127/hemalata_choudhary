/*
Problem Statement: Accept N numbers from the user. Accept another number and return the last occurance of this number
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void AcceptElements(int*,int);
void DisplayElements(int*,int);
int ReturnLastIndexOfNumber(int*,int,int);

//entry point function
int main(void)
{
	int size = 0;
	int* arr = NULL;
	int search_number = 0;
	int required_index = 0;
	
	//accept size of array
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	//check for invalid size of array
	if(size<=0)
	{
		printf("Invalid array size\n");
		exit(-1);
	}
	
	//Allocate memory dynamically for accepted number of elements
	arr = (int*)malloc(sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//accept the elements from the user
	AcceptElements(arr,size);
	
	//Display the accepted elements
	DisplayElements(arr,size);
	
	//Accept the search element
	printf("Enter element to search: ");
	scanf("%d",&search_number);
	
	//find the index of last occurance of the search_number in the array
	required_index = ReturnLastIndexOfNumber(arr,size,search_number);
	
	//display the output
	printf("Index of last occurance of %d in array is: %d\n",search_number,required_index);
	
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

int ReturnLastIndexOfNumber(int* arr, int size, int search_number)
{
	int i = 0;
	int index = 0;
	
	for(i=size-1;i>=0;i--)
	{
		if(arr[i] == search_number)
		{
			index = i;
			break;
		}
	}
	
	return index;
}