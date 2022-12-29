#include "binary_search_tree.h"

int main(void)
{
    bst_t* p_bst = NULL;
    status_t status;
    data_t new_data, e_data;
    data_t pred_data, succ_data, min_data, max_data;
    uint_t i;
    int choice = 1;

    p_bst = create_bst();

    puts("=====================================================");
    puts("IMPLEMENTATION OF BINARY SEARCH TREE");

    while(choice != 0)
    {
        puts("=====================================================");
        puts("1. Check if tree is empty");
        puts("2. Insert data");
        puts("3. Preorder traversal");
        puts("4. Inorder traversal");
        puts("5. Postorder traversal");
        puts("6. Search data");
        puts("7. Find inorder predecessor");
        puts("8. Find inorder successor");
        puts("9. Find max element");
        puts("10. Find min element");
        puts("11. Remove data");
        puts("0. Exit the application");

        printf("Please select an option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                status = is_bst_empty(p_bst);
                if(status == TRUE)
                    puts("Tree is empty");
                else if(status == FALSE)
                    puts("Tree is not empty");
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d",&new_data);
                status = bst_insert(p_bst, new_data);
                if(status == SUCCESS)
                    puts("Data inserted successfully");
                break;

            case 3:
                puts("PREORDER TREE TRAVERSAL");
                preorder_r(p_bst);
                break;

            case 4:
                puts("INORDER TRAVERSAL");
                inorder_r(p_bst);
                break;


            case 5:
                puts("POSTORDER TRAVERSAL");
                postorder_r(p_bst);
                break;

            case 6:
                printf("Enter data to search: ");
                scanf("%d",&e_data);
                status = bst_search(p_bst, e_data);
                if(status == TRUE)
                    printf("%d is present in tree\n",e_data);
                else if(status == FALSE)
                    printf("%d is not present\n",e_data);
                break;

            case 7:
                printf("Enter data whose predecessor to find: ");
                scanf("%d",&e_data);
                status = find_bst_inorder_predecessor(p_bst, e_data, &pred_data);
                if(status == TREE_NO_PREDECESSOR)
                    printf("%d has no predecessor\n",e_data);
                else if(status == SUCCESS)
                    printf("Predecessor of %d is %d\n",e_data, pred_data);
                break;

            case 8:
                printf("Enter data whose successor to find: ");
                scanf("%d",&e_data);
                status = find_bst_inorder_successor(p_bst, e_data, &pred_data);
                if(status == TREE_NO_SUCCESSOR)
                    printf("%d has no successor\n",e_data);
                else if(status == SUCCESS)
                    printf("Successor of %d is %d\n",e_data, pred_data);
                break;

            case 9:
                status = find_bst_max(p_bst, &max_data);
                if(status == SUCCESS)
                    printf("Max data = %d\n",max_data);
                break;

            case 10:
                status = find_bst_min(p_bst, &min_data);
                if(status == SUCCESS)
                    printf("Min data = %d\n",min_data);
                break;


            case 11:
                printf("Enter data to remove: ");
                scanf("%d", &e_data);
                status = remove_data(p_bst, e_data);
                if(status == SUCCESS)
                {
                    printf("BST after removing %d: \n",e_data);
                    inorder_r(p_bst);
                }
                else if(status == TREE_DATA_NOT_FOUND)
                    printf("%d not found in the tree\n",e_data);
                break;

            case 0:
                puts("Thank you for using the application!!!");
                break;

            default:
                puts("Incorrect option, please try again");
        }
    }


    exit(EXIT_SUCCESS);
}