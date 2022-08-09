#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
typedef int status_t;

status_t string_length(char* p_str, long long int* p_str_len);
void test_string_length();

int main(void)
{
    test_string_length();

    exit(EXIT_SUCCESS);
}

status_t string_length(char* p_str, long long int* p_str_len)
{
    long long int str_len = 0;
    while(p_str[str_len] != '\0')
        str_len = str_len+1;

    *p_str_len = str_len;
    return SUCCESS;
}

void test_string_length()
{
    char p_str[100] = "\0";
    long long int str_len = 0;

    printf("Enter string: ");
    scanf("%[^'\n']s",p_str);

    string_length(p_str, &str_len);
    printf("Length of entered string is: %lld\n",str_len);

    exit(EXIT_SUCCESS);
}
