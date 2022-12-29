#include "telephone_directory.h"

//entry point function
int main(void)
{
    list_t* p_list;
    len_t len = 0;
    status_t status = 0;
    contact_t new_contact;
    contact_t e_contact;
    char_t e_name[100];
    uint_t e_phone_no;
    int choice = 1;

    create_list(&p_list);

    puts("=======================================================");
    puts("TELEPHONE DIRECTORY USING DCLL");

    while(choice != 0)
    {
        puts("=======================================================");
        puts("1. Insert new record at start");
        puts("2. Insert new record at end");
        puts("3. Insert record before existing record");
        puts("4. Insert record after existing record");
        puts("5. Read first record");
        puts("6. Read last record");
        puts("7. Pop first record");
        puts("8. Pop last record");
        puts("9. Remove first record");
        puts("10. Remove last record");
        puts("11. Remove specific record");
        puts("12. Search record by name");
        puts("13. Search record by phone number");
        puts("14. Show telephone directory");
        puts("15. Count records");
        puts("0. Exit application");

        puts("=======================================================");
        printf("Please select an option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter name: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",new_contact.name);
                printf("Enter phone number: ");
                scanf("%llu",&new_contact.phone_no);
                status = insert_start(p_list, new_contact);
                if(status == SUCCESS)
                    puts("Record inserted successfully");
                break;

            case 2:
                printf("Enter name: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",new_contact.name);
                printf("Enter phone number: ");
                scanf("%llu",&new_contact.phone_no);
                status = insert_end(p_list, new_contact);
                if(status == SUCCESS)
                    puts("Record inserted successfully");
                break;

            case 3:
                puts("Enter existing record details: ");
                printf("Name: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",e_name);
                printf("Enter new name to insert: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",new_contact.name);
                printf("Enter phone number: ");
                scanf("%llu",&e_contact.phone_no);
                status = insert_before(p_list, new_contact, e_name);
                if(status == LIST_DATA_NOT_FOUND)
                    puts("Entered record does not exist in the directory");
                else if(status == SUCCESS)  
                    puts("Record inserted successfully");
                break;               

            case 4:
                puts("Enter existing record details: ");
                printf("Name: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",e_name);
                printf("Enter new name to insert: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",new_contact.name);
                printf("Enter phone number: ");
                scanf("%llu",&new_contact.phone_no);
                status = insert_after(p_list, new_contact, e_name);
                if(status == LIST_DATA_NOT_FOUND)
                    puts("Entered record does not exist in the directory");
                else if(status == SUCCESS)  
                    puts("Record inserted successfully");
                break; 

            case 5:
                status = get_start(p_list, &e_contact);
                if(status == SUCCESS)
                {
                    puts("Details of the first record: ");
                    printf("Name: %s\n",e_contact.name);
                    printf("Telephone number: %llu\n",e_contact.phone_no);
                }
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;

            case 6:
                status = get_end(p_list, &e_contact);
                if(status == SUCCESS)
                {
                    puts("Details of the last record: ");
                    printf("Name: %s\n",e_contact.name);
                    printf("Telephone number: %llu\n",e_contact.phone_no);
                }
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;

            case 7:
                status = pop_start(p_list, &e_contact);
                if(status == SUCCESS)
                {
                    puts("Details of the popped record: ");
                    printf("Name: %s\n",e_contact.name);
                    printf("Telephone number: %llu\n",e_contact.phone_no);
                }
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;

            case 8:
                status = pop_end(p_list, &e_contact);
                if(status == SUCCESS)
                {
                    puts("Details of the popped record: ");
                    printf("Name: %s\n",e_contact.name);
                    printf("Telephone number: %llu\n",e_contact.phone_no);
                }
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;

            case 9:
                status = remove_start(p_list);
                if(status == LIST_EMPTY)
                    puts("List is empty");
                else if(status == SUCCESS)
                    puts("First record deleted successfully");
                break;

            case 10:
                status = remove_end(p_list);
                if(status == LIST_EMPTY)
                    puts("List is empty");
                else if(status == SUCCESS)
                    puts("Last record deleted successfully");
                break;

            case 11:
                puts("Enter record details to remove: ");
                printf("Name: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",e_name);
                status = remove_data(p_list, e_name);
                if(status == LIST_DATA_NOT_FOUND)
                    puts("This record does not exist in the telephone directory");
                else if(status == SUCCESS)
                    puts("Specified record removed successfully");
                break;

            case 12:
                puts("Enter name to search: ");
                printf("Name: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",e_name);
                status = search_data_by_name(p_list, e_name, &e_contact);
                if(status == TRUE)
                {
                    puts("Details of the searched record: ");
                    printf("Name: %s\n",e_contact.name);
                    printf("Telephone number: %llu\n",e_contact.phone_no);
                }
                else if(status == FALSE)
                    puts("This record does not exist");
                break;

            case 13:
                puts("Enter phone number to search: ");
                printf("Phone number: ");
                scanf("%llu",&e_phone_no);
                status = search_data_by_phone_number(p_list, e_phone_no, &e_contact);
                if(status == TRUE)
                {
                    puts("Details of the searched record: ");
                    printf("Name: %s\n",e_contact.name);
                    printf("Telephone number: %llu\n",e_contact.phone_no);
                }
                else if(status == FALSE)
                    puts("This record does not exist");
                break;

            case 14:
                show_list(p_list, "CURRENT LIST OF RECORDS IN TELEPHONE DIRECTORY");
                break;

            case 15:
                find_length(p_list, &len);
                printf("Numberof records = %d\n",len);
                break;

            case 0:
                puts("Thank you for using our application!!!");
                break;

            default:
                puts("Incorrect option, please try again");
        }
    }

    destroy_list(&p_list);

    exit(EXIT_SUCCESS);
}
