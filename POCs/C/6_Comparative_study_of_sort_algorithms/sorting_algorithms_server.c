#include "sorting_algorithms.h"

void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void* p = calloc(nr_of_elements, size_per_element);
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }
    return p;
}

int* create_array(int size)
{
    int* arr = (int*)xcalloc(size, sizeof(int));

    int i;
    for(i = 0; i<size; ++i)
        arr[i] = rand();
    
    return arr;
}

void display_array(int* arr, int size, const char* msg)
{
    if(msg)
        puts(msg);
    int i;
    for(i = 0; i<size; ++i)
        printf("arr[%d] == %d\n",i, arr[i]);
}

void insert_at_sort_position(int* arr, int size)
{
    int key = arr[size-1];
    int i;
    
    for(i = size-2; i>=0 && arr[i] > key; --i)
        arr[i+1] = arr[i];

    arr[i+1] = key;
}

void insertion_sort(int* arr, int size)
{
    int i;
    for(i = 2; i <= size; ++i)
        insert_at_sort_position(arr, i);
}

void merge(int* arr, int p, int q, int r)
{
    int N1 = q - p + 1;
    int N2 = r - q;

    int* arr1 = (int*)xcalloc(N1, sizeof(int));
    int* arr2 = (int*)xcalloc(N2, sizeof(int));

    int i;
    for(i = 0; i<N1; ++i)
        arr1[i] = arr[p+i];
    for(i = 0; i<N2; ++i)
        arr2[i] = arr[q+1+i];

    int j = 0, k = 0;
    i = 0;

    while(TRUE)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[p+k] = arr1[i];
            k = k+1;
            i = i+1;
            if(i == N1)
            {
                while(j < N2)
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
                while(i < N1)
                {
                    arr[p+k] = arr1[i];
                    k = k+1;
                    i = i+1;
                }
                break;
            }
        }
    }

    free(arr1);
    arr1 = NULL;
    free(arr2);
    arr2 = NULL;
}

void merge_sort(int* arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void quick_sort(int* arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

int partition(int* arr, int p, int r)
{
    int pivot = arr[r];
    int i = p-1;
    int j, temp;
    for(j = p; j< r; ++j)
    {
        if(arr[j] < pivot)
        {
            i = i+1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
        i = i+1;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        return i;
}

void destroy_array(int** arr)
{
    free(*arr);
    arr = NULL;
}
