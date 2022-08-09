#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1

typedef int status_t;

status_t allocate_string(char** pp_str, long long int str_len, char init_char);
void test_allocate_string();

int main(void)
{
    test_allocate_string();

    exit(EXIT_SUCCESS);
}

status_t allocate_string(char** pp_str, long long int str_len, char init_char)
{
    char* p_str = (char*) malloc(str_len+1 * sizeof(char));
    assert(p_str != NULL);

    int i;
    for(i = 0;i<str_len;++i)
        p_str[i] = init_char;

    p_str[str_len] = '\0';

    *pp_str = p_str;

    return SUCCESS;
}

void test_allocate_string()
{
    long long int str_len;
    char init_char;

    printf("Enter string length: ");
    scanf("%lld",&str_len);
    getchar();
    printf("Enter initialise character: ");
    scanf("%c",&init_char);

    char* p_str = NULL;
    allocate_string(&p_str, str_len, init_char);
    printf("Allocated string is: %s\n",p_str);

    free(p_str);
}
