#include<stdio.h>
#include<stdlib.h>

//user defined data type - name 10, 11, 12 as i, j, k
enum demo
{
    i= 10, j, k
};

int main()
{
    printf("%d %d %d\n", i, j, k);
    //10, 11, 12
    return 0;
}