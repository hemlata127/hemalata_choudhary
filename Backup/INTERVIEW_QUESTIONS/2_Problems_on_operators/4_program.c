#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int j = (10,20,30,40);
    //assignment operator has right to left precedence
    //j = 40
    printf("%d",j);

    exit(EXIT_SUCCESS);
}