#ifndef _STRINGS_H
#define _STRINGS_H

//header files
#include<stdio.h>
#include<stdlib.h>

//symbolic constants
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 2
#define IN 3
#define OUT 4

//typedefs
typedef signed char schar_t;
typedef unsigned long long int uint_t;
typedef uint_t len_t;
typedef int status_t;
typedef int bool_t;

//auxillary function declarations
static void* xcalloc(size_t nr_of_elements, size_t size_per_element);
static void* xrealloc(void* old_address, size_t new_size);
static bool_t is_char_lower(schar_t ch);
static bool_t is_char_upper(schar_t ch);
static bool_t is_char_digit(schar_t ch);
static bool_t is_char_space(schar_t ch);
static schar_t to_lower_char(schar_t ch);
static schar_t to_upper_char(schar_t ch);

//interface functions
status_t allocate_string(len_t size, schar_t** pp_str);
status_t string_length(const schar_t* p_str, len_t* p_len);
status_t string_ncompare_cs(const schar_t* p_str_1, const schar_t* p_str_2, uint_t n);
status_t string_ncompare_ncs(const schar_t* p_str_1, const schar_t* p_str_2, uint_t n);
status_t string_compare_cs(const schar_t* p_str_1, const schar_t* p_str_2);
status_t string_compare_ncs(const schar_t* p_str_1, const schar_t* p_str_2);
status_t get_concatenated_string(const schar_t* p_str_1, const schar_t* p_str_2, schar_t** pp_str_concat);
status_t string_append(schar_t* p_str_1, const schar_t* p_str_2, uint_t* p_new_size);
status_t string_multiply(const schar_t* p_str, schar_t** pp_str_result, uint_t n);
status_t get_char_by_index(const schar_t* p_str, uint_t index, schar_t* p_ch);
status_t get_substring_by_range(const schar_t* p_str, uint_t start_index, uint_t end_index, schar_t** pp_substr);
status_t get_substring_by_slice(const schar_t* p_str, uint_t start_index, uint_t end_index, uint_t step, schar_t** pp_substr);
status_t is_substring(const schar_t* p_str, const schar_t* p_substr);
status_t substring_index(const schar_t* p_str, const schar_t* p_substr, uint_t index);
status_t substring_count(const schar_t* p_str, const schar_t* p_substr, uint_t* p_count);
status_t make_string_reverse(schar_t* p_str);
status_t get_reverse_string(const schar_t* p_str, schar_t** pp_str_reverse);
status_t make_string_range_reverse(schar_t* p_str, uint_t start_index, uint_t end_index);
status_t string_ncopy(schar_t* p_str_src, schar_t** pp_str_dest, uint_t n);
status_t clone_string(const schar_t* p_str_src, schar_t** pp_str_clone);
status_t get_upper_string(schar_t* p_str, schar_t** pp_str_result);
status_t make_string_upper(schar_t* p_str);
status_t get_lower_string(schar_t* p_str, schar_t** pp_str_result);
status_t make_string_lower(schar_t* p_str);
status_t get_title_case_string(schar_t* p_str, schar_t** pp_str_result);
status_t make_string_title_case(schar_t* p_str);
status_t get_lstriped_string(schar_t* p_str, schar_t** pp_str_result);
status_t make_string_lstriped(schar_t* p_str);
status_t get_rstriped_string(schar_t* p_str, schar_t** pp_str_result);
status_t make_string_rstriped(schar_t* p_str);
status_t get_striped_string(schar_t* p_str, schar_t** pp_str_result);
status_t make_string_striped(schar_t* p_str);
status_t get_case_swapped_string(schar_t* p_str, schar_t** pp_str_result);
status_t make_string_case_swapped(schar_t* p_str);
status_t split_string(const schar_t* p_str, const schar_t* p_sep, schar_t*** ppp_str, uint_t* p_size);
status_t count_words(const schar_t* p_str, uint_t* p_count);
status_t reverse_each_word(schar_t* p_str);
status_t starts_with(schar_t* p_str, schar_t* p_str_prefix);
status_t ends_with(schar_t* p_str, schar_t* p_str_suffix);
status_t remove_preffix(schar_t** pp_str, schar_t* p_str_prefix);
status_t remove_suffix(schar_t** pp_str, schar_t* p_str_suffix);
status_t is_string_alpha(schar_t* p_str);
status_t is_string_digit(schar_t* p_str);
status_t is_string_alnum(schar_t* p_str);
status_t is_string_decimal(schar_t* p_str);
status_t is_string_identifier(schar_t* p_str);
status_t is_string_lower(schar_t* p_str);
status_t is_string_upper(schar_t* p_str);
status_t is_string_title(schar_t* p_str);
status_t is_string_printable(schar_t* p_str);
status_t is_string_space(schar_t* p_str);

#endif
