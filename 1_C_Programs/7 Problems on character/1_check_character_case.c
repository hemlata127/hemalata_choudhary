/*
Write a C program to find the case of a character
Input: a
Output: SMALL
Input: D
Output: CAPITAL
Input: &
Output: &
*/
#include<stdio.h>
#include<stdlib.h>

#define CAPITAL 1
#define SMALL 0

typedef int case_t;

case_t FindCase(char ch);

int main(void)
{
    char ch = '\0';
    case_t result;
    printf("Enter a character: ");
    scanf("%c",&ch);

    result = FindCase(ch);
    if(result == SMALL)
        puts("SMALL");
    else if(result == CAPITAL)
        puts("CAPITAL");
    else
        printf("%c\n",ch);

    exit(EXIT_SUCCESS);
}

case_t FindCase(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return SMALL;
    else if(ch >= 'A' && ch <= 'Z')
        return CAPITAL;
    else 
        return -1;
}
