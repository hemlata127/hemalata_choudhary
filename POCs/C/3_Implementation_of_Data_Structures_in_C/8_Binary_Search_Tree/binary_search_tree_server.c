#include "binary_search_tree.h"

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

node_t* get_max_node(node_t* p_node)
{
    //tracker
    node_t* p_run = p_node;
    while(p_run->right != NULL)
        p_run = p_run->right;
    return p_run;
}

node_t* get_min_node(node_t* p_node)
{
    node_t* p_run = p_node;
    while(p_run->left != NULL)
        p_run = p_run->left;
    return p_run;
}

//find the inorder successor of the given node
node_t* get_inorder_successor(node_t* p_node)
{
    node_t* p_run = NULL;
    node_t* x = NULL;
    node_t* y = NULL;

    p_run = p_node;
    //right subtree of node whose succ is to be found is present - find lowest of right sub tree
    if(p_run->right != NULL)
    {
        p_run = p_run->right;
        while(p_run->left != NULL)
            p_run = p_run->left;
        return p_run;
    }
    else
    //right subtree of node whose succ is to be found is present - 
    //traverse up till you reach a node whose right node you are
    {
        x = p_run;
        y = p_run->parent;
        //till parent is NULL and 
        //y != NULL should be taken first
        while(y != NULL && y->right == x)  
        {
            x = y;
            y = y->parent;
        }
        return y;
    }
}

node_t* get_inorder_predecessor(node_t* p_node)
{
    node_t* p_run = NULL;
    node_t* x = NULL;
    node_t* y = NULL;
    p_run = p_node;

    //left subtree of node whose predecessor is to be found is present - largest of left subtree
    if(p_run->left != NULL)
    {
        p_run = p_run->left;
        while(p_run->right != NULL)
            p_run = p_run->right;
        return p_run;
    }
    //left subtree of node whose predecessor is to be found is present
    //traverse up till you get a node whose left node you are
    else
    {
        x = p_run;
        y = p_run->parent;
        while(y != NULL && y->left == x)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }
}

node_t* get_node(bst_t* p_bst, data_t e_data)
{
    node_t* p_run = NULL;
    p_run = p_bst->p_root_node;
    while(p_run != NULL)
    {
        if(e_data == p_run->data)
            break;
        else if(e_data <= p_run->data)
            p_run = p_run->left;
        else
            p_run = p_run->right;
    }
    return p_run;
}

static void display_preorder_node(node_t* p_root_node)
{
    if(p_root_node != NULL)
    {
        printf("[%d]<->",p_root_node->data);
        display_preorder_node(p_root_node->left);
        display_preorder_node(p_root_node->right);
    }
}

static void display_inorder_node(node_t* p_root_node)
{
    if(p_root_node != NULL)
    {
        display_inorder_node(p_root_node->left);
        printf("[%d]<->",p_root_node->data);
        display_inorder_node(p_root_node->right);
    }
}

static void display_postorder_node(node_t* p_root_node)
{
    if(p_root_node != NULL)
    {
        display_postorder_node(p_root_node->left);
        display_postorder_node(p_root_node->right);
        printf("[%d]<->",p_root_node->data);
    }
}

node_t* get_new_bst_node(data_t new_data)
{
    node_t* p_new_node = NULL;
    p_new_node = (node_t*)xcalloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->parent = NULL;
    p_new_node->left = NULL;
    p_new_node->right = NULL;
    return p_new_node;
}

//destroy the specified root node and its children
void destroy_node(node_t* p_root_node)
{
    if(p_root_node != NULL)
    {
        destroy_node(p_root_node->left);
        destroy_node(p_root_node->right);
        free(p_root_node);
    }
}

//=============================================================================
//interface function declarations
bst_t* create_bst(void)
{
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)xcalloc(1, sizeof(bst_t));
    p_bst->p_root_node = NULL;
    p_bst->nr_of_elements = 0;
    return p_bst;
}

status_t bst_insert(bst_t* p_bst, data_t new_data)
{
    node_t* p_new_node = NULL;
    node_t* p_run = NULL;

    p_new_node = get_new_bst_node(new_data);
    p_run = p_bst->p_root_node;

    //if BST is empty, new node becomes the root node
    if(p_run == NULL)
    {
        p_bst->p_root_node = p_new_node;
        p_bst->nr_of_elements = p_bst->nr_of_elements + 1;
        return (SUCCESS);
    }

    while(TRUE)
    {
        if(new_data <= p_run->data)
        {
            if(p_run->left == NULL)
            {
                p_run->left = p_new_node;
                p_new_node->parent = p_run;
                break;
            }
            else
                p_run = p_run->left;
        }

        if(new_data > p_run->data)
        {
            if(p_run->right == NULL)
            {
                p_run->right = p_new_node;
                p_new_node->parent = p_run;
                break;
            }
            else
                p_run = p_run->right;
        }
    }
    p_bst->nr_of_elements = p_bst->nr_of_elements + 1;
    return (SUCCESS);
}

void preorder_r(bst_t* p_bst)
{
    printf("[START]<->");
    display_preorder_node(p_bst->p_root_node);
    puts("[END]");
}

void inorder_r(bst_t* p_bst)
{
    printf("[START]<->");
    display_inorder_node(p_bst->p_root_node);
    puts("[END]");
}

void postorder_r(bst_t* p_bst)
{
    printf("[START]<->");
    display_postorder_node(p_bst->p_root_node);
    puts("[END]");
}

status_t find_bst_max(bst_t* p_bst, data_t* p_max_data)
{
    node_t* p_max_node = NULL;
    if(p_bst->p_root_node == NULL)
        return TREE_EMPTY;
    p_max_node = get_max_node(p_bst->p_root_node);
    *p_max_data = p_max_node->data;
    return SUCCESS;
}

status_t find_bst_min(bst_t* p_bst, data_t* p_min_data)
{
    node_t* p_min_node = NULL;
    if(p_bst->p_root_node == NULL)
        return TREE_EMPTY;
    p_min_node = get_min_node(p_bst->p_root_node);
    *p_min_data = p_min_node->data;
    return SUCCESS;
}

status_t find_bst_inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data)
{
    node_t* p_e_node = NULL;
    node_t* p_succ_node = NULL;

    p_e_node = get_node(p_bst, e_data);
    if(p_e_node == NULL)
        return TREE_DATA_NOT_FOUND;

    p_succ_node = get_inorder_successor(p_e_node);
    if(p_succ_node == NULL)
        TREE_NO_SUCCESSOR;
    
    *p_succ_data = p_succ_node->data;
    return SUCCESS;
}

status_t find_bst_inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data)
{
    node_t* p_e_node = NULL;
    node_t* p_pred_node = NULL;

    p_e_node = get_node(p_bst, e_data);
    if(p_e_node == NULL)
        return TREE_EMPTY;
    
    p_pred_node = get_inorder_predecessor(p_e_node);
    if(p_pred_node == NULL)
        return TREE_NO_PREDECESSOR;

    *p_pred_data = p_pred_node->data;
    return SUCCESS;
}

bool_t bst_search(bst_t* p_bst, data_t s_data)
{
    node_t* p_e_node = get_node(p_bst, s_data);
    if(p_e_node == NULL)
        return TRUE;
    else
        return FALSE;    
}

status_t remove_data(bst_t* p_bst, data_t r_data)
{
    node_t* z = NULL;   //pointer to the node to be deleted
    node_t* w = NULL;   //inorder successor of node to be deleted

    z = get_node(p_bst, r_data);
    if(z == NULL)
        return TREE_DATA_NOT_FOUND;
    
    if(z->left == NULL)
    {
        if(z->parent == NULL)   //means z is root node
            p_bst->p_root_node = z->right;
        else if(z == z->parent->left)
            z->parent->left = z->right;
        else
            z->parent->right = z->right;
        //this condition will take care of leaf node
        if(z->right != NULL)
            z->right->parent = z->parent;
    }
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
    else 
    {
        //to find successor of z->right, assign w to z->right (Right SubTree of z)
        w = z->right; 
        while(w->left != NULL)
            w = w->left; 
        
        //if in order successor is not immediate right child of z
        if(z->right != w)
        {
            //two things that we must skip if w is z's immediate right child - do those here
            //w's right's responsibility on its parent
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
    p_bst->nr_of_elements = p_bst->nr_of_elements - 1;
    free(z);
    return SUCCESS;
}

bool_t is_bst_empty(bst_t* p_bst)
{
    if(p_bst->p_root_node == NULL)
        return TRUE;
    else
        return FALSE;
}

len_t find_length(bst_t* p_bst)
{
    return (p_bst->nr_of_elements);
}

//destroy BST tree
void bst_destroy(bst_t** pp_bst)
{
    destroy_node((*pp_bst)->p_root_node);
    free(*pp_bst);
    *pp_bst = NULL;
}
