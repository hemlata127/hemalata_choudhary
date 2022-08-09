#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

//header files
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define TREE_EMPTY 2
#define TREE_DATA_NOT_FOUND 3
#define TREE_NO_SUCCESSOR 4
#define TREE_NO_PREDECESSOR 5

//node declaration
struct bst_node
{
    int data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

//declaration of node to hold - root node and count of elements
struct bst
{
    struct bst_node* p_root_node;
    unsigned long long int nr_of_elements;
};

//typedefs
typedef int data_t;
typedef int status_t;
typedef unsigned long long int uint_t;
typedef unsigned long long int len_t;
typedef int bool_t;
typedef struct bst_node node_t;
typedef struct bst bst_t;

//auxillary function declarations
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
node_t* get_max_node(node_t* p_node);
node_t* get_min_node(node_t* p_node);
node_t* get_inorder_successor(node_t* p_node);
node_t* get_inorder_predecessor(node_t* p_node);
node_t* get_node(bst_t* p_bst, data_t e_data);
static void display_preorder_node(node_t* p_root_node);
static void display_inorder_node(node_t* p_root_node);
static void display_postorder_node(node_t* p_root_node);
node_t* get_new_bst_node(data_t new_data);
void destroy_node(node_t* p_root_node);

//interface function declarations
bst_t* create_bst(void);
status_t bst_insert(bst_t* p_bst, data_t new_data);
void preorder_r(bst_t* p_bst);
void inorder_r(bst_t* p_bst);
void postorder_r(bst_t* p_bst);
status_t find_bst_max(bst_t* p_bst, data_t* p_max_data);
status_t find_bst_min(bst_t* p_bst, data_t* p_min_data);
status_t find_bst_inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data);
status_t find_bst_inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data);
bool_t bst_search(bst_t* p_bst, data_t s_data);
status_t remove_data(bst_t* p_bst, data_t r_data);
bool_t is_bst_empty(bst_t* p_bst);
len_t find_length(bst_t* p_bst);
void bst_destroy(bst_t** pp_bst);

#endif
