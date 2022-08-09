#include<stdio.h>
#include<stdlib.h>

int func(int);

int main(void)
{
    //1. declare a pointer to an integer
    int* p1 = NULL;

    //2. declare an array of 5 integers
    int arr1[5];

    //3. declare an array 5 of pointers to integers
    int *arr2[5];

    //4. declare pointer to array of 5 integers
    int (*p2)[5];

    //5. Declare a pointer to array 5 of pointers to int
    int *((*p3)[5]);

    //6 Declare a function accepting two ints returning int
    int fun1(int, int);

    //7 Declare a pointer to function accepting two ints returning int
    int (*p4)(int, int);

    //8 Declare an array 5 of pointer to function accepting two ints returning int
    int (*arr3[5])(int, int);

    //9 Declare a pointer to array 5 of pointer to function accepting two ints returning an int
    int (*(*p5)[5])(int, int);

    //10 Declare a function accepting void returning pointer to array of pointer to function 
    //accepting two integers and returning integer 
    int (*(*fun2(void))[])(int, int);

    //11 p is a pointer to array 5 of pointer to function accepting int, int and returning pointer 
    //to array 3 of pointer to function accepting void returning char  
    char (*(*(*(*p6)[5])(int,int))[3])(void);
    

    //12 x is a function returning pointer to array 5 of pointer to function accepting int and 
    //returning pointer to int 
    int *(*(*x())[5])(int);

    //13 arr is array 5 of pointer to function returning pointer to array 3 of pointer to function 
    //returning pointer to array 5 of pointer to array 3 of char 
    char (*(*(*(*(*arr4[5])())[3])())[5])[3];
    
    //14 Write a function which returns a pointer to array 5 of pointer to function accepting int, int and returning 
    //pointer to array 3 of pointer to function accepting void returning char 
    char (*(*(*(*fun3())[5])(int, int))[3])(void);

    //15 Declare a pointer to a function which returns a pointer to array 5 of pointer to function 
    //accepting int, int and returning 
    //pointer to array 3 of pointer to function accepting void returning char 
    char (*(*(*(*(*p7)())[5])(int, int))[3])(void);

    //16. Declare a pointer to a function returning pointer to array 5 of pointer to function 
    //accepting int and returning pointer to int 
    int *(*(*(*p8)())[5])(int);

    //17. Declare a pointer to array 5 of pointer to function returning pointer to array 3 of pointer to 
    //function returning pointer to array 5 of pointer to array 3 of char 
    char (*(*(*(*(*(*p9)[5])())[3])())[5])[3];

    //18. Declare a const pointer to int 
    int num = 10;
    int *const p = &num;

    //19. Declare a pointer to const int 
    const int *p10;

    //20. declare a const pointer to const int 
    const int *const p11 = &num;

    //21. Declare a const pointer to array 5 of int
    int (*const p12)[5] = &arr1;

    //22. Declare a pointer to array of const int 
    const int (*p13)[];

    //23. Declare a const pointer to array of const int  
    const int (*const p14)[5] = &arr1;

    //24. Declare a const pointer to function accepting int returning int 
    int (*const p15)(int);

    //25. Declare a const pointer to function accepting const int and returning pointer to const int 
    const int *(*const p16)(const int);

    //26. Declare a const pointer to function accepting const int and returning const pointer to array 5 of const int 
    const int (*const (*const p17)(const int))[5];

    exit(EXIT_SUCCESS);
}