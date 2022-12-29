#ifndef _LIST_H
#define _LIST_H

//header files
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
    struct node* prev;
};

//typedefs
typedef int bool;
typedef int data_t;
typedef struct node list_t;
typedef struct node node_t;
typedef int status_t;
typedef int len_t;

//interface function declarations
//auxillary functions - the functions which are not called by the client
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
static node_t* get_new_node(data_t new_data);
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);
static node_t* find_node_data(list_t* p_list, data_t find_data);
static void quick_sort(int* arr, int p, int r);
static int partition(int* arr, int p, int r);

//misc functions
list_t* create_list(void);
len_t get_length(list_t* p_list);
void show_list(list_t* p_list, const char* msg);
bool search_data(list_t* p_list, data_t search_data);
bool is_list_empty(list_t* p_list);
status_t destroy_list(list_t** pp_list);
int* to_array(list_t* p_list, int size);
list_t* to_list(int* arr, int size);

//functions related to insert new node
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_before(list_t* p_list, data_t new_data, data_t e_data);
status_t insert_after(list_t* p_list, data_t new_data, data_t e_data);

//functions related to delete a node
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t delete_data);

//functions related to reading the node data
status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

//merge function
list_t* merge_lists(list_t* p_list_1, list_t* p_list_2);

//concat functions
list_t* concat_lists_imm(list_t* p_list_1, list_t* p_list_2);
status_t concat_lists_m(list_t* p_list_1, list_t** pp_list_2);

//reverse functions
list_t* get_reversed_list(list_t* p_list);
status_t reverse_list(list_t* p_list);

//sort functions
list_t* sort_list(list_t* p_list);
void sort_array(int* arr, int size);

#endif
