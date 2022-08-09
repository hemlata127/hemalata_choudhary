#ifndef _STACK_H
#define _STACK_H

//header file
#include "list.h"

//symbolic constants
#define STACK_EMPTY LIST_EMPTY

//typedefs
typedef list_t stack_t;

//interface functions declarations
stack_t* create_stack(void);
status_t push(stack_t* p_stack, data_t new_data);
status_t pop(stack_t* p_stack, data_t* p_pop_data);
status_t top(stack_t* p_stack, data_t* p_top_data);
void show_stack(stack_t* p_stack, const char* msg);
bool is_stack_empty(stack_t* p_stack);
void destroy_stack(stack_t** pp_stack);

#endif
