#ifndef _SORTING_ALGORITHMS_H
#define _SORTING_ALGORITHM_H

//header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1

//function declarations
void* xcalloc(size_t nr_of_elements, size_t size_per_element);
int* create_array(int size);
void display_array(int* arr, int size, const char* msg);
void insert_at_sort_position(int* arr, int size);
void insertion_sort(int* arr, int size);
void merge(int* arr, int p, int q, int r);
void merge_sort(int* arr, int p, int r);
void quick_sort(int* arr, int p, int r);
int partition(int* arr, int p, int r);
void destroy_array(int** arr);

#endif
