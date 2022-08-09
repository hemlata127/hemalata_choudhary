/*
Problem Statement: Accept N numbers from user. Accept another number and check if this number is presnt in the list of entered numbers
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>
//macro definition
#define TRUE 1
#define FALSE 0
//type def
typedef int BOOL;

//function declarations
void AcceptElements(int*,int);
void DisplayElements(int*,int);
BOOL CheckElement(int*,int,int);

//entry point function - program execution begins here
int main(void)
{
	int size = 0;
	int* arr = NULL;
	BOOL result = FALSE;
	int search_number = 0;
	
	//accept size of array
	printf("Enter number of elements: ");
	scanf("%d",&size);
	
	//check for invalid array size
	if(size<=0)
	{
		printf("Invalid array size, not a positive non zero value\n");
		exit(-1);
	}
	
	//allocate memory dynamically for entered number of elements
	arr = (int*)malloc(size * sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//accept the array elements
	AcceptElements(arr,size);
	
	//display the entered array elements
	DisplayElements(arr,size);
	
	//accept the element to search
	printf("Enter number to search: ");
	scanf("%d",&search_number);
	
	//check if the number is present in the array
	result = CheckElement(arr,size,search_number);
	
	//display the search result
	if(result == TRUE)
	{
		printf("%d is present\n",search_number);
	}
	else
	{
		printf("%d is not present\n",search_number);
	}
	
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

BOOL CheckElement(int* arr, int size, int search_number)
{
	BOOL result = FALSE;
	int i = 0;
	int j = 0;
	
	for(i=0,j=size-1;i<=j;i++,j--)
	{
		if(i==j)
		{
			if(arr[i] == search_number)
			{
				result = TRUE;
				break;
			}
		}
		else if((arr[i] == search_number)||(arr[j] == search_number))
		{
			result = TRUE;
			break;
		}
	}
	
	return result;
}