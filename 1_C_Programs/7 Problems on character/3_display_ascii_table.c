/*
Write a a C program to display ASCII table
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i;
    for(i = 0;i<256;i++)
        printf("ASCII value: %d, Character: %c\n",i,(char)i);

    exit(EXIT_SUCCESS);
}
