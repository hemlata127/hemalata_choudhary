#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i = 10;
    int j = sizeof(i = i-2)+32;
    //j = sizeof(i = 10-2)+32;
    //j = sizeof(8)+32;
    //j = 4+32;
    //j = 36
    printf("%d %d",i,j);
    //10, 36
    exit(EXIT_SUCCESS);
}