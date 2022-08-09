#include<stdio.h>
#include<stdlib.h>

int* create_array(int size);
void display_array(int* arr, int size, const char* msg);
void sort_array(int* arr, int size);
void destroy_array(int** arr);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        puts("INCORRECT COMMAND USAGE");
        printf("USE AS: %s array_size\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int size = atoi(argv[1]);
    if(size <= 0)
    {
        puts("INCORRECT ARRAY SIZE");
        exit(EXIT_FAILURE);
    }

    int* arr = create_array(size);
    display_array(arr, size, "ORIGINAL ARRAY");
    sort_array(arr, size);
    display_array(arr, size, "SORTED ARRAY");
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
    for(i = 0;i<size;i++)
        arr[i] = rand();

    return arr;
}

void display_array(int* arr, int size, const char* msg)
{
    if(msg)
        puts(msg);

    int i;
    for(i = 0;i<size;i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

void sort_array(int* arr, int size)
{

}

void destroy_array(int** arr)
{
    free(*arr);
    *arr = NULL;
}
