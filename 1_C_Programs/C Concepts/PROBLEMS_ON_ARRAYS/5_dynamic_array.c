#include<stdio.h>
#include<stdlib.h>

struct vector
{
    int size;
    int* arr;
};

struct vector* create_array();
void add_element(struct vector* p, int num);
void display_array(struct vector* p, const char* msg);
void destroy_array(struct vector** pp);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        puts("INCORRECT COMMAND USAGE");
        printf("USE AS: %s array_size", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);
    if(N <= 0)
    {
        puts("Incorrect array size");
        exit(EXIT_FAILURE);
    }

    struct vector* even_array = create_array();
    struct vector* odd_array = create_array();

    int i, num;
    for(i = 0;i<N;++i)
    {
        num = rand();
        if(num%2 == 0)
            add_element(even_array, num);
        else
            add_element(odd_array, num);
    }

    display_array(even_array, "ARRAY OF EVEN ELEMENTS");
    display_array(odd_array, "ARRAY OF ODD ELEMENTS");

    destroy_array(&even_array);
    destroy_array(&odd_array);
}

struct vector* create_array()
{
    struct vector* p = (struct vector*)malloc(sizeof(struct vector));
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    p->arr = NULL;
    p->size = 0;

    return p;
}

void add_element(struct vector* p, int num)
{
    p->arr = (int*) realloc(p->arr, (p->size + 1) * sizeof(int));
    if(p->arr == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }
    p->arr[p->size] = num;
    p->size = p->size + 1;
}

void display_array(struct vector* p, const char* msg)
{
    if(msg)
        puts(msg);

    int i;
    for(i = 0;i<p->size;++i)
        printf("arr[%d] = %d\n",i,p->arr[i]);
}

void destroy_array(struct vector** pp)
{
    free((*pp)->arr);
    (*pp)->arr = NULL;

    *pp = NULL;
}
