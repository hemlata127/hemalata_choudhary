#include "telephone_directory.h"

//=========================================================================
//auxillary functions definitions
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

static contact_t* add_contact_details(contact_t new_contact)
{
    contact_t* p_new_contact = (contact_t*) xcalloc(1, sizeof(contact_t));
    strcpy(p_new_contact->name, new_contact.name);
    p_new_contact->phone_no = new_contact.phone_no;

    return p_new_contact;
}

static node_t* get_new_node(contact_t new_contact)
{
    node_t* p_new_node = NULL;
    p_new_node = (node_t*)xcalloc(1, sizeof(node_t));
    contact_t* p_new_contact = NULL;
    p_new_contact = add_contact_details(new_contact);
    
    p_new_node->p_contact = p_new_contact;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;
    return p_new_node;
}

static bool_t is_list_empty(list_t* p_list)
{
    return(p_list->next == p_list && p_list->prev == p_list);
}


static node_t* get_node_by_name(list_t* p_list, char_t* e_name)
{
    node_t* p_run = NULL;

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
    {
        if(strcmp(p_run->p_contact->name, e_name) == 0)
            return p_run;
    }
    return NULL;
}

static node_t* get_node_by_phone_number(list_t* p_list, uint_t e_phone_no)
{
    node_t* p_run = NULL;

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
    {
        if(p_run->p_contact->phone_no == e_phone_no)
            return p_run;
    }
    return NULL;
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

//=========================================================================
//interface functions definitions

status_t create_list(list_t** pp_list)
{
    list_t* p_list = NULL;
    contact_t dummy_details = {"dummy", 0000};

    p_list = get_new_node(dummy_details);
    p_list->next = p_list;
    p_list->prev = p_list;
    *pp_list = p_list;
    return SUCCESS;
}

status_t insert_start(list_t* p_list, contact_t new_contact)
{
    generic_insert(p_list, get_new_node(new_contact), p_list->next);
    return SUCCESS;
}

status_t insert_end(list_t* p_list, contact_t new_contact)
{
    generic_insert(p_list->prev, get_new_node(new_contact), p_list);
    return SUCCESS;
}

status_t insert_before(list_t* p_list, contact_t new_contact, char_t* e_name)
{
    node_t* p_e_node = NULL;
    p_e_node = get_node_by_name(p_list, e_name);
    if(p_e_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_insert(p_e_node->prev, get_new_node(new_contact), p_e_node);
    return SUCCESS;
}

status_t insert_after(list_t* p_list, contact_t new_contact, char_t* e_name)
{
    node_t* p_e_node = NULL;
    p_e_node = get_node_by_name(p_list, e_name);
    if(p_e_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_insert(p_e_node, get_new_node(new_contact), p_e_node->next);
    return SUCCESS;
}

status_t get_start(list_t* p_list, contact_t* p_e_contact)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    strcpy(p_e_contact->name, p_list->next->p_contact->name);
    p_e_contact->phone_no = p_list->next->p_contact->phone_no;
    return SUCCESS;
}

status_t get_end(list_t* p_list, contact_t* p_e_contact)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    strcpy(p_e_contact->name, p_list->prev->p_contact->name);
    p_e_contact->phone_no = p_list->prev->p_contact->phone_no;
    return SUCCESS;
}

status_t pop_start(list_t* p_list, contact_t* p_e_contact)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    strcpy(p_e_contact->name, p_list->next->p_contact->name);
    p_e_contact->phone_no = p_list->next->p_contact->phone_no;
    generic_delete(p_list->next);
    return SUCCESS;
}

status_t pop_end(list_t* p_list, contact_t* p_e_contact)
{
    if(is_list_empty(p_list) == TRUE)
        return LIST_EMPTY;
    strcpy(p_e_contact->name, p_list->prev->p_contact->name);
    p_e_contact->phone_no = p_list->prev->p_contact->phone_no;
    generic_delete(p_list->prev);
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

status_t remove_data(list_t* p_list, char_t* e_name)
{
    list_t* p_r_node = NULL;
    p_r_node = get_node_by_name(p_list, e_name);
    if(p_r_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_delete(p_r_node);
    return SUCCESS;
}

status_t search_data_by_name(list_t* p_list, char_t* e_name, contact_t* p_e_contact)
{
    node_t* p_s_node = NULL;
    p_s_node = get_node_by_name(p_list, e_name);
    if(p_s_node == NULL)
        return FALSE;
    else
    {
        strcpy(p_e_contact->name, p_s_node->p_contact->name);
        p_e_contact->phone_no = p_s_node->p_contact->phone_no;
        return TRUE;
    }
}

status_t search_data_by_phone_number(list_t* p_list, uint_t e_phone_no, contact_t* p_e_contact)
{
    node_t* p_s_node = NULL;
    p_s_node = get_node_by_phone_number(p_list, e_phone_no);
    if(p_s_node == NULL)
        return FALSE;
    else
    {
        strcpy(p_e_contact->name, p_s_node->p_contact->name);
        p_e_contact->phone_no = p_s_node->p_contact->phone_no;
        return TRUE;
    }
}

status_t show_list(list_t* p_list, const char* msg)
{
    puts("=======================================================");
    if(msg)
        puts(msg);
    node_t* p_run = NULL;
    puts("-------------------------------------------------------");
    printf("%-35s%s\n","Name", "Phone Number");
    puts("-------------------------------------------------------");
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        printf("%-35s%llu\n",p_run->p_contact->name, p_run->p_contact->phone_no);
    
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
