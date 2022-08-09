#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1
typedef int status_t;

status_t get_upper_string(char* p_str, char** pp_upper_str);
status_t string_length(char* p_str, long long int* p_str_len);
test_get_upper_string();

int main(void)
{
    test_get_upper_string();

    exit(EXIT_SUCCESS);
}

status_t get_upper_string(char* p_str, char** pp_upper_str)
{
    long long int str_len = 0;
    string_length(p_str, &str_len);

    char* p_upper_str = (char*)malloc(str_len * sizeof(char));
    assert(p_upper_str);

    int i;
    for(i = 0;i<str_len;++i)
    {
        if(p_str[i] >= 'a' && p_str[i] <= 'z')
            p_upper_str[i] = p_str[i] - 32;
        else
            p_upper_str[i] = p_str[i];
    }

    *pp_upper_str = p_upper_str;

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

test_get_upper_string()
{
    char* p_str = "Unix Operating System";
    char* p_upper_str = NULL;

    get_upper_string(p_str, &p_upper_str);
    printf("Original string: %s\n",p_str);
    printf("Result string: %s\n",p_upper_str);

    exit(EXIT_SUCCESS);
}
