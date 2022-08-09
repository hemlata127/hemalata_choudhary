#include "strings.h"

//auxillary function definitions
static void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void* p = NULL;
    p = calloc(nr_of_elements, size_per_element);
    if(p == NULL)
    {
        puts("MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }

    return p;
}

static void* xrealloc(void* old_address, size_t new_size)
{
    void* new_address = NULL;
    new_address = realloc(old_address, new_size);
    if(new_address == NULL)
    {
        puts("REALLOC FAILED");
        exit(EXIT_FAILURE);
    }
    return new_address;
}

static bool_t is_char_lower(schar_t ch)
{
    if(ch >= 'a' && ch <= 'z')
        return TRUE;
    else 
        return FALSE;
}

static bool_t is_char_upper(schar_t ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return TRUE;
    else
        return FALSE;
}

static bool_t is_char_digit(schar_t ch)
{
    if(ch >= '0' && ch <= '9')
        return TRUE;
    else    
        return FALSE;
}

static bool_t is_char_space(schar_t ch)
{
    if(ch == ' ')
        return TRUE;
    else
        return FALSE;
}

static schar_t to_lower_char(schar_t ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return (ch + 32);
    else
        return ch;
}

static schar_t to_upper_char(schar_t ch)
{
    if(ch >= 'a' && ch <= 'z')
        return (ch - 32);
    else
        return ch;
}

//=======================================================================
//interface function definitions
status_t allocate_string(len_t size, schar_t** pp_str)
{
    schar_t* p_str = NULL;
    p_str = (schar_t*)xcalloc(size, sizeof(schar_t));
    *pp_str = p_str;
    return SUCCESS;
}

status_t string_length(const schar_t* p_str, len_t* p_len)
{
    len_t len = 0;
    while(p_str[len] != '\0')
        len = len+1;
    *p_len = len;
    return SUCCESS;
}

status_t string_ncompare_cs(const schar_t* p_str_1, const schar_t* p_str_2, uint_t n)
{
    len_t len1, len2, len;
    string_length(p_str_1, &len1);
    string_length(p_str_2, &len2);

    //len should be minimum of len1, len2, n
    if(len1<=len2 && len1<=n)
        len = len1;
    else if(len2<=len1 && len2<=n)
        len = len2;
    else
        len = n;

    status_t flag = TRUE;
    uint_t i;
    for(i = 0; i<len; ++i)
    {
        if(p_str_1[i] != p_str_2[i])
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t string_ncompare_ncs(const schar_t* p_str_1, const schar_t* p_str_2, uint_t n)
{
    len_t len1, len2, len;
    string_length(p_str_1, &len1);
    string_length(p_str_2, &len2);

    //len should be minimum of len1, len2, n
    if(len1<=len2 && len1<=n)
        len = len1;
    else if(len2<=len1 && len2<=n)
        len = len2;
    else
        len = n;

    status_t flag = TRUE;
    uint_t i;
    for(i = 0; i<len; ++i)
    {
        if(to_lower_char(p_str_1[i]) != to_lower_char(p_str_2[i]))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t string_compare_cs(const schar_t* p_str_1, const schar_t* p_str_2)
{
    len_t len1, len2, len;
    string_length(p_str_1, &len1);
    string_length(p_str_2, &len2);

    //len should contain smaller of len1 and len2
    if(len1<=len2)
        len = len1;
    else 
        len = len2;

    uint_t i;
    status_t flag = TRUE;
    for(i = 0; i<len; ++i)
    {
        if(p_str_1[i] != p_str_2[i])
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t string_compare_ncs(const schar_t* p_str_1, const schar_t* p_str_2)
{
    len_t len1, len2, len;
    string_length(p_str_1, &len1);
    string_length(p_str_2, &len2);

    //len should have smaller of len1 and len2
    if(len1 <= len2)
        len = len1;
    else
        len = len2;

    uint_t i;
    status_t flag = TRUE;
    for(i = 0; i<len; ++i)
    {
        if(to_lower_char(p_str_1[i]) != to_lower_char(p_str_2[i]))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t get_concatenated_string(const schar_t* p_str_1, const schar_t* p_str_2, schar_t** pp_str_concat)
{
    len_t len1, len2, len;
    string_length(p_str_1, &len1);
    string_length(p_str_2, &len2);
    len = len1+len2;
    schar_t* p_str_concat = NULL;
    p_str_concat = (schar_t*)xcalloc(len+1, sizeof(schar_t));
    uint_t i;
    for(i = 0; i<len1; ++i)
        p_str_concat[i] = p_str_1[i];
    for(i = 0; i<len2; ++i)
        p_str_concat[len1+i] = p_str_2[i];

    p_str_concat[len] = '\0';
    *pp_str_concat = p_str_concat;
    return SUCCESS;
}

status_t string_append(schar_t* p_str_1, const schar_t* p_str_2, uint_t* p_new_size)
{
    len_t len1, len2;
    string_length(p_str_1, &len1);
    string_length(p_str_2, &len2);

    uint_t i;
    for(i = 0; i<len2; ++i)
        p_str_1[len1+i] = p_str_2[i];
    p_str_1[len1+len2] = '\0';
    *p_new_size = len1+len2;
    return SUCCESS;
}

status_t string_multiply(const schar_t* p_str, schar_t** pp_str_result, uint_t n)
{
    len_t len, len_result;
    string_length(p_str, &len);
    len_result = len * n;
    schar_t* p_str_result = NULL;
    p_str_result = (schar_t*)xcalloc(len_result + 1, sizeof(schar_t));
    uint_t i, j;
    for(i = 0; i<n; ++i)
    {
        for(j = 0; j<len; ++j)
        {
            p_str_result[(len*i) + j] = p_str[j];
        }
    }
    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t get_char_by_index(const schar_t* p_str, uint_t index, schar_t* p_ch)
{
    len_t len;
    string_length(p_str, &len);
    if(index >= len)
    {
        puts("INDEX IS OUT OF RANGE");
        return FAILURE;
    }
    *p_ch = p_str[index];
    return SUCCESS;
}

status_t get_substring_by_range(const schar_t* p_str, uint_t start_index, uint_t end_index, schar_t** pp_substr)
{
    len_t len, len_substr;
    string_length(p_str, &len);
    if(start_index < 0 || end_index >= len || start_index > end_index || start_index > len)
    {
        puts("Invalid range");
        return FAILURE;
    }    
    uint_t i;
    schar_t* p_substr = NULL;
    len_substr = end_index - start_index + 1;
    p_substr = (schar_t*)xcalloc(len_substr+1, sizeof(schar_t));
    for(i = 0; i<len_substr; ++i)
        p_substr[i] = p_str[start_index+i];
    *pp_substr = p_substr;
    return SUCCESS;
}

status_t get_substring_by_slice(const schar_t* p_str, uint_t start_index, uint_t end_index, uint_t step, schar_t** pp_substr)
{
    len_t len, len_substr;
    string_length(p_str, &len);
    if(start_index < 0 || end_index >= len || start_index>end_index || start_index>=len || end_index>=len || step >= len)
    {
        puts("Invalid index or step value");
        return FAILURE;
    }

    schar_t* p_substr = NULL;
    uint_t i, j;
    i = start_index;
    len_substr = 0;
    while(i < end_index)
    {
        p_substr = xrealloc(p_substr, len_substr+1);
        p_substr[len_substr] = p_str[i];
        len_substr = len_substr + 1;
        for(j = 0; j<step; ++j)
            i = i+1;
    }
    p_substr[len_substr] = '\0';
    *pp_substr = p_substr;
    return SUCCESS;
}

status_t is_substring(const schar_t* p_str, const schar_t* p_substr)
{
    len_t len, len_substr;
    string_length(p_str, &len);
    string_length(p_substr, &len_substr);
    if(len_substr > len)
    {
        puts("Substring is longer than string");
        return FAILURE;
    }

    uint_t i, j;
    status_t flag;
    for(i = 0; i<=(len - len_substr); ++i)
    {
        flag = TRUE;
        for(j = 0; p_substr[j] != '\0'; ++j)
        {
            if(p_str[i+j] != p_substr[j])
            {
                flag = FALSE;
                break;
            }
        }
        if(flag == TRUE)
            return TRUE;
    }
    return FALSE;
}

status_t substring_index(const schar_t* p_str, const schar_t* p_substr, uint_t index)
{
    len_t len, len_substr;
    string_length(p_str, &len);
    string_length(p_substr, &len_substr);
    if(len_substr > len)
    {
        puts("Substring is longer than string");
        return FAILURE;
    }
    if(index > len)
    {
        puts("Index is out of range");
        return FAILURE;
    }

    uint_t i;
    status_t flag = TRUE;
    for(i = 0; i< (len_substr); ++i)
    {
        if(p_str[index+i] != p_substr[i])
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t substring_count(const schar_t* p_str, const schar_t* p_substr, uint_t* p_count)
{
    len_t len, len_substr;
    uint_t i, j, count = 0;
    status_t flag;
    string_length(p_str, &len);
    string_length(p_substr, &len_substr);
    
    for(i = 0; i<=(len-len_substr);++i)
    {
        flag = TRUE;
        for(j = 0; j<len_substr; ++j)
        {
            if(p_str[i+j] != p_substr[j])
            {
                flag = FALSE;
                break;
            }
        }
        if(flag == TRUE)
            count = count+1;
    }
    *p_count = count;
    return SUCCESS;
}

status_t make_string_reverse(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    uint_t i, j;
    schar_t temp;
    for(i = 0, j = len-1; i<j; ++i, --j)
    {
        temp = p_str[i];
        p_str[i] = p_str[j];
        p_str[j] = temp;
    }    
    return SUCCESS;
}

status_t get_reverse_string(const schar_t* p_str, schar_t** pp_str_reverse)
{
    len_t len;
    uint_t i, j;
    schar_t* p_str_reverse = NULL;
    string_length(p_str, &len);
    p_str_reverse = (schar_t*)xcalloc(len+1, sizeof(schar_t));
    
    for(i = 0, j = len-1; i<len; ++i, --j)
        p_str_reverse[i] = p_str[j];
    
    p_str_reverse[len] = '\0';
    *pp_str_reverse = p_str_reverse;
    return SUCCESS;
}

status_t make_string_range_reverse(schar_t* p_str, uint_t start_index, uint_t end_index)
{
    len_t len;
    uint_t i, j;
    schar_t temp;
    string_length(p_str, &len);
    if(start_index < 0 || start_index > len || start_index > end_index || end_index >= len)
    {
        puts("Invalid range");
        return FAILURE;
    }    
    for(i = start_index, j = end_index; i<j; ++i, --j)
    {
        temp = p_str[i];
        p_str[i] = p_str[j];
        p_str[j] = temp;
    }
    return SUCCESS;
}

status_t string_ncopy(schar_t* p_str_src, schar_t** pp_str_dest, uint_t n)
{
    len_t len_src, len_dest;
    uint_t i;
    schar_t* p_str_dest;
    string_length(p_str_src, &len_src);
    if(len_src <= n)
        len_dest = len_src;
    else
        len_dest = n;

    p_str_dest = (schar_t*)xcalloc(len_dest, sizeof(schar_t));
    for(i = 0; i<len_dest; ++i)
        p_str_dest[i] = p_str_src[i];
    p_str_dest[len_dest] = '\0';
    *pp_str_dest = p_str_dest;
    return SUCCESS;
}

status_t clone_string(const schar_t* p_str_src, schar_t** pp_str_clone)
{
    len_t len_src, len_dest;
    schar_t* p_str_clone = NULL;
    uint_t i;
    string_length(p_str_src, &len_src);
    len_dest = len_src;
    p_str_clone = (schar_t*)xcalloc(len_dest+1, sizeof(schar_t));
    for(i = 0; i<len_dest; ++i)
        p_str_clone[i] = p_str_src[i];
    p_str_clone[len_dest] = '\0';
    *pp_str_clone = p_str_clone;
    return SUCCESS;
}

status_t get_upper_string(schar_t* p_str, schar_t** pp_str_result)
{
    len_t len_src;
    schar_t* p_str_result = NULL;
    uint_t i;
    string_length(p_str, &len_src);
    p_str_result = (schar_t*)xcalloc(len_src+1, sizeof(schar_t));
    for(i = 0; i<len_src; ++i)
        p_str_result[i] = to_upper_char(p_str[i]);
    p_str_result[len_src] = '\0';
    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t make_string_upper(schar_t* p_str)
{
    len_t len;
    uint_t i;
    string_length(p_str, &len);
    for(i = 0; i<len; ++i)
        p_str[i] = to_upper_char(p_str[i]);
    return SUCCESS;
}

status_t get_lower_string(schar_t* p_str, schar_t** pp_str_result)
{
    len_t len_src;
    schar_t* p_str_result = NULL;
    uint_t i;
    string_length(p_str, &len_src);
    p_str_result = (schar_t*)xcalloc(len_src+1, sizeof(schar_t));
    for(i = 0; i<len_src; ++i)
        p_str_result[i] = to_lower_char(p_str[i]);
    p_str_result[len_src] = '\0';
    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t make_string_lower(schar_t* p_str)
{
    len_t len;
    uint_t i;
    string_length(p_str, &len);
    for(i = 0; i<len; ++i)
        p_str[i] = to_lower_char(p_str[i]);
    return SUCCESS;
}

status_t get_title_case_string(schar_t* p_str, schar_t** pp_str_result)
{
    len_t len;
    schar_t* p_str_result = NULL;
    status_t flag;
    uint_t i;
    string_length(p_str, &len);
    p_str_result = (schar_t*)xcalloc(len+1, sizeof(schar_t));
    flag = OUT;
    for(i = 0; i<len; ++i)
    {
        if(flag == OUT && !is_char_space(p_str[i]))
        {
            flag = IN;
            p_str_result[i] = to_upper_char(p_str[i]);
        }
        else if(flag == IN && is_char_space(p_str[i]))
        {
            flag = OUT;
            p_str_result[i] = p_str[i];
        }
        else
        {
            p_str_result[i] = p_str[i];
        }
    }
    p_str_result[len] = '\0';
    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t make_string_title_case(schar_t* p_str)
{
    len_t len;
    uint_t i;
    status_t flag = OUT;
    string_length(p_str, &len);
    
    for(i = 0; i<len; ++i)
    {
        if(flag == OUT && !is_char_space(p_str[i]))
        {
            flag = IN;
            p_str[i] = to_upper_char(p_str[i]);
        }
        else if(flag == IN && is_char_space(p_str[i]))
        {
            flag = OUT;
        }
    }   
    return SUCCESS; 
}

status_t get_lstriped_string(schar_t* p_str, schar_t** pp_str_result)
{
    len_t len, len_result;
    uint_t index = 0, i;
    schar_t* p_str_result;
    string_length(p_str, &len);
    p_str_result = (schar_t*)xcalloc(len+1, sizeof(schar_t));
    for(i = 0; i<len; ++i)
    {
        if(
            is_char_space(p_str[i]) && (!is_char_space(p_str[i+1]) && p_str[i+1] != '\0')
            )
        {
            index = i+1;
            break;
        }
    }
    
    len_result = len - index;

    for(i = 0; i<len; ++i)
        p_str_result[i] = p_str[index+i];

    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t make_string_lstriped(schar_t* p_str)
{
    len_t len;
    uint_t i, index = 0;
    string_length(p_str, &len);
    for(i = 0; i<len; ++i)
    {
        if(is_char_space(p_str[i]) && !is_char_space(p_str[i+1]))
        {
            index = i+1;
            break;
        }
    }
    for(i = 0; i<len; ++i)
        p_str[i] = p_str[i+index];
    return SUCCESS;
}

status_t get_rstriped_string(schar_t* p_str, schar_t** pp_str_result)
{
    len_t len;
    schar_t* p_str_result = NULL;
    uint_t index = 0, i;
    status_t flag = OUT;
    string_length(p_str, &len);
    p_str_result = (schar_t*)xcalloc(len+1, sizeof(schar_t));
    for(i = 0; i<len; ++i)
    {
        if(flag == OUT && !is_char_space(p_str[i]))
            flag = IN;
        else if((flag == IN && is_char_space(p_str[i+1])) || p_str[i+1] == '\0')
        {
            flag = OUT;
            index = i;
        }
    }
    
    for(i = 0; i<=index; ++i)
        p_str_result[i] = p_str[i];
    p_str_result[index+1] = '\0';
    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t make_string_rstriped(schar_t* p_str)
{
    len_t len;
    uint_t index = 0, i;
    status_t flag = OUT;
    string_length(p_str, &len);
    for(i = 0; i<len; ++i)
    {
        if(flag == OUT && !is_char_space(p_str[i]))
            flag = IN;
        else if((flag == IN && is_char_space(p_str[i+1])) || p_str[i+1] == '\0')
        {
            flag = OUT;
            index = i;
        }
    }
    p_str[index+1] = '\0';
    return SUCCESS;
}

status_t get_striped_string(schar_t* p_str, schar_t** pp_str_result)
{
    schar_t* p_str_result = *pp_str_result;
    get_lstriped_string(p_str, &p_str_result);
    get_rstriped_string(p_str_result, &p_str_result);
    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t make_string_striped(schar_t* p_str)
{
    make_string_lstriped(p_str);
    make_string_rstriped(p_str);
    return SUCCESS;
}

status_t get_case_swapped_string(schar_t* p_str, schar_t** pp_str_result)
{
    len_t len;
    schar_t* p_str_result = NULL;
    uint_t i;
    string_length(p_str, &len);
    p_str_result = (schar_t*)xcalloc(len+1, sizeof(schar_t));
    for(i = 0; i<len; ++i)
    {
        if(is_char_lower(p_str[i]))
            p_str_result[i] = to_upper_char(p_str[i]);
        else if(is_char_upper(p_str[i]))
            p_str_result[i] = to_lower_char(p_str[i]);
        else
            p_str_result[i] = p_str[i];
    }
    p_str_result[len] = '\0';
    *pp_str_result = p_str_result;
    return SUCCESS;
}

status_t make_string_case_swapped(schar_t* p_str)
{
    len_t len;
    uint_t i;
    string_length(p_str, &len);
    for(i = 0; i<len; ++i)
    {
        if(is_char_lower(p_str[i]))
            p_str[i] = to_upper_char(p_str[i]);
        else if(is_char_upper(p_str[i]))
            p_str[i] = to_lower_char(p_str[i]);
    }
    return SUCCESS;
}

status_t split_string(const schar_t* p_str, const schar_t* p_sep, schar_t*** ppp_str, uint_t* p_size)
{
    schar_t** pp_str = NULL; 
    uint_t size = 0; 
    uint_t start_index, end_index, k, saved_k; 
    uint_t component_len, i, j, sep_len, orig_str_len; 
    schar_t* p_component; 
    status_t flag; 

    start_index = 0; 
    string_length(p_sep, &sep_len); 
    string_length(p_str, &orig_str_len);

    k = start_index; 
    while(k < orig_str_len && p_str[k] != '\0') 
    {
        flag = 1; 
        for(j = 0; p_sep[j] != '\0'; ++j)
        {
            if(p_str[k + j] != p_sep[j])
            {
                flag = 0; 
                break; 
            }
        }

        if(flag == 1)
        {
            end_index = k-1; 
            component_len = end_index - start_index + 1; 
            if(component_len == 0)
            {
                start_index = end_index + sep_len + 1; 
                k = start_index; 
                continue; 
            }
            p_component = (schar_t*)xcalloc(1, component_len + 1); 
            for(i = 0; i < component_len; ++i)
                p_component[i] = p_str[start_index + i]; 
            size += 1; 
            pp_str = (schar_t**)xrealloc(pp_str, size * sizeof(schar_t*)); 
            pp_str[size-1] = p_component; 
            p_component = NULL; 
            start_index = end_index + sep_len + 1; 
            k = start_index; 
            saved_k = k; 
        }
        else
        {
            k += 1; 
        }
    }

    if(saved_k < orig_str_len)
    {
        component_len = orig_str_len - saved_k + 1; 
        p_component = (schar_t*)xcalloc(1, component_len + 1); 
        
        for(i = 0; i < component_len; ++i)
            p_component[i] = p_str[start_index + i]; 
        size += 1; 
        pp_str = (schar_t**)xrealloc(pp_str, size * sizeof(schar_t*)); 
        
        pp_str[size-1] = p_component; 
        p_component = NULL; 
    }

    *ppp_str = pp_str; 
    *p_size = size; 

    return (1); 
}

status_t count_words(const schar_t* p_str, uint_t* p_count)
{
    len_t len;
    uint_t count = 0, i;
    status_t flag = OUT;
    string_length(p_str, &len);
    for(i = 0; i<len; ++i)
    {
        if(flag == OUT && !is_char_space(p_str[i]))
        {
            flag = IN;
            count = count+1;
        }
        else if(flag == IN && is_char_space(p_str[i]))
            flag = OUT;
    }
    *p_count = count;
    return SUCCESS;
}

status_t reverse_each_word(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    status_t flag = OUT;
    uint_t start_index, end_index, i;
    for(i = 0; i<len; ++i)
    {
        //start_index = 0, end_index = 0;
        if(flag == OUT && !is_char_space(p_str[i]))
        {
            start_index = i;
            flag = IN;
        }
        else if(flag == IN && is_char_space(p_str[i]))
        {
            flag = OUT;
            if(flag == OUT || p_str[i] == '\0')
                end_index = i-1;
            make_string_range_reverse(p_str, start_index, end_index);
        }
    }
    end_index = i-1;
    make_string_range_reverse(p_str, start_index, end_index);

    return SUCCESS;
}

status_t starts_with(schar_t* p_str, schar_t* p_str_prefix)
{
    status_t status;
    status = substring_index(p_str, p_str_prefix, 0);
    if(status == TRUE)
        return TRUE;
    else
        return FALSE;
}

status_t ends_with(schar_t* p_str, schar_t* p_str_suffix)
{
    len_t len_str, len_substr;
    uint_t index;
    status_t status;
    string_length(p_str, &len_str);
    string_length(p_str_suffix, &len_substr);
    if(len_str < len_substr)
    {
        puts("Suffix string longer than string");
        return FAILURE;
    }
    index = len_str - len_substr;
    status = substring_index(p_str, p_str_suffix, index);
    if(status == TRUE)
        return TRUE;
    else
        return FALSE;
}

status_t remove_preffix(schar_t** pp_str, schar_t* p_str_prefix)
{
    schar_t* p_str = *pp_str;
    status_t status;
    status = substring_index(p_str, p_str_prefix, 0);
    if(status == FALSE)
        return FAILURE;
    
    len_t len_str, len_prefix;
    string_length(p_str, &len_str);
    string_length(p_str_prefix, &len_prefix);
    get_substring_by_range(p_str, len_prefix, len_str-1, &p_str);
    printf("p_str = %s\n",p_str);
    *pp_str = p_str;
    return SUCCESS;
}

status_t remove_suffix(schar_t** pp_str, schar_t* p_str_suffix)
{
    schar_t* p_str = *pp_str;
    len_t len_str, len_suffix;
    status_t status;
    string_length(p_str, &len_str);
    string_length(p_str_suffix, &len_suffix);
    status = substring_index(p_str, p_str_suffix, len_str - len_suffix);
    if(status == FALSE)
        return FAILURE;
    p_str[len_str - len_suffix] = '\0';
    *pp_str = p_str;
    return SUCCESS;
}

status_t is_string_alpha(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    status_t flag = TRUE;
    uint_t i;    
    for(i = 0; i<len; ++i)
    {
        if(!(is_char_lower(p_str[i]) || is_char_upper(p_str[i])))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_digit(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    status_t flag = TRUE;
    uint_t i;    
    for(i = 0; i<len; ++i)
    {
        if(!is_char_digit(p_str[i]))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_alnum(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    status_t flag = TRUE;
    uint_t i;    
    for(i = 0; i<len; ++i)
    {
        if(!(is_char_lower(p_str[i]) || is_char_upper(p_str[i]) || is_char_digit(p_str[i])))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_decimal(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    status_t flag = TRUE;
    uint_t i;    
    if(p_str[0] == '0')
        return FALSE;

    for(i = 0; i<len; ++i)
    {
        if(!is_char_digit(p_str[i]))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_identifier(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    status_t flag = TRUE;
    uint_t i;    
    if(!(is_char_lower(p_str[0]) || is_char_upper(p_str[0]) || is_char_digit(p_str[0])))
        return FALSE;
        
    for(i = 0; i<len; ++i)
    {
        if(!((is_char_lower(p_str[i]) || is_char_upper(p_str[i]) || is_char_digit(p_str[i]) || p_str[i] == '_')))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_lower(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    uint_t i;
    status_t flag = TRUE;
    for(i = 0; i<len; ++i)
    {
        if(!is_char_lower(p_str[i]))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_upper(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    uint_t i;
    status_t flag = TRUE;
    for(i = 0; i<len; ++i)
    {
        if(!is_char_upper(p_str[i]))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_title(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    uint_t i;
    status_t flag = TRUE;
    status_t status = OUT;
    for(i = 0; i<len; ++i)
    {
        if(status == OUT && !is_char_space(p_str[i]))
        {
            status = IN;
            if(!is_char_upper(p_str[i]))
            {
                flag = FALSE;
                break;
            }
        }
        else if(status == IN && is_char_space(p_str[i]))
        {
            status = OUT;
        }
    }    
    return flag;
}

status_t is_string_printable(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    uint_t i;
    status_t flag = TRUE;
    for(i = 0; i<len; ++i)
    {
        if(!(p_str[i] >= 32 && p_str[i] <= 127))
        {
            flag = FALSE;
            break;
        }
    }
    return flag;
}

status_t is_string_space(schar_t* p_str)
{
    len_t len;
    string_length(p_str, &len);
    uint_t i;
    status_t flag = FALSE;
    for(i = 0; i<len; ++i)
    {
        if(is_char_space(p_str[i]))
        {
            flag = TRUE;
            break;
        }
    }
    return flag;
}
