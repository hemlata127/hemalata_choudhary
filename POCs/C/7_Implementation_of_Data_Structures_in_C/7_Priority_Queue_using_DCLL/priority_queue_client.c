#include "priority_queue.h"

int main(void)
{
    queue_t* p_queue = create_queue();
    int choice = 1;
    data_t data;

    puts("======================================================");
    puts("PRIORITY QUEUE AS DOUBLY CIRCULAR LINKED LIST");

    while(choice != 0)
    {
        puts("======================================================");
        puts("1. Enqueue");
        puts("2. Priority dequeue");
        puts("3. Show priority queue");
        puts("0. Exit");
        printf("Enter an option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to add to the queue: ");
                scanf("%d",&data);
                priority_enqueue(p_queue, data);
                break;

            case 2:
                if(is_priority_queue_empty(p_queue) == TRUE)
                    puts("PRIORITY QUEUE EMPTY");
                else
                {
                    priority_dequeue_min(p_queue, &data);
                    printf("Data = %d\n",data);
                }
                break;

            case 3:
                show_priority_queue(p_queue, "CURRENT PRIORITY QUEUE");
                break;

            case 0:
                puts("Thank you for using the application!!!");
                break;

            default:
                puts("Incorrect choice, please try again");
        }
    }

    destroy_priority_queue(&p_queue);

    exit(EXIT_SUCCESS);
}