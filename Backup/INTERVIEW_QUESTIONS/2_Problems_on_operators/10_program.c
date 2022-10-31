#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i = 21, j = 10;
    printf("%d %d %d %d\n", i*j, -i*j, i*-j, -i*-j);
    //210, -210, -210, 210

    return 0;
}