#include<stdio.h>
#include<stdlib.h>

enum demo
{
    i = 10, j, k
};

int main(void)
{
    printf("%zd %zd\n",sizeof(enum demo),sizeof(i));
    //4 4
    exit(EXIT_SUCCESS);
}
