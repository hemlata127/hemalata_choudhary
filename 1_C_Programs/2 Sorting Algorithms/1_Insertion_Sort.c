#include<stdio.h>
#include<stdlib.h>

int* create_array(int size);
void display_array(int* arr, int size, char* msg);
void sort_array(int* arr, int size);
void insertion_sort(int* arr, int size);
void insert_at_sort_position(int* arr, int size);
void destroy_array(int** arr);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("USAGE ERROR: USE AS %s number_of_elements\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    //store the array size in a variable
    int size = atoi(argv[1]);
    if(size <= 0)
    {
        puts("Invalid array size");
        exit(EXIT_FAILURE);
    }

    //create an array
    int* arr = create_array(size);
    //display the original - unsorted array
    display_array(arr, size, "ORIGINAL ARRAY");
    //sort the array
    sort_array(arr, size);
    //display the sorted array
    display_array(arr, size, "SORTED ARRAY");
    //destroy the array
    destroy_array(&arr);

    exit(EXIT_SUCCESS);
}

int* create_array(int size)
{
    int* arr = (int*) malloc(size * sizeof(int));
    if(arr == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0;i<size;i++)
        arr[i] = rand();

    return arr;
}

void display_array(int* arr, int size, char* msg)
{
    if(msg)
        puts(msg);

    int i;
    for(i = 0;i<size;i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

void sort_array(int* arr, int size)
{
    insertion_sort(arr, size);
}

void insertion_sort(int* arr, int size)
{
    int i;
    for(i = 2;i<=size;i++)
        insert_at_sort_position(arr, i);
}

void insert_at_sort_position(int* arr, int size)
{
    int key = arr[size-1];
    int i;
    for(i = size-2;i>=0 && arr[i]>key;i--)
        arr[i+1] = arr[i];
    
    arr[i+1] = key;
}

void destroy_array(int** arr)
{
    free(*arr);
    *arr = NULL;
}
