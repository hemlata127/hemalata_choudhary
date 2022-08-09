#include "singly_linear_linked_list.h"

//auxillary function declarations
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
    node_t* p_new_node = NULL;
    p_new_node = (node_t*)xcalloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    
    return p_new_node;
}

static status_t generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_beg->next = p_mid;
    p_mid->next = p_end;
    return SUCCESS;
}

static status_t generic_delete(node_t* p_delete_node, node_t* p_delete_node_prev)
{
    if(p_delete_node_prev != NULL)
    {
        p_delete_node_prev->next = p_delete_node->next;
        free(p_delete_node);
        p_delete_node = NULL;
        return SUCCESS;
    }
    else
        return LIST_EMPTY;
}

static bool_t is_list_empty(list_t* p_list)
{
    return (p_list->next == NULL);
}

static status_t get_node(list_t* p_list, data_t e_data, node_t** pp_e_node)
{
    node_t* p_run = NULL;
    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == e_data)
        {
            *pp_e_node = p_run;
            return SUCCESS;
        }
        p_run = p_run->next;
    }
    *pp_e_node = p_run;
    return SUCCESS;
}

static status_t get_last_node(list_t* p_list, node_t** pp_last)
{
    node_t* p_run = NULL;
    p_run = p_list;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }
    *pp_last = p_run;
    return SUCCESS;
}

static status_t get_last_node_and_prev(list_t* p_list, node_t** pp_last, node_t** pp_last_prev)
{
    node_t* p_run = NULL;
    node_t* p_run_prev = NULL;

    p_run_prev = NULL;
    p_run = p_list;

    while(p_run->next != NULL)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    *pp_last = p_run;
    *pp_last_prev = p_run_prev;
    return SUCCESS;
}

static status_t get_node_and_prev(list_t* p_list, data_t e_data, node_t** pp_node, node_t** pp_prev_node)
{
    node_t* p_run = NULL;
    node_t* p_run_prev = NULL;

    p_run_prev = NULL;
    p_run = p_list;
    while(p_run != NULL)
    {
        if(p_run->data == e_data)
            break;
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    *pp_node = p_run;
    *pp_prev_node = p_run_prev;
    return SUCCESS;
}

static void quick_sort(int* arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

static int partition(int* arr, int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;
    int j, temp;
    for(j = p; j<r; ++j)
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

//interface function declarations
status_t create_list(list_t** pp_list)
{
    list_t* p_list = NULL;
    p_list = get_new_node(-1);
    *pp_list = p_list;
    return SUCCESS;
}

status_t show_list(list_t* p_list, const char* msg)
{
    node_t* p_run = NULL;
    p_run = p_list->next;
    printf("[START]->");
    while(p_run != NULL)
    {
        printf("[%d]->",p_run->data);
        p_run = p_run->next;
    }
    puts("[END]");
    return SUCCESS;
}

status_t find_length(list_t* p_list, len_t* p_len)
{
    len_t len = 0;
    node_t* p_run = NULL;
    p_run = p_list->next;
    while(p_run != NULL)
    {
        len = len+1;
        p_run = p_run->next;
    }
    *p_len = len;
    return SUCCESS;
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

    p_run_next = p_list;
    p_run = p_list->next;
    while(p_run != NULL)
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

status_t to_array(list_t* p_list, int** pp_arr, int* p_size)
{
    len_t len = 0;
    find_length(p_list, &len);

    int* arr = NULL;
    arr = (int*)xcalloc(len, sizeof(int));
    int i = 0;
    node_t* p_run = p_list->next;
    while(p_run != NULL)
    {
        arr[i] = p_run->data;
        p_run = p_run->next;
        i = i+1;
    }
    *pp_arr = arr;
    *p_size = len;
    return SUCCESS;
}

status_t sort_array(int* arr, int size)
{
    quick_sort(arr, 0, size - 1);
    return SUCCESS;
}

status_t to_list(int* arr, int size, list_t** pp_list)
{
    list_t* p_list = NULL;
    create_list(&p_list);
    int i;
    for(i = 0; i<size; ++i)
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
    generic_insert(p_list, get_new_node(new_data), p_list->next);
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
    node_t* p_e_node = NULL;
    node_t* p_e_prev_node = NULL;
    get_node_and_prev(p_list, e_data, &p_e_node, &p_e_prev_node);
    if(p_e_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_insert(p_e_prev_node, get_new_node(new_data), p_e_node);
    return SUCCESS;
}

status_t insert_after(list_t* p_list, data_t new_data, data_t e_data)
{
    node_t* p_e_node = NULL;
    get_node(p_list, e_data, &p_e_node);
    if(p_e_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_insert(p_e_node, get_new_node(new_data), p_e_node->next);
    return SUCCESS;
}

//functions related to read data from list
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
    node_t* p_last = NULL;
    get_last_node(p_list, &p_last);
    *p_end_data = p_last->data;
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
    node_t* p_last = NULL;
    node_t* p_last_prev = NULL;
    get_last_node_and_prev(p_list, &p_last, &p_last_prev);
    *p_end_data = p_last->data;
    generic_delete(p_last, p_last_prev);
    return SUCCESS;
}

//functions related to remove list data
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
    node_t* p_last = NULL;
    node_t* p_last_prev = NULL;
    get_last_node_and_prev(p_list, &p_last, &p_last_prev);
    generic_delete(p_last, p_last_prev);
    return SUCCESS;
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    node_t* p_e_node = NULL;
    node_t* p_e_prev_node = NULL;
    get_node_and_prev(p_list, r_data, &p_e_node, &p_e_prev_node);
    if(p_e_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_delete(p_e_node, p_e_prev_node);
    return SUCCESS;
}

//concatenation functions
status_t concat_lists_imm(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_concat)
{
    list_t* p_list_concat = NULL;
    create_list(&p_list_concat);
    node_t* p_run = NULL;

    for(p_run = p_list_1->next; p_run != NULL; p_run = p_run->next)
        insert_end(p_list_concat, p_run->data);
    for(p_run = p_list_2->next; p_run != NULL; p_run = p_run->next)
        insert_end(p_list_concat, p_run->data);
    
    *pp_list_concat = p_list_concat;
    return SUCCESS;
}

status_t concat_lists_m(list_t* p_list_1, list_t** pp_list_2)
{
    list_t* p_list_2 = *pp_list_2;
    if(is_list_empty(p_list_2) == TRUE)
    {
        free(p_list_2);
        p_list_2 = NULL;
        *pp_list_2 = NULL;
        return SUCCESS;
    }

    node_t* p_last = NULL;
    get_last_node(p_list_1, &p_last);
    p_last->next = p_list_2->next;
    free(p_list_2);
    p_list_2 = NULL;
    *pp_list_2 = NULL;
    return SUCCESS;
}

//merge function
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_list_merge)
{
    list_t* p_list_merge = NULL;
    create_list(&p_list_merge);

    node_t* p_run_1 = p_list_1->next;
    node_t* p_run_2 = p_list_2->next;

    while(TRUE)
    {
        if(p_run_1 == NULL)
        {
            while(p_run_2 != NULL)
            {
                insert_end(p_list_merge, p_run_2->data);
                p_run_2 = p_run_2->next;
            }
            break;
        }

        if(p_run_2 == NULL)
        {
            while(p_run_1 != NULL)
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

//reverse list functions
status_t get_reversed_list(list_t* p_list, list_t** pp_list_reverse)
{
    list_t* p_list_rev = NULL;
    create_list(&p_list_rev);
    node_t* p_run = NULL;
    for(p_run = p_list->next; p_run != NULL; p_run = p_run->next)
        insert_start(p_list_rev, p_run->data);
    *pp_list_reverse = p_list_rev;
    return SUCCESS;
}
status_t reverse_list(list_t* p_list)
{
    return 0;
}
