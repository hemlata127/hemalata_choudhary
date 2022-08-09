#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void* xmalloc(size_t nr_of_bytes);
void* xcalloc(size_t nr_of_elements, size_t size_per_element);
void* xrealloc(void* old_addr, size_t nr_of_bytes);

size_t my_strlen(char* msg);
char* my_strcpy(char* src_str, char* dest_str);
char* my_strcat(char* str1, char* str2);
char* my_strbuilder(char* p_str, const char* append_str);

int main(void)
{
    char* msg = "This is interesting, isn't it?";
    unsigned long long int len = 0;

    len = my_strlen(msg);
    printf("String length = %llu\n",len);

    char* dest_str = NULL;
    dest_str = my_strcpy(msg, dest_str);
    printf("Original string = %s\n",msg);
    printf("Copied string = %s\n",dest_str);

    char* str1 = "Unix Operation system ";
    char* str2 = "By Dennis Ritchie and Ken Thompsom";
    char* str3 = NULL;
    str3 = my_strcat(str1, str2);
    printf("Concatenated string: %s\n",str3);

    char* p_str = NULL;
    p_str = my_strbuilder(p_str, "Hello");
    printf("p_str = %s\n",p_str);
    p_str = my_strbuilder(p_str, "world");
    printf("p_str = %s\n",p_str);

    exit(EXIT_SUCCESS);
}

size_t my_strlen(char* msg)
{
    size_t len = 0;
    while(*msg != '\0')
    {
        len = len+1;
        msg++;
    }

    return len;
}

char* my_strcpy(char* src_str, char* dest_str)
{
    size_t src_size = my_strlen(src_str);

    dest_str = (char*)xmalloc(src_size * sizeof(char));
    int i;
    for(i = 0;i<src_size;i++)
        dest_str[i] = src_str[i];

    dest_str[i] = '\0';

    return dest_str;
}

char* my_strcat(char* str1, char* str2)
{
    size_t len1, len2, len3;
    len1 = my_strlen(str1);
    printf("len1 = %llu\n",len1);
    len2 = my_strlen(str2);
    printf("len2 = %llu\n",len2);
    len3 = len1+len2;
    printf("len3 = %llu\n",len3);

    char* str = (char*)xmalloc(len3+1);

    size_t i = 0;
    for(i = 0;i<len1;++i)
        str[i] = str1[i];
        
    for(i = 0;i<len2;i++)
        str[len1+i] = str2[i];
        
    str[len3] = '\0';

    return str;
}

char* my_strbuilder(char* p_str, const char* append_str)
{
    size_t current_length, additional_length, total_length;
    size_t i;

    current_length = (p_str == NULL) ? 0 : my_strlen(p_str);
    additional_length = (append_str == NULL) ? 0 : my_strlen(append_str);
    total_length = current_length + additional_length;

    p_str = (char*)xrealloc(p_str, total_length+1);

    for(i = 0;i<additional_length;++i)
        *(p_str + current_length + i) = *(append_str + i);
    
    *(p_str + total_length) = '\0';

    return (p_str);
}

void* xmalloc(size_t nr_of_bytes)
{
    void* p = malloc(nr_of_bytes);
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    return p;
}

void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void* p = calloc(nr_of_elements, size_per_element);
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    return p;
}

void* xrealloc(void* old_addr, size_t nr_of_bytes)
{
    void* p = realloc(old_addr, nr_of_bytes);
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    return p;
}
