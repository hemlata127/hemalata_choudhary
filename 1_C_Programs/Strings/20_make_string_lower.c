#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1
typedef int status_t;

status_t make_string_lower(char* p_str);
status_t string_length(char* p_str, long long int* p_str_len);
test_make_string_lower();

int main(void)
{
    test_make_string_lower();

    exit(EXIT_SUCCESS);
}

status_t make_string_lower(char* p_str)
{
    long long int str_len = 0;
    string_length(p_str, &str_len);

    int i;
    for(i = 0;i<str_len;++i)
    {
        if(p_str[i] >= 'A' && p_str[i] <= 'Z')
            p_str[i] = p_str[i] + 32;
    }

    return SUCCESS;
}

status_t string_length(char* p_str, long long int* p_str_len)
{
    long long int str_len = 0;
    while(p_str[str_len] != '\0')
        str_len = str_len+1;

    *p_str_len = str_len;
    return SUCCESS;
}

test_make_string_lower()
{
    char* p_str = "Unix Operating System";
    printf("Original string: %s\n",p_str);

    make_string_lower(p_str);
    printf("Result string: %s\n",p_str);

    exit(EXIT_SUCCESS);
}
