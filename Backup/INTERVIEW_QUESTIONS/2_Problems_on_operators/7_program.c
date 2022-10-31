#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i = 10, j = 20, ans;
    ans = (++i || --j)&&(++i || --j);
    //--j in both brackets will not be executed as ++i becomes non zero
    //ans = 11 (non zero) && 12 (non zero) = 11
    //ans = 1, i = 12, j = 20
    printf("%d %d %d\n",i,j,ans);
    //12 20 1

    exit(EXIT_SUCCESS);
}