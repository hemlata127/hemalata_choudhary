/*
Problem Statement: Accept N numbers from the user. Accept another number from the user and return the index of first occurance of this number in the array
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declarations
void AcceptElements(int*,int);
void DisplayElements(int*,int);
int ReturnIndexOfFirstOccurance(int*,int,int);

//entry point function - program execution begins here
int main(void)
{
	int size = 0;
	int* arr = NULL;
	int search_number = 0;
	int index = 0;
	
	//Accept size of array
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	//check for invalid size
	if(size<=0)
	{
		printf("Invalid array size\n");
		exit(-1);
	}
	
	//allocate memory dynamically for entered number of elements
	arr = (int*)malloc(size*sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//Accept the elements
	AcceptElements(arr,size);
	
	//Display the accepted elements
	DisplayElements(arr,size);
	
	//Accept search number
	printf("Enter number to search: ");
	scanf("%d",&search_number);
	
	//Find index of first occurance of the search_number in the array
	index = ReturnIndexOfFirstOccurance(arr,size,search_number);
	
	//display output
	printf("%d occurs first at %d index\n",search_number,index);
	
	exit(-1);
}

//function definitions
void AcceptElements(int* arr, int size)
{
	int i = 0;
	
	printf("Enter %d elements: ",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
}

void DisplayElements(int* arr,int size)
{
	int i = 0;
	
	printf("Entered elements are: \n");
	
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int ReturnIndexOfFirstOccurance(int* arr,int size,int search_number)
{
	int i = 0;
	int required_index = 0;
	for(i=0;i<size;i++)
	{
		if(arr[i] == search_number)
		{
			required_index = i;
			break;
		}
	}
	
	return required_index;
}