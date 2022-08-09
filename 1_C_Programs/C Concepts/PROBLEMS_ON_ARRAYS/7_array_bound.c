#include<stdio.h>
#include<stdlib.h>

struct pair
{
    int x;
    int y;
};

struct output
{
    int size;
    struct pair** p_output_array;
};

int* create_array(int N);
void display_array(int* arr, int N, const char* msg);
void destroy_array(int** arr);
struct output* create_output_array();
void add_element(int* arr, int N, struct output* p, int bound_value);
void display_output_array(struct output* p, const char* msg);
void destroy_output_array(struct output** pp);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        puts("INCORRECT COMMAND USAGE");
        printf("USE AS: %s array_size\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);
    if(N <= 0)
    {
        puts("INCORRECT ARRAY SIZE");
        exit(EXIT_FAILURE);
    }

    int* arr = create_array(N);
    display_array(arr, N, "ORIGINAL ARRAY");

    struct output* p_op = create_output_array();
    int bound_value = 0;
    printf("Enter bound value: ");
    scanf("%d",&bound_value);
    add_element(arr, N, p_op, bound_value);
    display_output_array(p_op, "OUTPUT ARRAY");
    
    destroy_array(&arr);
    destroy_output_array(&p_op);

    exit(EXIT_FAILURE);
}

int* create_array(int N)
{
    int* arr = (int*)malloc(N * sizeof(int));
    if(arr == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0;i<N;++i)
        arr[i] = (i+1)*10;

    return arr;
}

void display_array(int* arr, int N, const char* msg)
{
    if(msg)
        puts(msg);

    int i;
    for(i = 0;i<N;++i)
        printf("arr[%d] = %d\n",i, arr[i]);
}

void destroy_array(int** arr)
{
    free(*arr);
    *arr = NULL;
}

struct output* create_output_array()
{
    struct output* p = (struct output*)malloc(sizeof(struct output));
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    p->p_output_array = NULL;
    p->size = 0;

    return p;
}

void add_element(int* arr, int N, struct output* p, int bound_value)
{
    int i, j;
    for(i = 0;i<N;++i)
    {
        for(j = i+1;j<N;++j)
        {
            if(arr[i] + arr[j] > bound_value)
            {
                p->p_output_array = (struct pair**) realloc(p->p_output_array, (p->size + 1) * sizeof(struct pair*));
                p->p_output_array[p->size] = (struct pair*)malloc(sizeof(struct pair));
                p->p_output_array[p->size]->x = arr[i];
                p->p_output_array[p->size]->y = arr[j];

                p->size = p->size + 1;
            }
        }
    }
}

void display_output_array(struct output* p, const char* msg)
{
    if(msg)
        puts(msg);

    int i;
    for(i = 0;i<p->size;++i)
        printf("(%d, %d)\n", p->p_output_array[i]->x, p->p_output_array[i]->y);
}

void destroy_output_array(struct output** pp)
{
    struct output* p = *pp;
    int i;
    for(i = 0;i<p->size;++i)
    {
        free(p->p_output_array[i]);
        p->p_output_array[i] = NULL;
    }

    free(p);
    p = NULL;

    *pp = NULL;
}
