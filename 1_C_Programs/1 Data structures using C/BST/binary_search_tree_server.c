#include "binary_serach_tree.h"

//auxillary functions - node level operations
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
    p_new_node->left = NULL;
    p_new_node->right = NULL;
    p_new_node->parent = NULL;

    return p_new_node;
}

static node_t* get_node(bst_t* p_bst, data_t e_data)
{
    node_t* p_run = NULL;
    p_run = p_bst->p_root_node;
    while(p_run != NULL)
    {
        if(e_data == p_run->data)
            break;
        else if(e_data < p_run->data)
            p_run = p_run->left;
        else
            p_run = p_run->right;
    }
    
    return p_run;
}

static node_t* get_max_node(node_t* p_node)
{
    node_t* p_run = NULL;
    p_run = p_node;
    while(p_run->right != NULL)
        p_run = p_run->right;
    return p_run;
}


static node_t* get_min_node(node_t* p_node)
{
    node_t* p_run = NULL;
    p_run = p_node;
    while(p_run->left != NULL)
        p_run = p_run->left;
    return p_run;
}

static node_t* get_inorder_successor(node_t* p_node)
{
    node_t* p_run = NULL;
    node_t* n = NULL;
    node_t* p = NULL;

    p_run = p_node;
    //case 1 right subtree of p_run is not NULL - min of right sbtree is the in order suucc
    if(p_run->right != NULL)
    {
        //go to right sub tree
        p_run = p_run->right;
        //return the minimum of p_run
        while(p_run->left != NULL)
            p_run = p_run->left;
        return p_run;
    }
    else
    //case 2 - right subtree of p_run is NULL - in order succ is one of its ancestor
    {
        n = p_run;
        p = p_run->parent;
        //travel up untill you get a node that is left child of its parent
        while(p != NULL && p->right == n)
        {
            n = p;
            p = p->parent;
        }
        return p;
    }
}

static node_t* get_inorder_predecessor(node_t* p_node)
{
    node_t* p_run = NULL;
    node_t* n = NULL;
    node_t* p = NULL;

    p_run = p_node;
    //case 1 - left sub tree is present
    if(p_run->left != NULL)
    {
        //go in left subtree
        p_run = p_run->left;
        //return max of left sub tree
        while(p_run->right != NULL)
            p_run = p_run->right;
        return p_run;
    }
    //case 2 - left sub tree is null - in order prd is an ancestor node whose right 
    else
    {
        n = p_run;
        p = p_run->parent;
        while(p != NULL && p->left == n)
        {
            n = p;
            p = p->parent;
        }
        return p;
    }
}

static void display_preorder_node(node_t* p_node)
{
    if(p_node != NULL)
    {
        printf("[%d]<->",p_node->data);
        display_preorder_node(p_node->left);
        display_preorder_node(p_node->right);
    }
}

static void display_inorder_node(node_t* p_node)
{
    if(p_node != NULL)
    {
        display_inorder_node(p_node->left);
        printf("[%d]<->",p_node->data);
        display_inorder_node(p_node->right);
    }
}

static void display_postorder_node(node_t* p_node)
{
    if(p_node != NULL)
    {
        display_postorder_node(p_node->left);
        display_postorder_node(p_node->right);
        printf("[%d]<->",p_node->data);
    }
}

static void destroy_node(node_t* p_node)
{
    if(p_node != NULL)
    {
        free(p_node->left);
        free(p_node->right);
        free(p_node);
    }
}

//interface functions - tree level operations
bst_t* bst_create()
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xcalloc(1, sizeof(bst_t));
    p_bst->nr_of_nodes = 0;
    p_bst->p_root_node = NULL;
    return p_bst;
}

status_t bst_insert(bst_t* p_bst, data_t new_data)
{
    node_t* p_new_node = get_new_node(new_data);
    node_t* p_run = NULL;
    p_run = p_bst->p_root_node;
    if(p_run == NULL)
    {
        p_bst->p_root_node = p_new_node;
        p_bst->nr_of_nodes = p_bst->nr_of_nodes + 1;
        return SUCCESS;
    }
    while(TRUE)
    {
        if(new_data <= p_run->data)
        {
            if(p_run->left == NULL)
            {
                p_run->left = p_new_node;
                break;
            }
            p_run = p_run->left;
        }
        if(new_data > p_run->data)
        {
            if(p_run->right == NULL)
            {
                p_run->right = p_new_node;
                break;
            }
            p_run = p_run->right;
        }
    }
    p_bst->nr_of_nodes = p_bst->nr_of_nodes;
    return SUCCESS;
}

void bst_preorder_display_r(bst_t* p_bst)
{
    printf("[START]<->");
    display_preorder_node(p_bst->p_root_node);
    puts("[END]");
}

void bst_inorder_display_r(bst_t* p_bst)
{
    printf("[START]<->");
    display_inorder_node(p_bst->p_root_node);
    puts("[END]");
}

void bst_postorder_display_r(bst_t* p_bst)
{
    printf("[START]<->");
    display_postorder_node(p_bst->p_root_node);
    puts("END");
}

status_t bst_find_max(bst_t* p_bst, data_t* p_max_data)
{
    if(p_bst->p_root_node == NULL)
        return TREE_EMPTY;

    node_t* p_run = NULL;
    p_run = get_max_node(p_bst->p_root_node);

    *p_max_data = p_run->data;
    return SUCCESS;
}

status_t bst_find_min(bst_t* p_bst, data_t* p_min_data)
{
    if(p_bst->p_root_node == NULL)
        return TREE_EMPTY;

    node_t* p_run = NULL;
    p_run = get_min_node(p_bst->p_root_node);

    *p_min_data = p_run->data;
    return SUCCESS;
}

status_t bst_inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data)
{
    node_t* p_e_node = NULL;
    node_t* p_succ_node = NULL;

    p_e_node = get_node(p_bst, e_data);
    if(p_e_node == NULL)
        return TREE_DATA_NOT_FOUND;

    p_succ_node = get_inorder_successor(p_e_node);

    if(p_succ_node == NULL)
        return TREE_NO_SUCCESSOR;

    *p_succ_data = p_succ_node->data;

    return SUCCESS;
}

status_t bst_inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data)
{
    node_t* p_e_node = NULL;
    node_t* p_pred_node = NULL;

    p_e_node = get_node(p_bst, e_data);
    if(p_e_node == NULL)
        return TREE_DATA_NOT_FOUND;

    p_pred_node = get_inorder_predecessor(p_e_node);
    if(p_pred_node == NULL)
        return TREE_NO_PREDECESSOR;

    *p_pred_data = p_pred_node->data;

    return SUCCESS;
}

bool_t bst_search_data(bst_t* p_bst, data_t s_data)
{
    node_t* p_e_node = NULL;
    p_e_node = get_node(p_bst, s_data);

    if(p_e_node == NULL)
        return FALSE;
    else
        return TRUE;
}

status_t bst_remove_data(bst_t* p_bst, data_t r_data)
{
    node_t* z = NULL;   //node to be deleted
    node_t* w = NULL;

    z = get_node(p_bst, r_data);
    printf("delete node = %d\n",z->data);
    if(z == NULL)
        return TREE_DATA_NOT_FOUND;

    //case 1 - z has only one child
    //case 1 - subcase 1 z has right child only (no left child)
    //z's parent can take the responsibility of its right child
    if(z->left == NULL)
    {
        //z is to be deleted, its parent is NULL, means root node is to be deleted, z->right will become new root node
        if(z->parent == NULL)
            p_bst->p_root_node = z->right;
        //z is its parent's left child - z's parent 's left child now is z's right child
        else if(z == z->parent->left)
            z->parent->left = z->right;
        //z is its parent's right child, so z's parents's right child is now z's right child
        else
            z->parent->right = z->right;
        //connect the new parent
        if(z->right != NULL)
            z->right->parent = z->parent;
    }
    //case 1 - subcase 2 - z has left child only (no right child)
    //z's parent can take the responsibility of its left child
    else if(z->right == NULL)
    {
        if(z->parent == NULL)
            p_bst->p_root_node = z->left;
        else if(z == z->parent->left)
            z->parent->left = z->left;
        else
            z->parent->right = z->left;
        if(z->left != NULL)
            z->left->parent = z->parent;  
    }
    //case 2 - z has left and right child
    else
    {
        //find in order successor of w
        w = z->right;
        while(w->left != NULL)
            w = w->left;

        //in order successor is not its immediate right child
        if(z->right != w)
        {
            w->parent->left = w->right;
            if(w->right != NULL)
                w->right->parent = w->parent;
            
            w->right = z->right;
            w->right->parent = w;
        }

        if(z->parent == NULL)
            p_bst->p_root_node = w;
        else if(z == z->parent->left)
            z->parent->left = w;
        else
            z->parent->right = w;
        w->parent = z->parent;

        w->left = z->left;
        w->left->parent = w;
    }
    p_bst->nr_of_nodes = p_bst->nr_of_nodes - 1;
    free(z);
    return SUCCESS;
}

len_t bst_find_length(bst_t* p_bst)
{
    return p_bst->nr_of_nodes;
}

bool_t is_bst_empty(bst_t* p_bst)
{
    if(p_bst->p_root_node == NULL)
        return TRUE;
    else
        return FALSE;
}

void bst_destroy(bst_t** pp_bst)
{
    destroy_node((*pp_bst)->p_root_node);
    free(*pp_bst);
    *pp_bst = NULL;
}
