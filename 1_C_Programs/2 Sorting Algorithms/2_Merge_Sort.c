//include the required header files
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1

//function declarations
int* create_array(int size);
void display_array(int* arr, int size, char* msg);
void sort_array(int* arr, int size);
void merge_sort(int* arr, int p, int r);
void merge(int* arr, int p, int q, int r);
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
    //call merge sort to sort the entire array - from index 0 to index size - 1
    merge_sort(arr, 0, size-1);
}

void merge_sort(int* arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(int* arr, int p, int q, int r)
{
    //calculate the size of the two sub arrays
    int N1 = q - p + 1;
    int N2 = r - q;

    //allocate memory for the two sub arrays
    int* arr1 = (int*) malloc(N1 * sizeof(int));
    if(arr1 == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int* arr2 = (int*) malloc(N2 * sizeof(int));
    if(arr2 == NULL)
    {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    //add elements to the two sub arrays
    int i;
    for(i = 0;i<N1;i++)
        arr1[i] = arr[p+i];
    for(i = 0;i<N2;i++)
        arr2[i] = arr[q + 1 + i];

    //merge the two sub arrays
    i = 0;
    int j = 0, k = 0;
    //i is the tracker for arr1, j is the tracker for arr2 and k is the tracker for arr

    while(TRUE)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[p+k] = arr1[i];
            k = k+1;
            i = i+1;
            //if arr1 elements finish - add the remaining elements of arr2
            if(i == N1)
            {
                while(j<N2)
                {
                    arr[p+k] = arr2[j];
                    k = k+1;
                    j = j+1;
                }
                break;
            }
        }
        else
        {
            arr[p+k] = arr2[j];
            k = k+1;
            j = j+1;
            if(j == N2)
            {
                while(i<N1)
                {
                    arr[p+k] = arr1[i];
                    k = k+1;
                    i = i+1;
                }
                break;
            }
        }
    }

    //free the two sub arrays
    free(arr1);
    arr1 = NULL;
    free(arr2);
    arr2 = NULL;
}

void destroy_array(int** arr)
{
    free(*arr);
    *arr = NULL;
}
