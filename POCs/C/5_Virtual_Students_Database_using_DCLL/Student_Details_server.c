#include "Student_Details.h"

//auxillary functions
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

static s_details_t* add_new_student_details(s_details_t new_s_details)
{
    s_details_t* p_new_node = (s_details_t*)xcalloc(1, sizeof(s_details_t));
    p_new_node->roll_no = new_s_details.roll_no;
    strcpy(p_new_node->s_name,new_s_details.s_name);
    strcpy(p_new_node->year,new_s_details.year);
    strcpy(p_new_node->department,new_s_details.department);
    p_new_node->percentage = new_s_details.percentage;

    return p_new_node;
}

static node_t* get_new_node(s_details_t new_s_details)
{
    s_details_t* p_new_s_details = NULL;
    p_new_s_details = add_new_student_details(new_s_details);

    node_t* p_new_node = NULL;
    p_new_node = (node_t*)xcalloc(1, sizeof(node_t));

    p_new_node->p_s_details = p_new_s_details;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;

    return p_new_node;
}

static node_t* get_node(list_t* p_list, uint_t s_roll_no)
{
    node_t* p_run = NULL;

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
    {
        if(p_run->p_s_details->roll_no == s_roll_no)
            return p_run;
    }

    return NULL;
}

static bool_t is_list_empty(list_t* p_list)
{
    return (p_list->next == p_list && p_list->prev == p_list);
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_beg->next = p_mid;
    p_mid->prev = p_beg;
    p_mid->next = p_end;
    p_end->prev = p_mid;
}

static void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;
}

//================================================================================
//interface functions
status_t create_list(list_t** pp_list)
{
    s_details_t s_details = {-1, "xxxx", "xx", "xxx", 0.0};
    list_t* p_list = NULL;
    p_list = get_new_node(s_details);
    p_list->next = p_list;
    p_list->prev = p_list;

    *pp_list = p_list;
    return SUCCESS;
}

status_t show_list(list_t* p_list, const char* msg)
{
    if(msg)
        puts(msg);
    printf("%-10s%-25s%-10s%-25s%-25s\n","ROLL NO", "STUDENT NAME", "YEAR", "DEPARTMENT", "PERCENTAGE");
    puts("----------------------------------------------------------------------------------");
    node_t* p_run = p_list->next;
    while(p_run != p_list)
    {
        printf("%-10hu%-25s%-10s%-25s%-25.3f\n",p_run->p_s_details->roll_no, p_run->p_s_details->s_name, p_run->p_s_details->year, p_run->p_s_details->department, p_run->p_s_details->percentage);
        p_run = p_run->next;
    }
    return SUCCESS;
}

status_t find_length(list_t* p_list, len_t* p_len)
{
    len_t len = 0;
    node_t* p_run = NULL;
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        len = len+1;
    *p_len = len;
    return SUCCESS;
}

status_t insert_end(list_t* p_list, s_details_t new_s_details)
{
    generic_insert(p_list->prev, get_new_node(new_s_details), p_list);
    return SUCCESS;
}

status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    generic_delete(p_list->next);
    return SUCCESS;
}

status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    generic_delete(p_list->prev);
    return SUCCESS;
}

status_t remove_data(list_t* p_list, uint_t roll_no)
{
    node_t* p_r_node = NULL;
    p_r_node = get_node(p_list, roll_no);
    if(p_r_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_delete(p_r_node);
    return SUCCESS;
}

status_t get_start(list_t* p_list, s_details_t** pp_e_s_details)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;

    *pp_e_s_details = p_list->next->p_s_details;
    return SUCCESS;
}

status_t get_end(list_t* p_list, s_details_t** pp_e_s_details)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    
    *pp_e_s_details = p_list->prev->p_s_details;
    return SUCCESS;
}

status_t search_data(list_t* p_list, uint_t roll_no, s_details_t** pp_e_s_details)
{
    node_t* p_e_node = NULL;

    p_e_node =  get_node(p_list, roll_no);

    if(p_e_node == NULL)
        return LIST_DATA_NOT_FOUND;

    *pp_e_s_details = p_e_node->p_s_details;
    return SUCCESS;
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
