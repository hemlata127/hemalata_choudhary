#include "string.h"

int main(void)
{
    int choice = 1;

    puts("==================================================");
    puts("IMPLEMENTATION OF DIFFERENT STRING ALGORITHMS");
    

    do
    {
        puts("==================================================");
        puts("1. Test allocate_string()");
        puts("2. Test string_length()");
        puts("3. Test string_ncompare_cs()");
        puts("4. Test string_ncompare_ncs()");
        puts("5. Test string_compare_cs()");
        puts("6. Test compare_ncs()");
        puts("7. Test concatenated_string()");
        puts("8. Test string_append()");
        puts("9. Test string_multiply()");
        puts("10. Test get_char_by_index()");
        puts("11. Test get_substring_by_range()");
        puts("12. Test substring_by_slice()");
        puts("13. Test is_substring()");
        puts("14. Test substring_index()");
        puts("15. Test substring_count()");
        puts("16. Test make_string_reverse()");
        puts("17. Test get_reverse_string()");
        puts("18. Test make_string_range_reverse()");
        puts("19. Test string_ncopy()");
        puts("20. Test clone_string()");
        puts("21. Test get_upper_string()");
        puts("22. Test make_string_upper()");
        puts("23. Test get_lower_string()");
        puts("24. Test make_string_lower()");
        puts("25. Test get_title_case_string()");
        puts("26. Test make_string_title_case()");
        puts("27. Test get_lstriped_string()");
        puts("28. Test make_string_lstriped()");
        puts("29. Test get_rstriped_string()");
        puts("30. Test make_string_rstriped()");
        puts("31. Test get_striped_string()");
        puts("32. Test make_string_striped()");
        puts("33. Test get_case_swapped_string()");
        puts("34. Test make_string_case_swapped()");
        puts("35. Test split_string()");
        puts("36. Test count_words()");
        puts("37. Test reverse_each_word()");
        puts("38. Test start_with()");
        puts("39. Test ends_with()");
        puts("40. Test remove_preffix()");
        puts("41. Test remove_suffix()");
        puts("42. Test is_string_alpha()");
        puts("43. Test is_string_digit()");
        puts("44. Test is_string_alnum()");
        puts("45. Test is_string_decimal()");
        puts("46. Test is_string_identifier()");
        puts("47. Test is_string_lower()");
        puts("48. Test is_string_upper()");
        puts("49. Test is_string_title()");
        puts("50. Test is_string_printable()");
        puts("51. Test is_space()");
        puts("0. Exit the application");

        printf("Enter choice: ");
        scanf("%d",&choice);
        puts("==================================================");

        switch(choice)
        {
            case 1:
                test_allocate_string();
                break;
            
            case 2:
                test_string_length();
                break;

            case 3:
                test_string_ncompare_cs();
                break;

            case 4:
                test_string_ncompare_ncs();
                break;

            case 5:
                test_string_compare_cs();
                break;

            case 6:
                test_string_compare_ncs();
                break;

            case 7:
                test_get_concatenated_string();
                break;

            case 8:
                test_string_append();
                break;

            case 9:
                test_string_multiply();
                break;

            case 10:
                test_get_char_by_index();
                break;

            case 11:
                test_get_substring_by_range();
                break;

            case 12:
                test_get_substring_by_slice();
                break;

            case 13:
                test_is_substring();
                break;

            case 14:
                test_substring_index();
                break;

            case 15:
                test_substring_count();
                break;

            case 16:
                test_make_string_reverse();
                break;
            
            case 17:
                test_get_reverse_string();
                break;

            case 18:
                test_make_string_range_reverse();
                break;

            case 19:
                test_string_ncopy();
                break;

            case 20:
                test_clone_string();
                break;

            case 21:
                test_get_upper_string();
                break;

            case 22:
                test_make_string_upper();
                break;

            case 23:
                test_get_lower_string();
                break;
            
            case 24:
                test_make_string_lower();
                break;

            case 25:
                test_get_title_case_string();
                break;

            case 26:
                test_make_string_title_case();
                break;

            case 27:
                test_get_lstriped_string();
                break;

            case 28:
                test_make_string_lstriped();
                break;

            case 29:
                test_get_rstriped_string();
                break;

            case 30:
                test_make_string_rstriped();
                break;

            case 31:
                test_get_striped_string();
                break;
            
            case 32:
                test_make_string_striped();
                break;

            case 33:
                test_get_case_swapped_string();
                break;

            case 34:
                test_make_string_case_swapped();
                break;

            case 35:
                test_split_string();
                break;

            case 36:
                test_count_words();
                break;

            case 37:
                test_reverse_each_word();
                break;

            case 38:
                test_starts_with();
                break;

            case 39:
                test_ends_with();
                break;

            case 40:
                test_remove_preffix();
                break;

            case 41:
                test_remove_suffix();
                break;
            
            case 42:
                test_is_string_alpha();
                break;

            case 43:
                test_is_string_digit();
                break;

            case 44:
                test_is_string_alnum();
                break;
            
            case 45:
                test_is_string_decimal();
                break;

            case 46:
                test_is_string_identifier();
                break;

            case 47:
                test_is_string_lower();
                break;

            case 48:
                test_is_string_upper();
                break;

            case 49:
                test_is_string_title();
                break;

            case 50:
                test_is_string_printable();
                break;

            case 51:
                test_is_string_space();
                break;

            case 0: 
                break;

            default:
                puts("Incorrect option, try again");
        }

        if(choice == 0)
            break;

        puts("==================================================");
        printf("Continue? [1], Exit? [0]: ");
        scanf("%d",&choice);
    }
    while(choice != 0);

    puts("Thank you for using the application!!!");
    puts("==================================================");

    exit("EXIT_SUCCESS");
}