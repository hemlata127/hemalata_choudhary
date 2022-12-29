#include "subway.h"

int main(void)
{
    int choice_of_patty = 0, choice_of_bread = 0, choice_of_prep = 0, choice_of_veggies = 0, choice_of_sauces = 0, choice_of_addons = 0;
    int ans = 0;
    int nr_try = 0;
    display_banner();

    //selection of patty
    nr_try = 1;
    puts("-----------------------------------------------------");
    puts("WELCOME TO MAKE MY SUB APPLICATION\nLets make your SUB!!");
    puts("-----------------------------------------------------");
    puts("CHOICE OF PATTY");
    puts("1. Aloo patty");
    puts("2. Hara bhara kabab");
    puts("3. Mexican patty");
    puts("4. Paneer tikka");
    puts("5. Shammi kabab");
    printf("Please select your patty: ");
    while(TRUE)
    {
        scanf("%d",&choice_of_patty);
        if(choice_of_patty >= 1 && choice_of_patty <= 5)
        {
            break;
        }
        if(nr_try == 3)
        {
            puts("Sorry we could not understand your order.");
            puts("Thanks for using my sub application. Good day!");    
            exit(-1);        
        }
        nr_try = nr_try+1;
        printf("Invalid option for patty: %d, please try again\n",choice_of_patty);
        printf("Please select your patty: ");
    }
    puts("-----------------------------------------------------");

    //selection of bread
    puts("CHOICE OF BREAD");
    nr_try = 1;
    puts("1. Flat bread");
    puts("2. Honey oat");
    puts("3. Multigrain bread");
    puts("4. Parmesan oregano");
    puts("5. White italian bread");
    printf("Please select the bread: ");
    while(TRUE)
    {
        scanf("%d",&choice_of_bread);
        if(choice_of_bread >= 1 && choice_of_bread <= 6)
        {
            break;
        }
        if(nr_try == 3)
        {
            puts("Sorry we could not understand your order.");
            puts("Thank you for using my sub application. Good day!");
            exit(-1);
        }
        nr_try = nr_try + 1;
        printf("Incorrect option for bread: %d, please try again\n", choice_of_bread);
        printf("Please select the bread: ");
    }
    puts("-----------------------------------------------------");

    //choice of preperation
    puts("Please tell us, how we should prepare your bread");
    nr_try = 1;
    puts("1. Plain bread");
    puts("2. Plain bread with cheese slice");
    puts("3. Toasted bread");
    puts("4. Toasted bread with cheese slice");
    puts("5. Toasted bread with mozarella cheese");
    printf("Please select your choice for preparing bread: ");
    while(TRUE)
    {
        scanf("%d",&choice_of_prep);
        if(choice_of_prep >= 1 && choice_of_prep <= 5)
        {
            break;
        }
        if(nr_try == 3)
        {
            puts("Sorry we could not understand your order.");
            puts("Thank you for using my sub application. Good day!");
            exit(-1);
        }
        nr_try = nr_try + 1;
        printf("Invalid choice of bread preparation: %d, please try again\n",choice_of_prep);
        printf("Please select your choice for preparing bread: ");
    }
    puts("-----------------------------------------------------");

    //Select veggies
    puts("Let's select your veggies!");
    printf("Add capsicum? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_CAPSICUM;
    }
    printf("Add cucumber? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_CUCUMBER;
    }
    printf("Add jalepano? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_JALEPANO;
    }
    printf("Add lettuce? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_LETTUCE;
    }
    printf("Add onion? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_ONION;
    }
    printf("Add pickle? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_PICKLE;
    }
    printf("Add salt and pepper? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_SALT_AND_PEPPER;
    }
    printf("Add tomato? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_veggies = choice_of_veggies | SUB_VEG_TOMATO;
    }
    puts("-----------------------------------------------------");
    
    //Select sauces
    puts("Let's add yummy sauces to your sub!");
    printf("Add barbequeus sauce? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_BARBEQUE;
    }
    printf("Add chiptale south west? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_CHIPTALE_SOUTH_WEST;
    }
    printf("Add honey mustard? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_HONEY_MUSTARD;
    }
    printf("Add marinara? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_MARINARA;
    }
    printf("Add mayonnaise? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_MAYONNAISE;
    }
    printf("Add mint mayonnaise? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_MINT_MAYONNAISE;
    }
    printf("Add red chilli? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_RED_CHILLI;
    }
    printf("Add sweet onion? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_SWEET_ONION;
    }
    printf("Add tandori mayo? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_sauces = choice_of_sauces | SUB_SAUCE_TANDORI_MAYO;
    }
    puts("-----------------------------------------------------");

    //Addons
    puts("Lets make your sub extra special");
    printf("Add extra cheese slice? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_addons = choice_of_addons | SUB_CHEESE_SLICE;
    }
    printf("Add mozarella cheese? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_addons = choice_of_addons | SUB_MOZARELLA_CHEESE;
    }
    printf("Add veg protein? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_addons = choice_of_addons | SUB_VEG_PROTEIN;
    }
    printf("Add add-on egg? [1] Yes, [0] No: ");
    scanf("%d",&ans);
    if(ans == 1)
    {
        choice_of_addons = choice_of_addons | SUB_ADDON_EGG;
    }
    puts("-----------------------------------------------------");

    make_my_sub(choice_of_patty, choice_of_bread, choice_of_prep, choice_of_veggies, choice_of_sauces, choice_of_addons);

    exit(0);
}
