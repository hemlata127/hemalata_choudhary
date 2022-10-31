#include<stdio.h>
#include<stdlib.h>

int fun()
{
    return (10,20,30,40);
    //this is also like assignment, return value is assigned into a register
    //assignment operator has right to left precedence
}

int gun()
{
    return (10,20,30,40);
}

int main(void)
{
    printf("%d %d\n",fun(), gun());
    //40 40

    exit(EXIT_SUCCESS);
}