/*
Problem statemnet: Accept N numbers from the user and return the difference between the sum of even numbers and odd numbers
*/

//header file inclusion
#include<stdio.h>
#include<stdlib.h>

//function declaration
void AcceptNumbers(int*,int);
void DisplayNumbers(int*,int);
int FindDifference(int*,int);

//entry point function
int main(void)
{
	//local variables for array size and array address
	int size = 0;
	int* arr = NULL;
	int result = 0;
	
	//Accept the size from the user
	printf("Enter number of elements: ");
	scanf("%d",&size);
	
	//check for invalid size
	if(size<=0)
	{
		printf("Invalid input, not a positive non zero number\n");
		exit(-1);
	}
	
	//dynamically allocate memory for these many elements
	arr = (int*)malloc(size * sizeof(int));
	
	//check for memory allocation failure
	if(arr == NULL)
	{
		printf("Memory allocation failure\n");
		exit(-1);
	}
	
	//Accept the elements from the user
	AcceptNumbers(arr,size);
	
	//Display the entered elements
	DisplayNumbers(arr,size);
	
	//Find difference of sum of even and sum of odd numbers
	result = FindDifference(arr,size);
	printf("Difference between the sum of even and sum of odd elements is : %d\n",result);
	
	exit(0);
}

//definition of AcceptNumbers() function
void AcceptNumbers(int* arr, int size)
{
	int i = 0;
	
	printf("Enter %d elements: \n",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
}

//definition of DisplayNumbers() function
void DisplayNumbers(int* arr, int size)
{
	int i = 0;
	printf("The entered elements are: \n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//definition of function to find difference of sum of even and odd numbers
int FindDifference(int* arr, int size)
{
	int i = 0;
	int sum_of_even = 0;
	int sum_of_odd = 0;
	
	for(i=0;i<size;i++)
	{
		if(arr[i]%2 == 0)
		{
			sum_of_even = sum_of_even + arr[i];
		}
		else
		{
			sum_of_odd = sum_of_odd + arr[i];
		}
	}
	
	return (sum_of_even - sum_of_odd);
}