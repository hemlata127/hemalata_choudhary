#include "queue.h"

int main(void)
{
    queue_t* p_queue = create_queue();
    data_t data;

    int choice = 1;
    puts("==========================================================");
    puts("QUEUE IMPLEMENTATION USING DOUBLE CIRCULAR LINKED LIST");

    while(choice != 0)
    {
        puts("==========================================================");
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. Peek");
        puts("4. Show queue");
        puts("0. Exit");
        printf("Please enter an option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to add: ");
                scanf("%d",&data);
                insert_start(p_queue, data);
                break;

            case 2:
                if(is_queue_empty(p_queue) == FALSE)
                {
                    pop_end(p_queue, &data);
                    printf("Removed data is: %d\n",data);
                }
                else
                    puts("QUEUE EMPTY");
                break;

            case 3:
                if(is_queue_empty(p_queue) == FALSE)
                {
                    get_end(p_queue, &data);
                    printf("Peeked data is: %d\n",data);
                }
                else
                    puts("QUEUE EMPTY");
                break;

            case 4:
                show_queue(p_queue, "CURRENT QUEUE");
                break;

            case 0:
                puts("Thank you for using the application!!!");

            default:
                puts("Incorrect choice, please try again");
        }
    }

    destroy_queue(&p_queue);

    exit(EXIT_SUCCESS);
}