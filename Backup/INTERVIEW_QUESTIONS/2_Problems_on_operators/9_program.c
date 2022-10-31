#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i = 21, j = 10;
    printf("%d %d %d %d\n",i%j, -i%j, i%-j, -i%-j);
    //in case of modulus division, sign of numerator is retained
    //1, -1, 1, -1
    return 0;
}
