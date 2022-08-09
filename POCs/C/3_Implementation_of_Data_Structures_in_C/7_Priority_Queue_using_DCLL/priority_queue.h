#ifndef QUEUE_H_
#define QUEUE_H_

//header file
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define QUEUE_EMPTY 2
#define QUEUE_DATA_NOT_FOUND 3

//node declaration
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

//typedefs
typedef int bool;
typedef int len_t;
typedef int data_t;
typedef int status_t;
typedef struct node node_t;
typedef struct node queue_t;

//interface function declarations
//auxillary functions
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
node_t* get_new_node(data_t new_data);
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
void generic_delete(node_t* p_delete_node);

//misc functions
queue_t* create_queue();
status_t priority_enqueue(queue_t* p_queue, data_t new_data);
status_t priority_dequeue_min(queue_t* p_queue, data_t* p_data);
status_t insert_start();
status_t remove_end();
void show_priority_queue(queue_t* p_queue, const char* msg);
bool is_priority_queue_empty(queue_t* p_queue);
void destroy_priority_queue(queue_t** pp_queue);

#endif