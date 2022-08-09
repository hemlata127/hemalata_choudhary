#include "doubly_circular_linked_list.h"

//interface function definitions
//auxillary functions - the functions which are not called by the client
static void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void *p = NULL;
    p = calloc(nr_of_elements, size_per_element);
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }
    return p;
}

static node_t* get_new_node(data_t new_data)
{
    node_t* p_new_node = (node_t*) xcalloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;
    return (p_new_node);
}

static status_t generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
    return SUCCESS;
}

static status_t generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;
    return SUCCESS;
}

static node_t* get_node(list_t* p_list, data_t find_data)
{
    node_t* p_run = NULL;
    for(p_run = p_list->next;p_run != p_list;p_run = p_run->next)
    {
        if(p_run->data == find_data)
        {
            return (p_run);
        }
    }

    return NULL;
}
//quick sort algorithm
static void quick_sort(int* arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

//function used by quick sort algorithm to find the final position of last element
static int partition(int* arr, int p, int r)
{
    int pivot = arr[r];
    int i = p-1;
    int j, temp;
    for(j = p;j<r;j++)
    {
        if(arr[j] < pivot)
        {
            i = i+1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
    }
    i = i+1;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    return i;
}
//==========================================================================
//misc functions
status_t create_list(list_t** pp_list)
{
    list_t* p_list = get_new_node(-1);
    p_list->next = p_list;
    p_list->prev = p_list;
    *pp_list = p_list;
    return SUCCESS;
}

status_t find_length(list_t* p_list, len_t* p_len)
{
    len_t len = 0;
    node_t* p_run = NULL;
    for(p_run = p_list->next;p_run != p_list;p_run = p_run->next)
        len = len+1;
    *p_len = len;
    return SUCCESS;
}

status_t show_list(list_t* p_list, const char* msg)
{
    if(msg)
        puts(msg);
    node_t* p_run = NULL;
    printf("[START]<->");
    for(p_run = p_list->next;p_run != p_list;p_run = p_run->next)
        printf("[%d]<->",p_run->data);
    puts("[END]");
    return SUCCESS;
}

bool_t search_data(list_t* p_list, data_t s_data)
{
    node_t* p_search_node = get_node(p_list, s_data);
    if(p_search_node == NULL)
        return FALSE;
    else
        return TRUE;
}

bool_t is_list_empty(list_t* p_list)
{
    return (p_list->next == p_list && p_list->prev == p_list);
}

status_t destroy_list(list_t** pp_list)
{
    list_t* p_list = *pp_list;
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;
    
    p_run = p_list->next;
    while(p_run != p_list)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_list);
    p_list = NULL;

    *pp_list = NULL;
    return SUCCESS;
}

status_t to_array(list_t* p_list, int** pp_arr, int* size)
{
    len_t len = 0;
    find_length(p_list, &len);
    int* arr = (int*) xcalloc(len, sizeof(int));
    int i;
    for(i = 0; i<len; ++i)
        pop_start(p_list, &arr[i]);
    *pp_arr = arr;
    *size = len;
    return SUCCESS;
}

status_t to_list(int* arr, int size, list_t** pp_list)
{
    list_t* p_list = NULL;
    create_list(&p_list);
    int i;
    for(i = 0; i<size; i++)
        insert_end(p_list, arr[i]);
    *pp_list = p_list;
    return SUCCESS;
}

status_t sort_array(int* arr, int size)
{
    quick_sort(arr, 0, size-1);
    return SUCCESS;
}

status_t destroy_array(int** pp_arr)
{
    free(*pp_arr);
    *pp_arr = NULL;
    return SUCCESS;
}

//==========================================================================
//functions related to insert new node
status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_new_node(new_data), p_list->next);
    return SUCCESS;
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_new_node(new_data), p_list);
    return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t new_data, data_t e_data)
{
    node_t* p_e_node = get_node(p_list, e_data);
    if(p_e_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    generic_insert(p_e_node->prev, get_new_node(new_data), p_e_node);
    return SUCCESS; 
}

status_t insert_after(list_t* p_list, data_t new_data, data_t e_data)
{
    node_t* p_e_node = get_node(p_list, e_data);
    if(p_e_node == NULL)
        return (LIST_DATA_NOT_FOUND);
    generic_insert(p_e_node, get_new_node(new_data), p_e_node->next);
    return SUCCESS;
}

//=============================================================================
//functions related to delete a node
status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);
    generic_delete(p_list->next);
    return SUCCESS;
}

status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);
    generic_delete(p_list->prev);
    return SUCCESS;
}

status_t remove_data(list_t* p_list, data_t d_data)
{
    node_t* p_remove_node = get_node(p_list, d_data);
    if(p_remove_node == NULL)
        return (LIST_DATA_NOT_FOUND);
    generic_delete(p_remove_node);
    return SUCCESS;
}

//=============================================================================
//functions related to reading the node data
status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    *p_start_data = p_list->next->data;
    return SUCCESS;
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    *p_end_data = p_list->prev->data;
    return SUCCESS;
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    *p_start_data = p_list->next->data;
    generic_delete(p_list->next);
    return SUCCESS;
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    *p_end_data = p_list->prev->data;
    generic_delete(p_list->prev);
    return SUCCESS;
}

//=============================================================================
//merge function
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_merge)
{
    list_t* p_list_merge = NULL;
    create_list(&p_list_merge);

    node_t* p_run_1 = p_list_1->next;
    node_t* p_run_2 = p_list_2->next;

    while(TRUE)
    {
        if(p_run_1 == p_list_1)
        {
            while(p_run_2 != p_list_2)
            {
                insert_end(p_list_merge, p_run_2->data);
                p_run_2 = p_run_2->next;
            }
            break;
        }

        if(p_run_2 == p_list_2)
        {
            while(p_run_1 != p_list_1)
            {
                insert_end(p_list_merge, p_run_1->data);
                p_run_1 = p_run_1->next;
            }
            break;
        }

        if(p_run_1->data <= p_run_2->data)
        {
            insert_end(p_list_merge, p_run_1->data);
            p_run_1 = p_run_1->next;
        }
        else
        {
            insert_end(p_list_merge, p_run_2->data);
            p_run_2 = p_run_2->next;
        }
    }
    *pp_list_merge = p_list_merge;
    return SUCCESS;
}

//=============================================================================
//concat functions
status_t get_concatenated_list(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_concat)
{
    list_t* p_list_concat = NULL;
    create_list(&p_list_concat);

    node_t* p_run = NULL;
    for(p_run = p_list_1->next;p_run != p_list_1; p_run = p_run->next)
        insert_end(p_list_concat, p_run->data);
    for(p_run = p_list_2->next;p_run != p_list_2; p_run = p_run->next)
        insert_end(p_list_concat, p_run->data);
    
    *pp_list_concat = p_list_concat;
    return SUCCESS;
}

status_t append_list(list_t* p_list_1, list_t** pp_list_2)
{
    list_t* p_list_2 = *pp_list_2;

    if(is_list_empty(p_list_2) == TRUE)
    {
        free(p_list_2);
        p_list_2 = NULL;
        *pp_list_2 = NULL;
        return SUCCESS;
    }
    
    p_list_1->prev->next = p_list_2->next;
    p_list_2->next->prev = p_list_1->prev;
    p_list_1->prev = p_list_2->prev;
    p_list_2->prev->next = p_list_1;

    free(p_list_2);
    p_list_2 = NULL;
    *pp_list_2 = NULL;
    
    return SUCCESS;
}

//=============================================================================
//reverse functions
status_t get_reversed_list(list_t* p_list, list_t** pp_list_reverse)
{
    list_t* p_list_reverse = NULL;
    create_list(&p_list_reverse);

    node_t* p_run = NULL;
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        insert_start(p_list_reverse, p_run->data);

    *pp_list_reverse = p_list_reverse;
    return SUCCESS;
}

status_t reverse_list(list_t* p_list)
{
    node_t* p_original_prev = NULL;
    node_t* p_current_last = NULL;
    node_t* p_run = NULL;
    node_t* p_run_prev = NULL;

    p_original_prev = p_list->prev;
    p_current_last = p_original_prev;
    p_run = p_original_prev->prev;

    while(p_run != p_list)
    {
        p_run_prev = p_run->prev;
        p_current_last->next = p_run;
        p_run->prev = p_current_last;

        p_current_last = p_run;
        p_run = p_run_prev;
    }

    p_current_last->next = p_list;
    p_list->prev = p_current_last;    
    p_list->next = p_original_prev;
    p_original_prev->prev = p_list;

    return SUCCESS;
}
