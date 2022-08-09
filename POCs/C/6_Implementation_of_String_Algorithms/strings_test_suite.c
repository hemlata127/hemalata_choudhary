#include "strings_test_suite.h"

//test functions for testing string alogorithms - definitions
void test_allocate_string()
{
    puts("Function name: allocate_string()");
    puts("Description: allocate memory for a string of specified size");
    len_t size;
    status_t status;
    schar_t* p_str = NULL;
    printf("Enter size: ");
    scanf("%llu",&size);
    status = allocate_string(size, &p_str);
    if(status == SUCCESS)
        puts("String allocated successfully");
    free(p_str);
    p_str = NULL;
    puts("Allocated string freed successfully");
}

void test_string_length()
{
    puts("Function name: string_length()");
    puts("Description: find length of string");
    schar_t p_str[100];
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    len_t len;
    status_t status;
    status = string_length(p_str, &len);
    printf("Length = %llu\n",len);
}

void test_string_ncompare_cs()
{
    puts("Function name: string_ncompare_cs()");
    puts("Description: compare n characters of two strings in case sensitive manner");
    schar_t p_str_1[100], p_str_2[100];
    uint_t n = 30;
    status_t status;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter string2: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_2);
    printf("Enter n: ");
    scanf("%llu",&n);
    
    status = string_ncompare_cs(p_str_1, p_str_2, n);
    if(status == TRUE)
        puts("EQUAL");
    else if(status == FALSE)
        puts("NOT EQUAL");
}

void test_string_ncompare_ncs()
{
    puts("Function name: string_ncompare_ncs()");
    puts("Description: compare n characters of two strings in case insensitive manner");
    schar_t p_str_1[100], p_str_2[100];
    uint_t n = 30;
    status_t status;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter string2: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_2);
    printf("Enter n: ");
    while(getchar() != '\n');
    scanf("%llu",&n);
    
    status = string_ncompare_ncs(p_str_1, p_str_2, n);
    if(status == TRUE)
        puts("EQUAL");
    else if(status == FALSE)
        puts("NOT EQUAL");
}

void test_string_compare_cs()
{
    puts("Function name: string_compare_cs()");
    puts("Description: compare two strings in case sensitive manner");
    schar_t p_str_1[100], p_str_2[100];
    status_t status;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter string2: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_2);
    
    status = string_compare_cs(p_str_1, p_str_2);
    if(status == TRUE)
        puts("EQUAL");
    else if(status == FALSE)
        puts("NOT EQUAL");
}

void test_string_compare_ncs()
{
    puts("Function name: string_compare_cs()");
    puts("Description: compare two strings in case sensitive manner");
    schar_t p_str_1[100], p_str_2[100];
    status_t status;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter string2: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_2);
    
    status = string_compare_ncs(p_str_1, p_str_2);
    if(status == TRUE)
        puts("EQUAL");
    else if(status == FALSE)
        puts("NOT EQUAL");
}

void test_get_concatenated_string()
{
    puts("Function name: get_concatenated_string()");
    puts("Description: concatenate two strings into a new third string");
    schar_t p_str_1[100], p_str_2[100];
    schar_t* p_str_concat = NULL;
    status_t status;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter string2: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_2);
    
    status = get_concatenated_string(p_str_1, p_str_2, &p_str_concat);
    if(status == SUCCESS)
        printf("Concatenated string = %s\n",p_str_concat);
    free(p_str_concat);
    p_str_concat = NULL;
}

void test_string_append()
{
    puts("Function name: string_append()");
    puts("Description: Append the second string at the end of the first string");
    schar_t p_str_1[200], p_str_2[100];
    uint_t new_size;
    status_t status;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter string2: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_2);
    
    status = string_append(p_str_1, p_str_2, &new_size);
    if(status == SUCCESS)
        printf("String1 after appending string2 = %s\n",p_str_1);
}

void test_string_multiply()
{
    puts("Function name: string_multiply()");
    puts("Description: Multiply the string specified number of times");
    schar_t p_str_1[100];
    schar_t* p_str_result;
    status_t status;
    uint_t n;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter value of n: ");
    scanf("%llu",&n);
    
    status = string_multiply(p_str_1, &p_str_result, n);
    if(status == SUCCESS)
        printf("Result string = %s\n",p_str_result);
}

void test_get_char_by_index()
{
    puts("Function name: get_char_by_index()");
    puts("Description: Get the character at the specified index");
    schar_t p_str_1[100];
    schar_t ch;
    status_t status;
    uint_t index;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter index value: ");
    scanf("%llu",&index);
    
    status = get_char_by_index(p_str_1, index, &ch);
    if(status == SUCCESS)
        printf("Character at index %llu = %c\n",index, ch);
}

void test_get_substring_by_range()
{
    puts("Function name: get_substring_by_range()");
    puts("Description: Get substring from specified string from the given index range");
    schar_t p_str_1[100];
    schar_t* p_substr = NULL;
    status_t status;
    uint_t start_index, end_index;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter start index value: ");
    scanf("%llu",&start_index);
    printf("Enter end index value: ");
    scanf("%llu",&end_index);
    
    status = get_substring_by_range(p_str_1, start_index, end_index, &p_substr);
    if(status == SUCCESS)
        printf("Substring at given range = %s\n",p_substr);
}

void test_get_substring_by_slice()
{
    puts("Function name: get_substring_by_slice()");
    puts("Description: Get substring from specified string from the given index range stepping by the specified step value");
    schar_t p_str_1[100];
    schar_t* p_substr = NULL;
    status_t status;
    uint_t start_index, end_index, step;
    printf("Enter string1: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_1);
    printf("Enter start index value: ");
    scanf("%llu",&start_index);
    printf("Enter end index value: ");
    scanf("%llu",&end_index);
    printf("Enter step value: ");
    scanf("%llu",&step);
    
    status = get_substring_by_slice(p_str_1, start_index, end_index, step, &p_substr);
    if(status == SUCCESS)
        printf("Substring at given range stepping by %llu = %s\n",step, p_substr);
}

void test_is_substring()
{
    puts("Function name: is_substring()");
    puts("Description: Checks if the string contains the specified substring");
    schar_t p_str[100];
    schar_t p_substr[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter substring: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_substr);
    
    status = is_substring(p_str, p_substr);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_substring_index()
{
    puts("Function name: substring_index()");
    puts("Description: Checks if the string contains the specified substring at given index");
    schar_t p_str[100];
    schar_t p_substr[100];
    uint_t index;
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter substring: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_substr);
    printf("Enter index: ");
    scanf("%llu",&index);
    
    status = substring_index(p_str, p_substr, index);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_substring_count()
{
    puts("Function name: substring_count()");
    puts("Description: Counts number of occurences of substring in specified string");
    schar_t p_str[100];
    schar_t p_substr[100];
    status_t status;
    uint_t count;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter substring: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_substr);
    
    status = substring_count(p_str, p_substr, &count);
    if(status == SUCCESS)
        printf("Count of substring = %llu\n",count);
}

void test_make_string_reverse()
{
    puts("Function name: make_string_reverse()");
    puts("Description: Makes the string reverse");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_reverse(p_str);
    if(status == SUCCESS)
        printf("Reverse string = %s\n",p_str);
}

void test_get_reverse_string()
{
    puts("Function name: get_reverse_string()");
    puts("Description: Get reverse string");
    schar_t p_str[100];
    schar_t* p_str_reverse = NULL;
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = get_reverse_string(p_str, &p_str_reverse);
    if(status == SUCCESS)
        printf("Reverse string = %s\n",p_str_reverse);
    
    free(p_str_reverse);
    p_str_reverse = NULL;
}

void test_make_string_range_reverse()
{
    puts("Function name: make_string_range_reverse()");
    puts("Description: Reverse specified range of string");
    schar_t p_str[100];
    status_t status;
    uint_t start_index, end_index;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter start index: ");
    scanf("%llu",&start_index);
    printf("Enter end index: ");
    scanf("%llu",&end_index);
    
    status = make_string_range_reverse(p_str, start_index, end_index);
    if(status == SUCCESS)
        printf("String after reversing given range = %s\n",p_str);
}

void test_string_ncopy()
{
    puts("Function name: string_ncopy()");
    puts("Description: Copy n characters of string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    uint_t n;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    printf("Enter number of characters to copy: ");
    scanf("%llu",&n);
    
    status = string_ncopy(p_str_src, &p_str_dest, n);
    if(status == SUCCESS)
        printf("Copied string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_clone_string()
{
    puts("Function name: clone_string()");
    puts("Description: Clone the given string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = clone_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Copied string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_get_upper_string()
{
    puts("Function name: get_upper_string()");
    puts("Description: Get upper case string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = get_upper_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Upper case string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_make_string_upper()
{
    puts("Function name: make_string_upper()");
    puts("Description: Make the given string upper case");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_upper(p_str);
    if(status == SUCCESS)
        printf("Upper case string = %s\n",p_str);
}

void test_get_lower_string()
{
    puts("Function name: get_lower_string()");
    puts("Description: Get lower case string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    uint_t n;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = get_lower_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Lower case string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_make_string_lower()
{
    puts("Function name: make_string_lower()");
    puts("Description: Make the given string lower case");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_lower(p_str);
    if(status == SUCCESS)
        printf("Lower case string = %s\n",p_str);
}

void test_get_title_case_string()
{
    puts("Function name: get_title_case_string()");
    puts("Description: Get title case string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    uint_t n;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = get_title_case_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Title case string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_make_string_title_case()
{
    puts("Function name: make_string_title_case()");
    puts("Description: Make the given string title case");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_title_case(p_str);
    if(status == SUCCESS)
        printf("Title case string = %s\n",p_str);
}

void test_get_lstriped_string()
{
    puts("Function name: get_lstriped_string()");
    puts("Description: Remove extra left spaces from the string and get new string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    uint_t n;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = get_lstriped_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Left striped string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_make_string_lstriped()
{
    puts("Function name: make_string_lstriped()");
    puts("Description: Remove extra left spaces from the string");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_lstriped(p_str);
    if(status == SUCCESS)
        printf("String after removing extra left spaces = %s\n",p_str);
}

void test_get_rstriped_string()
{
    puts("Function name: get_rstriped_string()");
    puts("Description: Remove extra right spaces from the string and get new string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    uint_t n;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = get_rstriped_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Right striped string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_make_string_rstriped()
{
    puts("Function name: make_string_rstriped()");
    puts("Description: Remove extra right spaces from the string");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_rstriped(p_str);
    if(status == SUCCESS)
        printf("String after removing extra right spaces = %s\n",p_str);
}

void test_get_striped_string()
{
    puts("Function name: get_striped_string()");
    puts("Description: Remove extra left and right spaces from the string and get new string");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    uint_t n;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = get_striped_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Striped string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_make_string_striped()
{
    puts("Function name: make_string_striped()");
    puts("Description: Remove extra left and right spaces from the string");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_striped(p_str);
    if(status == SUCCESS)
        printf("String after removing extra left and right spaces = %s\n",p_str);
}

void test_get_case_swapped_string()
{
    puts("Function name: get_case_swapped_string()");
    puts("Description: Get new string with case swapped");
    schar_t p_str_src[100];
    schar_t* p_str_dest = NULL;
    status_t status;
    uint_t n;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str_src);
    
    status = get_case_swapped_string(p_str_src, &p_str_dest);
    if(status == SUCCESS)
        printf("Case swapped string = %s\n",p_str_dest);

    free(p_str_dest);
    p_str_dest = NULL;
}

void test_make_string_case_swapped()
{
    puts("Function name: make_string_case_swapped()");
    puts("Description: Swap the case of the string");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = make_string_case_swapped(p_str);
    if(status == SUCCESS)
        printf("String after case swap = %s\n",p_str);
}

void test_split_string()
{
    puts("Test function split()");

    schar_t p_str[100];
    schar_t p_sep[50];
    uint_t p_size = 0;
    schar_t** pp_str = NULL;

    while(getchar() != '\n');
    printf("Enter string to be split: ");
    scanf("%[^'\n']s",p_str);
    while(getchar() != '\n');
    printf("Enter seperator: ");
    scanf("%[^'\n']s",p_sep);

    split_string(p_str, p_sep, &pp_str, &p_size);
    
    uint_t i;
    for(i = 0; i<p_size; ++i)
        printf("Component%llu: %s\n",i, pp_str[i]);

    for(i = 0; i<p_size; ++i)
        free(pp_str[i]);

    free(pp_str);
    pp_str = NULL;
}

void test_count_words()
{
    puts("Function name: count_words()");
    puts("Description: Count the number of words in the string");
    schar_t p_str[100];
    status_t status;
    uint_t count;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = count_words(p_str, &count);
    if(status == SUCCESS)
        printf("Number of words = %llu\n",count);
}

void test_reverse_each_word()
{
    puts("Function name: reverse_each_word()");
    puts("Description: Reverse each word in string");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = reverse_each_word(p_str);
    if(status == SUCCESS)
        printf("Result string = %s\n",p_str);
}

void test_starts_with()
{
    puts("Function name: starts_with()");
    puts("Description: Checks if the string starts with the given prefix");
    schar_t p_str[100];
    schar_t p_prefix[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter substring: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_prefix);
    
    status = starts_with(p_str, p_prefix);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_ends_with()
{
    puts("Function name: ends_with()");
    puts("Description: Checks if the string ends with the given suffix");
    schar_t p_str[100];
    schar_t p_suffix[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter substring: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_suffix);
    
    status = ends_with(p_str, p_suffix);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_remove_preffix()
{
    puts("Function name: remove_prefix()");
    puts("Description: Remove prefix from the string");
    schar_t p_str[100];
    schar_t p_prefix[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter substring: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_prefix);
    schar_t* p_str1 = p_str;
    
    status = remove_preffix(&p_str1, p_prefix);
    if(status == FAILURE)
        printf("%s not prefix of %s\n",p_prefix, p_str);
    else if(status == SUCCESS)
        printf("String after removing prefix = %s\n",p_str1);
}

void test_remove_suffix()
{
    puts("Function name: remove_suffix()");
    puts("Description: Remove suffix from the string");
    schar_t p_str[100];
    schar_t p_suffix[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    printf("Enter substring: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_suffix);
    schar_t* p_str1 = p_str;
    
    status = remove_suffix(&p_str1, p_suffix);
    if(status == FAILURE)
        printf("%s not suffix of %s\n",p_suffix, p_str);
    else if(status == SUCCESS)
        printf("String after removing suffix = %s\n",p_str1);
}
void test_is_string_alpha()
{
    puts("Function name: is_string_alpha()");
    puts("Description: Checks if string contains all alphabetic characters");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_alpha(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_is_string_digit()
{
    puts("Function name: is_string_digit()");
    puts("Description: Checks if string contains all digits");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_digit(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_is_string_alnum()
{
    puts("Function name: is_string_alnum()");
    puts("Description: Checks if string contains all alpha-numeric charaters");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_alnum(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_is_string_decimal()
{
    puts("Function name: is_string_decimal()");
    puts("Description: Checks if string is decimal");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_decimal(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");
}

void test_is_string_identifier()
{
    puts("Function name: is_string_identifier()");
    puts("Description: Checks if string is valid identifier");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_identifier(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");    
}

void test_is_string_lower()
{
    puts("Function name: is_string_lower()");
    puts("Description: Checks if string has all lower case alphabets");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_lower(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");  
}

void test_is_string_upper()
{
    puts("Function name: is_string_upper()");
    puts("Description: Checks if string has all upper case alphabets");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_upper(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE");  
}

void test_is_string_title()
{
    puts("Function name: is_string_title()");
    puts("Description: Checks if string is in title case");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_title(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE"); 
}

void test_is_string_printable()
{
    puts("Function name: is_string_printable()");
    puts("Description: Checks if string has all printable characters");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_printable(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE"); 
}

void test_is_string_space()
{
    puts("Function name: is_string_space()");
    puts("Description: Checks if string has space characters");
    schar_t p_str[100];
    status_t status;
    printf("Enter string: ");
    while(getchar() != '\n');
    scanf("%[^'\n']s",p_str);
    
    status = is_string_space(p_str);
    if(status == TRUE)
        puts("TRUE");
    else if(status == FALSE)
        puts("FALSE"); 
}
