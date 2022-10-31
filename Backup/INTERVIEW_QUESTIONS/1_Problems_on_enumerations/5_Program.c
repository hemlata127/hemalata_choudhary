#include<stdio.h>
#include<stdlib.h>

enum demo
{
    i,j,k
};

int main(void)
{
    printf("%u %u\n",&(demo),&i);

    exit(EXIT_SUCCESS);
}