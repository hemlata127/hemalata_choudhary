#include "stack.h"

int main(void)
{
    stack_t* p_stack = create_stack();
    data_t data;
    int choice = 1;

    puts("===========================================================");
    puts("IMPLEMENTATION OF STACK USING DOUBLY CIRCULAR LINKED LIST");
    
    while(choice != 0)
    {
        puts("===========================================================");
        puts("1. Push");
        puts("2. Pop");
        puts("3. Top");
        puts("4. Show stack");
        puts("0. Exit");
        printf("Please enter an option: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d",&data);
                push(p_stack, data);
                break;

            case 2:
                if(pop(p_stack, &data) == SUCCESS)
                    printf("Popped data is: %d\n",data);
                else
                    puts("STACK_EMPTY");
                break;

            case 3:
                if(top(p_stack, &data) == SUCCESS)
                    printf("Data on top of stack is: %d\n", data);
                else
                    puts("STACK_EMPTY");
                break;

            case 4:
                show_stack(p_stack, "CURRENT STACK");
                break;

            case 0:
                puts("Thank you for using the application!!");
                break;

            default:
                puts("Incorrect choice");
        }
    }

    destroy_stack(&p_stack);
}
