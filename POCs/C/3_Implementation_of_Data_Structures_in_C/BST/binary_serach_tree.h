#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

//header files
#include<stdio.h>
#include<stdlib.h>

//symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define TREE_EMPTY 2
#define TREE_DATA_NOT_FOUND 3
#define TREE_NO_PREDECESSOR 4
#define TREE_NO_SUCCESSOR 5

//typedefs 
typedef int data_t;
typedef int bool_t;
typedef int status_t;
typedef unsigned long long int uint_t;
typedef uint_t len_t;

//declaration of a binary search tree node
struct node
{
    data_t data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

//declaration of the head node of a binary search tree - which is pointing to the bst (root node of the bst)
struct bst
{
    uint_t nr_of_nodes;
    struct node* p_root_node;
};

//typedefs
typedef struct node node_t;
typedef struct bst bst_t;

//auxillary functions - node level operations
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
static node_t* get_new_node(data_t new_data);
static node_t* get_node(bst_t* p_bst, data_t e_data);
static node_t* get_max_node(node_t* p_node);
static node_t* get_min_node(node_t* p_node);
static node_t* get_inorder_successor(node_t* p_node);
static node_t* get_inorder_predecessor(node_t* p_node);
static void display_preorder_node(node_t* p_node);
static void display_inorder_node(node_t* p_node);
static void display_postorder_node(node_t* p_node);
static void destroy_node(node_t* p_node);

//interface functions - tree level operations
bst_t* bst_create();
status_t bst_insert(bst_t* p_bst, data_t new_data);
void bst_preorder_display_r(bst_t* p_bst);
void bst_inorder_display_r(bst_t* p_bst);
void bst_postorder_display_r(bst_t* p_bst);
status_t bst_find_max(bst_t* p_bst, data_t* p_max_data);
status_t bst_find_min(bst_t* p_bst, data_t* p_min_data);
status_t bst_inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data);
status_t bst_inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data);
bool_t bst_search_data(bst_t* p_bst, data_t s_data);
status_t bst_remove_data(bst_t* p_bst, data_t r_data);
len_t bst_find_length(bst_t* p_bst);
bool_t is_bst_empty(bst_t* p_bst);
void bst_destroy(bst_t** pp_bst);

#endif
