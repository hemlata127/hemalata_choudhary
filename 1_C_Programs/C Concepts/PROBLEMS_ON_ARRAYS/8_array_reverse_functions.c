#include<stdio.h>
#include<stdlib.h>

int* create_array(int size);
void display_array(int* arr, int size, const char* msg);
void get_reversed_array(int* src_arr, int src_size, int** dest_arr, int* dest_size);
void reverse_array(int* arr, int size);
void destroy_array(int** arr);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        puts("INCORRECT COMMAND USAGE");
        printf("USE AS: %s array_size\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int src_size = atoi(argv[1]);
    if(src_size <= 0)
    {
        puts("INCORRECT ARRAY SIZE");
        exit(EXIT_FAILURE);
    }

    int* src_arr = create_array(src_size);
    display_array(src_arr, src_size, "ORIGINAL ARRAY");
    int* dest_arr = NULL;
    int dest_size = 0;

    get_reversed_array(src_arr, src_size, &dest_arr, &dest_size);
    display_array(dest_arr, dest_size, "REVERSED ARRAY");

    reverse_array(src_arr, src_size);
    display_array(src_arr, src_size, "INPLACE REVERSED ARRAY");

    exit(EXIT_SUCCESS);
}

int* create_array(int size)
{
    int* arr = (int*) malloc(size * sizeof(int));
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

void get_reversed_array(int* src_arr, int src_size, int** dest_arr, int* dest_size)
{
    int* p_arr = (int*) malloc(src_size * sizeof(int));
    if(p_arr == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0;i<src_size;++i)
        p_arr[i] = src_arr[src_size-1-i];

    *dest_arr = p_arr;
    *dest_size = src_size;
}

void reverse_array(int* arr, int size)
{
    int i, temp;
    for(i = 0;i<size/2;++i)
    {
        temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

void destroy_array(int** arr)
{
    free(*arr);
    *arr = NULL;
}
