#ifndef _SINGLY_CIRCULAR_LINKED_LIST_H
#define _SINGLY_CIRCULAR_LINKED_LIST_H

//header file
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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
};

//typedefs
typedef int bool_t;
typedef int len_t;
typedef int status_t;
typedef int data_t;
typedef struct node node_t;
typedef struct node list_t;

//interface function declarations
//auxillary functions - not called by the client
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
static node_t* get_new_node(data_t new_data);
static void get_node_and_prev(list_t* p_list, data_t s_data, node_t** pp_node, node_t** pp_prev_node);
static get_last_node(list_t* p_list, node_t** pp_last_node);
static get_last_node_and_prev(list_t* p_list, node_t** pp_last_node, node_t** pp_prev_node);
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node, node_t* p_delete_node_prev);
static void get_node(list_t* p_list, data_t e_data, node_t** pp_e_node);
static void quick_sort(int* arr, int p, int r);
static int partition(int* arr, int p, int r);

//misc functions
status_t create_list(list_t** pp_list);
status_t find_length(list_t* p_list, len_t* p_len);
status_t show_list(list_t* p_list, const char* msg);
bool_t is_list_empty(list_t* p_list);
bool_t search_data(list_t* p_list, data_t s_data);
status_t destroy_list(list_t** pp_list);
status_t to_array(list_t* p_list, int** pp_arr, int* pp_size);
status_t sort_array(int* arr, int size);
status_t to_list(int* arr, int size, list_t** pp_list);
status_t destroy_array(int** pp_arr);

//functions related to insert data in list
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_before(list_t* p_list, data_t new_data, data_t e_data);
status_t insert_after(list_t* p_list, data_t new_data, data_t e_data);

//functions related to read list data
status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

//functions related to delete list data
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

//concat functions
status_t concat_lists_imm(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_concat);
status_t concat_lists_m(list_t* p_list_1, list_t** pp_list_2);

//merge function
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_merge);

//reverse function
status_t get_reversed_list(list_t* p_list, list_t** pp_list_reverse);
status_t reverse_list(list_t* p_list);

#endif
