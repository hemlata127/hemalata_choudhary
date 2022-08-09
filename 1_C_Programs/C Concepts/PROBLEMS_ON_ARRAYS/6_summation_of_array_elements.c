#include<stdio.h>
#include<stdlib.h>

int* create_array(int size);
void display_array(int* arr, int size, const char* msg);
long long int add_array_elements(int* arr, int size);
void destroy_array(int** arr);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        puts("MEMORY ALLOCATION FAILED");
        printf("USE AS: %s array_size", argv[0]);
        exit(EXIT_FAILURE);
    }

    int size = atoi(argv[1]);
    if(size <= 0)
    {
        puts("INVALID ARRAY SIZE");
        exit(EXIT_FAILURE);
    }

    int* arr = create_array(size);
    display_array(arr, size, "ORIGINAL ARRAY");
    long long int sum = add_array_elements(arr, size);
    printf("Summation of array elements: %lld\n",sum);

    destroy_array(&arr);

    exit(EXIT_SUCCESS);
}

int* create_array(int size)
{
    int* arr = (int*)malloc(size * sizeof(int));
    if(arr == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0;i<size;++i)
        arr[i] = (i+1)*10;

    return arr;
}

void display_array(int* arr, int size, const char* msg)
{
    if(msg)
        puts(msg);

    int i;
    for(i = 0;i<size;++i)
        printf("arr[%d] = %d\n",i,arr[i]);
}

long long int add_array_elements(int* arr, int size)
{
    long long int sum = 0;
    int i;
    for(i = 0;i<size;i++)
        sum = sum + arr[i];

    return sum;
}

void destroy_array(int** arr)
{
    free(*arr);
    *arr = NULL;
}
