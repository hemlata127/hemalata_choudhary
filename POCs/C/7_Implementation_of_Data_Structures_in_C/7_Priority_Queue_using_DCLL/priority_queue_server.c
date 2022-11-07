#include "priority_queue.h"

//interface function declarations
//auxillary functions
static void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void* p = calloc(nr_of_elements, size_per_element);
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }
    return p;
}

node_t* get_new_node(data_t new_data)
{
    node_t* p_new_node = (node_t*) xcalloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;

    return p_new_node;
}

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

void generic_delete(node_t* p_delete_node)
{
    p_delete_node->next->prev = p_delete_node->prev;
    p_delete_node->prev->next = p_delete_node->next;
    free(p_delete_node);
    p_delete_node = NULL;
}

//misc functions
queue_t* create_queue()
{
    queue_t* p_queue = get_new_node(-1);
    p_queue->next = p_queue;
    p_queue->prev = p_queue;
    return p_queue;
}

status_t priority_enqueue(queue_t* p_queue, data_t new_data)
{
    return insert_start(p_queue, new_data);
}

status_t priority_dequeue_min(queue_t* p_queue, data_t* p_data)
{
    int current_min_data;
    node_t* p_run = NULL;
    node_t* p_node_min_data = NULL;

    if(is_priority_queue_empty(p_queue) == TRUE)
        return QUEUE_EMPTY;

    p_node_min_data = p_queue->next;
    current_min_data = p_queue->next->data;
    for(p_run = p_queue->next;p_run != p_queue;p_run = p_run->next)
    {
        if(p_run->data < current_min_data)
        {
            current_min_data = p_run->data;
            p_node_min_data = p_run;
        }
    }

    *p_data = current_min_data;
    generic_delete(p_node_min_data);
    
    return SUCCESS;
}

status_t insert_start(queue_t* p_queue, data_t new_data)
{
    generic_insert(p_queue, get_new_node(new_data), p_queue->next);
    return SUCCESS;
}

status_t remove_end(queue_t* p_queue)
{
    if(is_priority_queue_empty(p_queue) == TRUE)
        return QUEUE_EMPTY;
    generic_delete(p_queue->prev);
    return SUCCESS;
}

void show_priority_queue(queue_t* p_queue, const char* msg)
{
    if(msg)
        puts(msg);

    node_t* p_run;
    printf("[START]<->");
    for(p_run = p_queue->next;p_run != p_queue;p_run = p_run->next)
        printf("[%d]<->",p_run->data);
    puts("[END]");
}

bool is_priority_queue_empty(queue_t* p_queue)
{
    return(p_queue->next == p_queue && p_queue->prev == p_queue);
}

void destroy_priority_queue(queue_t** pp_queue)
{
    queue_t* p_queue = *pp_queue;
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    p_run = p_queue->next;
    while(p_run != p_queue)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_queue);
    p_queue = NULL;

    *pp_queue = NULL;
}
