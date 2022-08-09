#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1
typedef int status_t;

status_t make_string_title_case(char* p_str);
status_t string_length(char* p_str, long long int* p_str_len);
test_make_string_title_case();

int main(void)
{
    test_make_string_title_case();

    exit(EXIT_SUCCESS);
}

status_t make_string_title_case(char* p_str)
{
    long long int str_len = 0;
    string_length(p_str, &str_len);

    int i = 0;
    while(p_str[i] != '\0')
    {
        if((p_str[i] != ' ') && (p_str[i] != '\0'))
        {
            if((p_str[i] >= 'a') && (p_str[i] <= 'z'))
                p_str[i] = p_str[i] - 32;

            while((p_str[i] != ' ') && (p_str[i] != '\0'))
                i = i+1;
        }
        else if((p_str[i] == ' ') && (p_str[i] != '\0'))
        {
            while((p_str[i] == ' ') && (p_str[i] != '\0'))
                i = i+1;
        }
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

test_make_string_title_case()
{
    char* p_str = "unix operating system";
    printf("Original string: %s\n",p_str);

    make_string_title_case(p_str);
    printf("Result string: %s\n",p_str);

    exit(EXIT_SUCCESS);
}


#define IN 1
#define OUT 0
typedef int bool;

status_t make_string_title_case(char* p_str)
{
    long long int str_len = 0;
    string_length(p_str, &str_len);
	bool flag = IN;

    int i = 0;
    while(p_str[i] != '\0')
    {
        if(p_str[i] != ' ' && flag == IN)
        {
            flag = IN
			if((p_str[i] >= 'a') && (p_str[i] <= 'z'))
                p_str[i] = p_str[i] - 32;
			i = i+1;
			
        }
        else if(p_str[i] == ' ')
        {
            flag = OUT;
            i = i+1;
        }
    }

    return SUCCESS;
}



char* get_lstripped_string(char* str)
{
	long long int len_str = cpa_strcpy(str);
	char* str_r = (char*)malloc(len_str + 1);
	
	int flag = TRUE;
	int i = 0, j = 0;
	while(str[i] != '\0')
	{
		if(is_space(str[i] == FALSE) && flag == FALSE)
		{
			str_r[j] = str[i];
			i = i+1;
			j = j+1;
			flag = TRUE;
		}
		else
		{
			str_r[j] = str[i];
			j = j+1;
		}
			
	}
}


