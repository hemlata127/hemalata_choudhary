#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int num = 0x0a0b0c0d;
    if(*((unsigned char*)&num) == 0x0d)
        puts("Little endianness");
    else if(*((unsigned char*)&num) == 0x0a)
        puts("Big endianness");
    else
        puts("Strange machine");

    exit(0);
}