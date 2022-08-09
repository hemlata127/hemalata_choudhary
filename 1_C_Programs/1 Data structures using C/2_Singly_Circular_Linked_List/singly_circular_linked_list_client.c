#include "singly_circular_linked_list.h"

int main(void)
{
    list_t* p_list = NULL;
    list_t* p_list_1 = NULL;
    list_t* p_list_2 = NULL;
    list_t* p_list_result = NULL;
    len_t len = 0;
    len_t len1 = 0;
    len_t len2 = 0;
    data_t new_data = 0;
    data_t e_data = 0;
    bool_t choice = 1;
    status_t status;
    int* arr1 = NULL;
    int* arr2 = NULL;
    int i = 0;
    create_list(&p_list);
  
    puts("===============================================");
    puts("SINGLY CIRCULAR LINKED LIST");

    while(choice != 0)
    {
        puts("===============================================");
        puts("1. Insert start");
        puts("2. Insert end");
        puts("3. Insert before node");
        puts("4. Insert after node");
        puts("5. Delete start");
        puts("6. Delete end");
        puts("7. Delete data");
        puts("8. Get start node data");
        puts("9. Get end node data");
        puts("10. Pop start");
        puts("11. Pop end");
        puts("12. Get list length");
        puts("13. Show list");
        puts("14. Search data in list");
        puts("15. Concat lists - immutable");
        puts("16. Concat lists - mutable");
        puts("17. Get reversed list");
        puts("18. Reverse list");
        puts("19. Merge lists");
        puts("0. Exit application");
        printf("Please select an option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter new node data: ");
                scanf("%d",&new_data);
                status = insert_start(p_list, new_data);
                if(status == SUCCESS)
                    puts("Data inserted successfully");
                break;
            case 2:
                printf("Enter new node data: ");
                scanf("%d",&new_data);
                status = insert_end(p_list, new_data);
                if(status == SUCCESS)
                    puts("Data inserted successfully");
                break;
            case 3:
                printf("Enter new node data: ");
                scanf("%d",&new_data);
                printf("Enter existing node data: ");
                scanf("%d",&e_data);
                status = insert_before(p_list, new_data, e_data);
                if(status == SUCCESS)
                    puts("Data inserted successfully");
                else if(status == LIST_DATA_NOT_FOUND)
                    printf("%d not found in list\n",e_data);
                break;
            case 4:
                printf("Enter new node data: ");
                scanf("%d",&new_data);
                printf("Enter existing node data: ");
                scanf("%d",&e_data);
                status = insert_after(p_list, new_data, e_data);
                if(status == SUCCESS)
                    puts("Data inserted successfully");
                else if(status == LIST_DATA_NOT_FOUND)
                    printf("%d not found in list\n",e_data);
                break;
            case 5:
                status = remove_start(p_list);
                if (status == SUCCESS)
                    puts("Data deleted successfully");
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;
            case 6:
                status = remove_end(p_list);
                if(status == SUCCESS)
                    puts("Data deleted successfully");
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;
            case 7:
                printf("Enter node data to delete: ");
                scanf("%d",&e_data);
                status = remove_data(p_list, e_data);
                if(status == LIST_EMPTY)
                    puts("List is empty");
                else if(status == LIST_DATA_NOT_FOUND)
                    printf("%d not found in list\n",e_data);
                else if(status == SUCCESS)
                    puts("Data deleted successfully");
                break;
            case 8:
                status = get_start(p_list, &e_data);
                if(status == LIST_EMPTY)
                    puts("List is empty");
                else if(status == SUCCESS)
                    printf("Data in start node = %d\n",e_data);
                break;
            case 9:
                status = get_end(p_list, &e_data);
                if(status == LIST_EMPTY)
                    puts("List is empty");
                else if(status == SUCCESS)
                    printf("Data in last node = %d\n", e_data);
                break;
            case 10:
                status = pop_start(p_list, &e_data);
                if(status == SUCCESS)
                    printf("Popped data from first node = %d\n",e_data);
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;
            case 11:
                status = pop_end(p_list, &e_data);
                if(status == SUCCESS)
                    printf("Popped data from last node = %d\n",e_data);
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;
            case 12:
                find_length(p_list, &len);
                printf("Number of nodes in list = %d\n",len);
                break;
            case 13:
                show_list(p_list,"Current list");
                break;
            case 14:
                printf("Enter data to search in the list: ");
                scanf("%d",&e_data);
                status = search_data(p_list, e_data);
                if(status == TRUE)
                    printf("%d is present in list\n",e_data);
                else if(status == FALSE)
                    printf("%d is not present in list\n",e_data);
                break;
            case 15:
                create_list(&p_list_1);
                printf("Enter list1 length: ");
                scanf("%d",&len1);
                for(i = 0; i<len1; ++i)
                {
                    printf("Enter list1 node data%d: ",i+1);
                    scanf("%d",&e_data);
                    insert_end(p_list_1, e_data);
                }
                create_list(&p_list_2);
                printf("Enter list2 length: ");
                scanf("%d",&len2);
                for(i = 0; i<len2; ++i)
                {
                    printf("Enter list2 node data%d: ",i+1);
                    scanf("%d",&e_data);
                    insert_end(p_list_2, e_data);
                }
                create_list(&p_list_result);
                concat_lists_imm(p_list_1, p_list_2, &p_list_result);
                show_list(p_list_1, "LIST1");
                show_list(p_list_2, "LIST2");
                show_list(p_list_result, "CONCATENATED LIST");
                destroy_list(&p_list_1);
                destroy_list(&p_list_2);
                destroy_list(&p_list_result);
                break;
            case 16:
                create_list(&p_list_1);
                printf("Enter list1 length: ");
                scanf("%d",&len1);
                for(i = 0; i<len1; ++i)
                {
                    printf("Enter list1 node data%d: ",i+1);
                    scanf("%d",&e_data);
                    insert_end(p_list_1, e_data);
                }
                create_list(&p_list_2);
                printf("Enter list2 length: ");
                scanf("%d",&len2);
                for(i = 0; i<len2; ++i)
                {
                    printf("Enter list2 node data%d: ",i+1);
                    scanf("%d",&e_data);
                    insert_end(p_list_2, e_data);
                }
                show_list(p_list_1, "LIST1");
                show_list(p_list_2, "LIST2");
                concat_lists_m(p_list_1, &p_list_2);
                show_list(p_list_1, "CONCATENATED LIST");
                destroy_list(&p_list_1);
                break;
            case 17:
                p_list_result = NULL;
                create_list(&p_list_result);
                get_reversed_list(p_list, &p_list_result);
                show_list(p_list, "ORIGINAL LIST");
                show_list(p_list_result, "NEW REVERSED LIST");
                destroy_list(&p_list_result);
                break;
            case 18:
                show_list(p_list, "ORIGINAL LIST");
                reverse_list(p_list);
                show_list(p_list, "REVERSED LIST");
                break;
            case 19:
                create_list(&p_list_1);
                printf("Enter list1 length: ");
                scanf("%d",&len1);
                for(i = 0; i<len1; ++i)
                {
                    printf("Enter list1 node data%d: ",i+1);
                    scanf("%d",&e_data);
                    insert_end(p_list_1, e_data);
                }
                create_list(&p_list_2);
                printf("Enter list2 length: ");
                scanf("%d",&len2);
                for(i = 0; i<len2; ++i)
                {
                    printf("Enter list2 node data%d: ",i+1);
                    scanf("%d",&e_data);
                    insert_end(p_list_2, e_data);
                }
                to_array(p_list_1, &arr1, &len1);
                destroy_list(&p_list_1);
                sort_array(arr1, len1);
                create_list(&p_list_1);
                to_list(arr1, len1, &p_list_1);
                destroy_array(&arr2);

                to_array(p_list_2, &arr2, &len2);
                destroy_list(&p_list_2);
                sort_array(arr2, len2);
                create_list(&p_list_2);
                to_list(arr2, len2, &p_list_2);
                destroy_array(&arr2);

                create_list(&p_list_result);
                merge_lists(p_list_1, p_list_2, &p_list_result);
                show_list(p_list_1, "LIST1");
                show_list(p_list_2, "LIST2");
                show_list(p_list_result, "MERGED LIST");
                destroy_list(&p_list_1);
                destroy_list(&p_list_2);
                destroy_list(&p_list_result);
                break;
            case 0:
                puts("Thank you for using the application!!!");
                break;
            default:
                puts("Incorrect choice, please try again");
        }
    }

    destroy_list(&p_list);

    exit(EXIT_SUCCESS);
}
