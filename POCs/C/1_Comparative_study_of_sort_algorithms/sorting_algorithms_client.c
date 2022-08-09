#include "sorting_algorithms.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        puts("Incorrect command usage");
        printf("Use as: %s array_size",argv[0]);
        exit(EXIT_FAILURE);
    }

    clock_t start;
    clock_t end;
    double cpu_time_1, cpu_time_2, cpu_time_3;

    int* arr = NULL;
    int size = atoi(argv[1]);
    if(size <= 0)
    {
        puts("Incorrect array size");
        exit(EXIT_FAILURE);
    }

    //insertion sort
    arr = create_array(size);
    display_array(arr, size, "ORIGINAL ARRAY");
    start = clock();
    insertion_sort(arr, size);
    end = clock();
    display_array(arr, size, "ARRAY SORTED BY INSERTION SORT ALGORITHM");
    cpu_time_1 = (double)(end - start);
    printf("Time taken by insertion sort algorithm is %lf\n",(double)(end - start));

    //merge sort
    arr = create_array(size);
    display_array(arr, size, "ORIGINAL ARRAY");
    start = clock();
    merge_sort(arr, 0, size-1);
    end = clock();
    cpu_time_2 = (double)(end - start);
    display_array(arr, size, "ARRAY SORTED BY INSERTION SORT ALGORITHM");

    //quick sort
    arr = create_array(size);
    display_array(arr, size, "ORIGINAL ARRAY");
    start = clock();
    quick_sort(arr, 0, size-1);
    end = clock();
    cpu_time_3 = (double)(end - start);
    display_array(arr, size, "ARRAY SORTED BY INSERTION SORT ALGORITHM");
    printf("Time taken by insertion sort algorithm is %lf\n",cpu_time_1);
    printf("Time taken by merge sort algorithm is %lf\n",cpu_time_2);
    printf("Time taken by quick sort algorithm is %lf\n",cpu_time_3);

    exit(EXIT_SUCCESS);
}