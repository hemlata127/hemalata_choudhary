#include "Student_Details.h"

//global variable for most recent roll no
uint_t roll_no_to_be_used_next = 0;

int main(void)
{
    s_details_t p_new_s_details;
    s_details_t* p_e_s_details;
    list_t* p_list;
    len_t len;
    status_t status;
    uint_t s_roll_no;
    int choice = 1;

    create_list(&p_list);

    puts("==================================================================================");
    puts("STUDENT DATABASE USING DOUBLY CIRCULAR LINKED LIST");

    while(choice != 0)
    {
        puts("==================================================================================");
        puts("1. Insert new student record");
        puts("2. Remove last student record");
        puts("3. Remove first student record");
        puts("4. Remove student record");
        puts("5. Read first student record");
        puts("6. Read last student record");
        puts("7. Search if student record exists");
        puts("8. Show all student records");
        puts("9. Count records");
        puts("0. Exit the application");
        puts("==================================================================================");

        printf("Please select an option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                roll_no_to_be_used_next = roll_no_to_be_used_next + 1;
                p_new_s_details.roll_no = roll_no_to_be_used_next;
                puts("Please enter the student details to add");
                printf("Student name: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",p_new_s_details.s_name);
                printf("Year[FE, SE, TE or BE]: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",p_new_s_details.year);
                printf("Department: ");
                while(getchar() != '\n');
                scanf("%[^'\n']s",p_new_s_details.department);
                printf("Percentage in recent exams: ");
                scanf("%f",&p_new_s_details.percentage);
                status = insert_end(p_list, p_new_s_details);
                if(status == SUCCESS)
                    puts("Record inserted successfully");
                break;

            case 2:
                status = remove_end(p_list);
                if(status == SUCCESS)
                    puts("Last record removed successfully");
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;

            case 3:
                status = remove_start(p_list);
                if(status == SUCCESS)
                    puts("First record removed successfully");
                else if(status == LIST_EMPTY)
                    puts("List is empty");
                break;

            case 4:
                printf("Enter roll no of student record to remove: ");
                scanf("%llu",&s_roll_no);
                status = remove_data(p_list, s_roll_no);
                if(status == LIST_DATA_NOT_FOUND)
                    puts("This record does not exist");
                if(status == SUCCESS);
                    puts("Matching student record removed successfully");
                break;

            case 5:
                status = get_start(p_list, &p_e_s_details);
                if(status == LIST_EMPTY)
                    puts("List is empty");
                if(status == SUCCESS)
                {
                    puts("Details of the first record: ");
                    printf("ROLL NUMBER: %hu\nSTUDENT NAME: %s\nYEAR: %s\nDEPARTMENT: %s\nPERCENTAGE: %.3f\n", p_e_s_details->roll_no, p_e_s_details->s_name, p_e_s_details->year, p_e_s_details->department, p_e_s_details->percentage);
                }
                break;

            case 6:
                status = get_end(p_list, &p_e_s_details);
                if(status == LIST_EMPTY)
                    puts("List is empty");
                if(status == SUCCESS)
                {
                    puts("Details of the last record: ");
                    printf("ROLL NUMBER: %hu\nSTUDENT NAME: %s\nYEAR: %s\nDEPARTMENT: %s\nPERCENTAGE: %.3f\n", p_e_s_details->roll_no, p_e_s_details->s_name, p_e_s_details->year, p_e_s_details->department, p_e_s_details->percentage);
                }                
                break;

            case 7:
                printf("Enter roll no of student record to search: ");
                scanf("%llu",&s_roll_no);
                status = search_data(p_list, s_roll_no, &p_e_s_details);
                if(status == LIST_DATA_NOT_FOUND)
                    puts("Student with this roll no does not exist");
                else if(status == SUCCESS)
                {
                    puts("Details of the matching record: ");
                    printf("ROLL NUMBER: %hu\nSTUDENT NAME: %s\nYEAR: %s\nDEPARTMENT: %s\nPERCENTAGE: %.3f\n", p_e_s_details->roll_no, p_e_s_details->s_name, p_e_s_details->year, p_e_s_details->department, p_e_s_details->percentage);
                }
                break;

            case 8:
                show_list(p_list, "LIST OF ALL STUDENTS");
                break;

            case 9:
                find_length(p_list, &len);
                printf("NUMBER OF RECORDS = %d\n",len);
                break;

            case 0:
                puts("Thank you for using the application!!!");
                break;

            default:
                puts("Incorrect option, please try again");
        }
    }

    destroy_list(&p_list);

    exit(EXIT_SUCCESS);
}
