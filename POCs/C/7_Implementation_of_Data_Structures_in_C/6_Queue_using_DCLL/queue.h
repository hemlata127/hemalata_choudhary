#ifndef _QUEUE_H
#define _QUEUE_H

//header file
#include "list.h"

//symbolic constant
#define QUEUE_EMPTY LIST_EMPTY

//typedef
typedef list_t queue_t;

//interface function declarations
queue_t* create_queue();
status_t enqueue(queue_t* p_queue, data_t new_data);
status_t dequeue(queue_t* p_queue, data_t* p_data);
status_t peek(queue_t* p_queue, data_t* p_data);
bool is_queue_empty(queue_t* p_queue);
void show_queue(queue_t* p_queue, const char* msg);
void destroy_queue(queue_t** pp_queue);

#endif
