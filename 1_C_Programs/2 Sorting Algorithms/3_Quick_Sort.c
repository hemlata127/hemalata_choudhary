#include<stdio.h>
#include<stdlib.h>

int* create_array(int size);
void display_array(int* arr, int size, char* msg);
void sort_array(int* arr, int size);
void quick_sort(int* arr, int p, int r);
int partition(int* arr, int p, int q);
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
    //call quick_sort function to sort the entire the entire array - from index 0 to size-1
    quick_sort(arr, 0, size-1);
}

void quick_sort(int* arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

//function to move the pivot element - last element in the array to its final position
int partition(int* arr, int p, int r)
{
    //consider the pivot element as last element in the array
    int pivot = arr[r];
    //tracker to find the correct index of pivot element
    int i = p - 1;
    //temp variable to use for swapping
    int temp;
    //variable to track the array movement - move through the array
    int j;
    //navigate through the entire array to find the correct position of pivot element
    for(j = p;j<r;j++)
    {
        if(arr[j] < pivot)
        {
            i = i+1;
            //swap
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    //final swap
    i = i+1;
    temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;

    return i;
}

void destroy_array(int** arr)
{
    free(*arr);
    *arr = NULL;
}
