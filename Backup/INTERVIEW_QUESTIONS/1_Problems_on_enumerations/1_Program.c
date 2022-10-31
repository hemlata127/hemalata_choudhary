#include<stdio.h>
#include<stdlib.h>

//user defined data type
//constant integers are given names - here 0, 1, 2 are named i, j, k
enum demo
{
    i,j,k
};

int main(void)
{
    printf("%d %d %d\n",i,j,k);
    //0, 1, 2

    exit(EXIT_SUCCESS);
}