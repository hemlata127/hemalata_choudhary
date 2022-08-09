#ifndef _DOUBLY_LINEAR_LINKED_LIST_H
#define _DOUBLY_LINEAR_LINKED_LIST_H

//header files
#include<stdio.h>
#include<stdlib.h>

//symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define LIST_EMPTY 2
#define LIST_DATA_NOT_FOUND 3

//node declaration
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

//typedefs
typedef int bool_t;
typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef struct node list_t;

//interface function declarations
//auxillary functions - not called by client
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
static node_t* get_new_node(data_t new_data);
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);
static node_t* get_node(list_t* p_list, data_t find_data);
static bool_t is_list_empty(list_t* p_list);
static void quick_sort(int* arr, int p, int r);
static int partition(int* arr, int p, int r);

//misc functions
status_t create_list(list_t** pp_list);
status_t find_length(list_t* p_list, len_t* p_len);
status_t show_list(list_t* p_list, const char* msg);
bool_t search_data(list_t* p_list, data_t search_data);
status_t to_array(list_t* p_list, int** pp_arr, int* p_size);
status_t sort_array(int* arr, int size);
status_t to_list(int* arr, int size, list_t** pp_list);
status_t destroy_list(list_t** pp_list);
status_t destroy_array(int** pp_arr);

//functions related to insert new node in linked list
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_before(list_t* p_list, data_t new_data, data_t e_data);
status_t insert_after(list_t* p_list, data_t new_data, data_t e_data);

//functions related to read node data
status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

//functions related to delete node in linked list
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t remove_data);

//concat functions
status_t concat_lists_imm(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_concat);
status_t concat_lists_m(list_t* p_list_1, list_t** pp_list_2);

//merge function
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_merge);

//reverse functions
status_t get_reversed_list(list_t* p_list, list_t** pp_list_reverse);
status_t reverse_list(list_t* p_list);

#endif