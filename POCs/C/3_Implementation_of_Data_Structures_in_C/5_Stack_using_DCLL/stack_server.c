#include "stack.h"

//interface functions declarations
stack_t* create_stack(void)
{
    return create_list();
}

status_t push(stack_t* p_stack, data_t new_data)
{
    return insert_end(p_stack, new_data);
}

status_t pop(stack_t* p_stack, data_t* p_pop_data)
{
    return pop_end(p_stack, p_pop_data);
}

status_t top(stack_t* p_stack, data_t* p_top_data)
{
    return get_end(p_stack, p_top_data);
}

void show_stack(stack_t* p_stack, const char* msg)
{
    show_list(p_stack, msg);
}

bool is_stack_empty(stack_t* p_stack)
{
    return is_list_empty(p_stack);
}

void destroy_stack(stack_t** pp_stack)
{
    destroy_list(pp_stack);
}
