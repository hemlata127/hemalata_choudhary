#include "singly_circular_linked_list.h"

//interface function definitions
//auxillary functions - not called by the client
static void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void* p = NULL;
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
    node_t* p_new_node = (node_t*)xcalloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    return p_new_node;
}

static void get_node_and_prev(list_t* p_list, data_t s_data, node_t** pp_node, node_t** pp_prev_node)
{    
    node_t* p_run = NULL;
    node_t* p_run_prev = NULL;

    p_run = p_list->next;
    p_run_prev = p_list;

    while(p_run != p_list)
    {
        if(p_run->data == s_data)
        {
            *pp_node = p_run;
            *pp_prev_node = p_run_prev;
            return;
        }
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    *pp_node = NULL;
    *pp_prev_node = NULL;
}

static get_last_node(list_t* p_list, node_t** pp_last_node)
{
    node_t* p_run = p_list;
    while(p_run->next != p_list)
    {
        p_run = p_run->next;
    }
    *pp_last_node = p_run;
}

static get_last_node_and_prev(list_t* p_list, node_t** pp_last_node, node_t** pp_prev_node)
{
    node_t* p_run = NULL;
    node_t* p_run_prev = NULL;

    p_run = p_list;

    while(p_run->next != p_list)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    *pp_last_node = p_run;
    *pp_prev_node = p_run_prev;
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end;
    p_beg->next = p_mid;
}

static void generic_delete(node_t* p_delete_node, node_t* p_delete_node_prev)
{
    p_delete_node_prev->next = p_delete_node->next;
    free(p_delete_node);
    p_delete_node = NULL;
}

static void get_node(list_t* p_list, data_t e_data, node_t** pp_e_node)
{
    node_t* p_run = NULL;
    p_run = p_list->next;
    while(p_run != p_list)
    {
        puts("inside while");
        if(p_run->data == e_data)
        {
            *pp_e_node = p_run;
            return;
        }
        p_run = p_run->next;
    }
    *pp_e_node = NULL;
    return;
}

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

//misc functions
status_t create_list(list_t** pp_list)
{
    list_t* p_list = NULL;
    p_list = get_new_node(-1);
    p_list->next = p_list;
    *pp_list = p_list;
    return SUCCESS;
}

status_t find_length(list_t* p_list, len_t* p_len)
{
    len_t len = 0;
    node_t* p_run = NULL;
    p_run = p_list->next;
    while(p_run != p_list)
    {
        len = len+1;
        p_run = p_run->next;
    }
    *p_len = len;
    return SUCCESS;
}

status_t show_list(list_t* p_list, const char* msg)
{
    if(msg)
        puts(msg);
    node_t* p_run = NULL;
    p_run = p_list->next;
    printf("[START]->");
    while(p_run != p_list)
    {
        printf("[%d]->",p_run->data);
        p_run = p_run->next;
    }
    puts("[END]");
    return SUCCESS;
}

bool_t is_list_empty(list_t* p_list)
{
    return (p_list->next == p_list);
}

bool_t search_data(list_t* p_list, data_t s_data)
{
    node_t* p_s_node = NULL;
    get_node(p_list, s_data, &p_s_node);
    if(p_s_node == NULL)
        return FALSE;
    else
        return TRUE;
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

status_t to_array(list_t* p_list, int** pp_arr, int* pp_size)
{
    len_t len = 0;
    find_length(p_list, &len);
    int* arr = (int*) xcalloc(len, sizeof(int));
    
    node_t* p_run = p_list->next;
    int i = 0;
    while(p_run != p_list)
    {   
        arr[i] = p_run->data;
        i = i+1;
        p_run = p_run->next;
    }
    *pp_size = len;
    *pp_arr = arr;
    return SUCCESS;
}

status_t sort_array(int* arr, int size)
{
    quick_sort(arr, 0, size-1);
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

status_t destroy_array(int** pp_arr)
{
    free(*pp_arr);
    *pp_arr = NULL;
    return SUCCESS;
}

//functions related to insert data in list
status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list,get_new_node(new_data), p_list->next);
    return SUCCESS;
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    node_t* p_last = NULL;

    get_last_node(p_list, &p_last);
    generic_insert(p_last, get_new_node(new_data), p_last->next);
    return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t new_data, data_t e_data)
{
    node_t* p_node = NULL;
    node_t* p_node_prev = NULL;

    get_node_and_prev(p_list, e_data, &p_node, &p_node_prev);
    if(p_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_insert(p_node_prev, get_new_node(new_data), p_node);
    return SUCCESS;
}

status_t insert_after(list_t* p_list, data_t new_data, data_t e_data)
{
    node_t* p_node = NULL;
    get_node(p_list, e_data, &p_node);
    if(p_node == NULL)
        return LIST_DATA_NOT_FOUND;

    generic_insert(p_node, get_new_node(new_data), p_node->next);
    return SUCCESS;
}

//functions related to read list data
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
    node_t* p_last_node = NULL;
    get_last_node(p_list, &p_last_node);
    *p_end_data = p_last_node->data;
    return SUCCESS;
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    *p_start_data = p_list->next->data;
    generic_delete(p_list->next, p_list);
    return SUCCESS;
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    node_t* p_last_node = NULL;
    node_t* p_last_node_prev = NULL;
    get_last_node_and_prev(p_list, &p_last_node, &p_last_node_prev);
    *p_end_data = p_last_node->data;
    generic_delete(p_last_node, p_last_node_prev);
    return SUCCESS;
}

//functions related to delete list data
status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    generic_delete(p_list->next, p_list);
    return SUCCESS;
}
status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    node_t* p_last_node = NULL;
    node_t* p_last_prev_node = NULL;

    get_last_node_and_prev(p_list, &p_last_node, &p_last_prev_node);
    generic_delete(p_last_node, p_last_prev_node);

    return SUCCESS;
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* p_r_node = NULL;
    node_t* p_r_node_prev = NULL;
    get_node_and_prev(p_list, r_data, &p_r_node, &p_r_node_prev);
    if(p_r_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_delete(p_r_node, p_r_node_prev);
    return SUCCESS;
}

//concat functions
status_t concat_lists_imm(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_concat)
{
    list_t* p_concat_list = NULL;
    create_list(&p_concat_list);
    node_t* p_run = NULL;

    for(p_run = p_list_1->next; p_run != p_list_1; p_run = p_run->next)
        insert_end(p_concat_list, p_run->data);
    for(p_run = p_list_2->next; p_run != p_list_2; p_run = p_run->next)
        insert_end(p_concat_list, p_run->data);

    *pp_list_concat = p_concat_list;
    return SUCCESS;
}

status_t concat_lists_m(list_t* p_list_1, list_t** pp_list_2)
{
    list_t* p_list_2 = *pp_list_2;

    node_t* p_last_node_of_list_1 = NULL;
    node_t* p_last_node_of_list_2 = NULL;

    if(is_list_empty(p_list_2) == TRUE)
        return SUCCESS;

    get_last_node(p_list_1, &p_last_node_of_list_1);
    get_last_node(p_list_2, &p_last_node_of_list_2);

    p_last_node_of_list_1->next = p_list_2->next;
    p_last_node_of_list_2->next = p_list_1;

    free(p_list_2);

    *pp_list_2 = NULL;

    return SUCCESS;
}

//merge function
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_merge)
{
    node_t* p_run_1 = p_list_1->next;
    node_t* p_run_2 = p_list_2->next;

    list_t* p_list_merge = NULL;
    create_list(&p_list_merge);
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
            while(p_run_1 == p_list_1)
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

//reverse function
status_t get_reversed_list(list_t* p_list, list_t** pp_list_reverse)
{
    list_t* p_list_reverse = NULL;
    create_list(&p_list_reverse);
    node_t* p_run = NULL;

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        insert_start(p_list_reverse,p_run->data);

    *pp_list_reverse = p_list_reverse;
    return SUCCESS;
}

status_t reverse_list(list_t* p_list)
{
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    //if list is empty or has one node
    if(p_list->next == p_list || p_list->next->next == p_list)
        return SUCCESS;

    p_run = p_list->next->next;
    p_list->next->next = p_list;

    while(p_run != p_list)
    {
        p_run_next = p_run->next;
        generic_insert(p_list, p_run, p_run->next);
        p_run = p_run_next;
    }

    return SUCCESS;
}
