#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1

typedef int bool_t;
typedef int status_t;

bool_t string_ncompare_ncs(char* p_str1, char* p_str2, long long int n);
status_t string_length(char* p_str, long long int* p_str_len);
void test_string_ncompare_ncs();

int main(void)
{
    test_string_ncompare_ncs();

    exit(EXIT_SUCCESS);
}

bool_t string_ncompare_ncs(char* p_str1, char* p_str2, long long int n)
{
    long long int len_str1 = 0;
    long long int len_str2 = 0;

    string_length(p_str1, &len_str1);
    string_length(p_str2, &len_str2);

    if(len_str1 < n)
        n = len_str1;
    if(len_str2 < n)
        n = len_str2;

    int i;
    bool_t flag = TRUE;
    for(i = 0;i<n;++i)
    {
        printf("p_str1[i] = %c, p_str2[i] = %c\n",p_str1[i], p_str2[i]);
        if(p_str1[i]>='a' && p_str1[i]<='z')
        {
            if((p_str1[i] != p_str2[i]) || (p_str1[i] - 32 != p_str2[i]))
            {
                flag = FALSE;
                break;
            }
        }
        
        else if(p_str1[i]>='A' && p_str1[i]<='A')
        {
            if((p_str1[i] != p_str2[i]) || (p_str1[i] + 32 != p_str2[i]))
            {
                flag = FALSE;
                break;
            }
        }
    }

    return flag;
}

status_t string_length(char* p_str, long long int* p_str_len)
{
    long long int str_len = 0;
    while(p_str[str_len] != '\0')
        str_len = str_len+1;

    *p_str_len = str_len;
    return SUCCESS;
}

void test_string_ncompare_ncs()
{
    char* p_str1 = "Unix Operating System";
    char* p_str2 = "Unix operating system";

    printf("String1: %s\n",p_str1);
    printf("String2: %s\n",p_str2);

    bool_t flag = TRUE;
    printf("Compare %d characters\n",5);
    flag = string_ncompare_ncs(p_str1, p_str2, 5);
    if(flag == TRUE)
        puts("Strings are equal");
    else if(flag == FALSE)
        puts("Strings are not equal");

    printf("Compare %d characters\n",15);
    flag = string_ncompare_ncs(p_str1, p_str2, 15);
    if(flag == TRUE)
        puts("Strings are equal");
    else if(flag == FALSE)
        puts("Strings are not equal");

    printf("Compare %d characters\n",22);
    flag = string_ncompare_ncs(p_str1, p_str2, 22);
    if(flag == TRUE)
        puts("Strings are equal");
    else if(flag == FALSE)
        puts("Strings are not equal");
}