#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i = 20, j = 10;
    printf("%d %d %d %d\n",i/j, -i/j, i/-j, -i/-j);
    //2, -2, -2, 0
    return 0;
}