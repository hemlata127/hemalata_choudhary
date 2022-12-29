//include the required header files
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//declare a structure to hold the base address of array and number of elements in the array
struct vector
{
    int* arr;
    int size;
};

//function declarations
struct vector* create_array();
void add_element(struct vector* p, int num);
void display_array(struct vector* p, char* msg);
void destroy_array(struct vector** pp);

//entry point function
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("USAGE ERROR, USE AS: %s number_of_elements\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int count = atoi(argv[1]);
    if(count <= 0)
    {
        puts("Invalid count");
        exit(EXIT_FAILURE);
    }

    struct vector* vector_rand_integers = create_array();

    int i;
    for(i = 0;i<count;i++)
        add_element(vector_rand_integers, rand());

    display_array(vector_rand_integers, "ARRAY OF RANDOM INTEGERS");
    destroy_array(&vector_rand_integers);

    exit(EXIT_SUCCESS);
}

//function to create an object of the structure - struct vector
struct vector* create_array()
{
    struct vector* p = (struct vector*) malloc(sizeof(struct vector));
    assert(p != NULL);

    p->arr = NULL;
    p->size = 0;

    return p;
}

//add a new element to the array dynamically
void add_element(struct vector* p, int num)
{
    p->arr = (int*) realloc(p->arr, (p->size + 1) * sizeof(int));
    assert(p->arr != NULL);

    p->arr[p->size] = num;
    p->size = p->size + 1;
}

//display the array elements
void display_array(struct vector* p, char* msg)
{
    if(msg)
        puts(msg);

    int i;
    for(i = 0;i<p->size;i++)
        printf("arr[%d] = %d\n",i,p->arr[i]);
}

//free the array
void destroy_array(struct vector** pp)
{
    free((*pp)->arr);
    (*pp)->arr = NULL;

    free(*pp);
    *pp = NULL;
}
