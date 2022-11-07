#ifndef _STUDENTS_DETAILS_H
#define _STUDENTS_DETAILS_H

//header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define LIST_EMPTY 2
#define LIST_DATA_NOT_FOUND 3

//typedefs
typedef unsigned long long int uint_t;
typedef unsigned short ushort_t;
typedef char char_t;
typedef float float_t;

//declaration of struct student details 
struct student_details
{
    ushort_t roll_no;
    char_t s_name[40];
    char_t year[5];
    char_t department[25];
    uint_t contact_no;
    float_t percentage;
};

//linked list node declaration
struct node
{
    struct student_details* p_s_details;
    struct node* next;
    struct node* prev;
};

//typedefs
typedef int bool_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef struct node list_t;
typedef struct student_details s_details_t;

//auxillary functions
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
static s_details_t* add_new_student_details(s_details_t new_s_details);
static node_t* get_new_node(s_details_t new_s_details);
static node_t* get_node(list_t* p_list, uint_t s_roll_no);
static bool_t is_list_empty(list_t* p_list);
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);

//interface functions
status_t create_list(list_t** pp_list);
status_t show_list(list_t* p_list, const char* msg);
status_t find_length(list_t* p_list, len_t* p_len);
status_t insert_end(list_t* p_list, s_details_t new_s_details);
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, uint_t roll_no);
status_t get_start(list_t* p_list, s_details_t** pp_e_s_details);
status_t get_end(list_t* p_list, s_details_t** pp_e_s_details);
status_t search_data(list_t* p_list, uint_t roll_no, s_details_t** pp_e_s_details);
status_t destroy_list(list_t** pp_list);

#endif
