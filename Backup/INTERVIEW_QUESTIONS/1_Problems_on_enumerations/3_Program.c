#include<stdio.h>
#include<stdlib.h>

//user defined data type to name symbolic constants 10, 11, 12 as i, j, k
enum demo
{
    i = 10, j, k
};

int main(void)
{
    //override the value of i
    int i = 51;
    printf("%d %d %d\n",i, j, k);
    //51, 11, 12

    exit(EXIT_SUCCESS);
}