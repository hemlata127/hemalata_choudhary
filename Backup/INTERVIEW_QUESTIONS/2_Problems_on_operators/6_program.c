#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int no = 10;
    printf("%d %d %d\n",~no, !no, ~no+1);
    //~bitwise compliment operator, ! logical not
    //bitwise compliment operator of n = -(n+1)
    //~(10) = -11
    //!(10) = 0
    //~10 + 1 = -10
    //OP: -11 0 10

    exit(EXIT_SUCCESS);
}