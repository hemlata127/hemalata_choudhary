#ifndef _TELEPHONE_DIRECTORY_H
#define _TELEPHONE_DIRECTORY_H

//header files
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//symbolic constants
#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_EMPTY 2
#define LIST_DATA_NOT_FOUND 3

//typedefs
typedef unsigned long long int uint_t;
typedef char char_t;

//declaration of structure to store contact details
struct contact
{
    char_t name[100];
    uint_t phone_no;
};

//node of doubly circular linked list
struct node
{
    struct contact* p_contact;
    struct node* next;
    struct node* prev;
};

//typedefs
typedef int bool_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef struct node list_t;
typedef struct contact contact_t;

//auxillary functions
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
static contact_t* add_contact_details(contact_t new_contact);
static node_t* get_new_node(contact_t new_contact);
static bool_t is_list_empty(list_t* p_list);
static node_t* get_node_by_name(list_t* p_list, char_t* e_name);
static node_t* get_node_by_phone_number(list_t* p_list, uint_t e_phone_no);
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);

//interface functions
status_t create_list(list_t** pp_list);

status_t insert_start(list_t* p_list, contact_t new_contact);
status_t insert_end(list_t* p_list, contact_t new_contact);
status_t insert_before(list_t* p_list, contact_t new_contact, char_t* e_name);
status_t insert_after(list_t* p_list, contact_t new_contact, char_t* e_name);

status_t get_start(list_t* p_list, contact_t* p_e_contact);
status_t get_end(list_t* p_list, contact_t* p_e_contact);
status_t pop_start(list_t* p_list, contact_t* p_e_contact);
status_t pop_end(list_t* p_list, contact_t* p_e_contact);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, char_t* e_name);

status_t search_data_by_name(list_t* p_list, char_t* e_name, contact_t* p_e_contact);
status_t search_data_by_phone_number(list_t* p_list, uint_t e_phone_no, contact_t* p_e_contact);

status_t show_list(list_t* p_list, const char* msg);
status_t find_length(list_t* p_list, len_t* p_len);

status_t destroy_list(list_t** pp_list);

#endif
