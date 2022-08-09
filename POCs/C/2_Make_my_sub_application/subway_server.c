#include "subway.h"

//display waiting dots
static void Display_waiting_dots(void)
{
    int count = 0;
    while(count<3)
    {
        printf(".");
        Sleep(HALF_SECOND);
        count = count+1;
    }
    puts("DONE");
}

//display banner
void display_banner()
{
    puts("|||||||  ||     ||  |||||||    ||         ||       ||      ||    ||");
    puts("||	 ||     ||  ||    ||   ||    |    ||      ||||      ||  ||");
    puts("|||||||  ||     ||  |||||||    ||   |||   ||     ||  ||       ||");
    puts("     ||   ||   ||   ||    ||   ||  |||||  ||    ||||||||      ||");
    puts("|||||||	   ||||||   |||||||     ||||| |||||    ||      ||     ||");
}

void make_my_sub(int choice_of_patty, int choice_of_bread, int choice_of_prep, int choice_of_veggies, int choice_of_sauces, int choice_of_addons)
{
    puts("Preparing your sub");
    //patty
    puts("PATTY");
    printf("Getting ");
    switch(choice_of_patty)
    {
        case SUB_PATTY_ALOO:
            printf("aloo patty");
            break;
        case SUB_PATTY_HARA_BHARA_KABAB:
            printf("hara bhara kabab");
            break;
        case SUB_PATTY_MEXICAN:
            printf("mexican patty");
            break;
        case SUB_PATTY_PANEER_TIKKA:
            printf("paneer tikka patty");
            break;
        case SUB_PATTY_SHAMMI_KABAB:
            printf("shammi kabab");
            break;
    }
    Display_waiting_dots();

    //Bread
    puts("BREAD");
    printf("Getting ");
    switch(choice_of_bread)
    {
        case SUB_BREAD_FLAT:
            printf("flat bread");
            break;
        case SUB_BREAD_HONEY_OAT:
            printf("honey oat bread");
            break;
        case SUB_BREAD_MULTIGRAIN:
            printf("multigrain bread");
            break;
        case SUB_BREAD_PARMESAN_OREGANO:
            printf("parmesan oregano");
            break;
        case SUB_BREAD_ROASTED_GARLIC:
            printf("roasted garlic bread");
            break;
        case SUB_BREAD_WHITE_ITALIAN:
            printf("white italian bread");
            break;
    }
    Display_waiting_dots();

    //preparation
    if(choice_of_prep == SUB_TOASTED_BREAD || choice_of_prep == SUB_TOASTED_BREAD_WITH_CHEESE_SLICE || choice_of_prep == SUB_TOASTED_BREAD_WITH_MOZARELLA_CHEESE)
    {
        printf("Toasting");
        Display_waiting_dots();

    }

    //veggies
    puts("VEGGIES");
    if((choice_of_veggies & SUB_VEG_CAPSICUM) == SUB_VEG_CAPSICUM)
    {
        printf("Adding capsicum");
        Display_waiting_dots();
    }
    if((choice_of_veggies & SUB_VEG_CUCUMBER) == SUB_VEG_CUCUMBER)
    {
        printf("Adding cucumber");
        Display_waiting_dots();
    }
    if((choice_of_veggies & SUB_VEG_JALEPANO) == SUB_VEG_JALEPANO)
    {
        printf("Adding jalepano");
        Display_waiting_dots();
    }
    if((choice_of_veggies & SUB_VEG_LETTUCE) == SUB_VEG_LETTUCE)
    {
        printf("Adding lettuce");
        Display_waiting_dots();
    }
    if((choice_of_veggies & SUB_VEG_ONION) == SUB_VEG_ONION)
    {
        printf("Adding onion");
        Display_waiting_dots();
    }
    if((choice_of_veggies & SUB_VEG_PICKLE) == SUB_VEG_PICKLE)
    {
        printf("Adding pickle");
        Display_waiting_dots();
    }
    if((choice_of_veggies & SUB_VEG_SALT_AND_PEPPER) == SUB_VEG_SALT_AND_PEPPER)
    {
        printf("Adding salt and pepper");
        Display_waiting_dots();
    }
    if((choice_of_veggies & SUB_VEG_TOMATO) == SUB_VEG_TOMATO)
    {
        printf("Adding tomato");
        Display_waiting_dots();
    }

    //sauces
    puts("SAUCES");
    if((choice_of_sauces & SUB_SAUCE_BARBEQUE) == SUB_SAUCE_BARBEQUE)
    {
        printf("Adding barbeque");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_CHIPTALE_SOUTH_WEST) == SUB_SAUCE_CHIPTALE_SOUTH_WEST)
    {
        printf("Adding chiptale south west");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_HONEY_MUSTARD) == SUB_SAUCE_HONEY_MUSTARD)
    {
        printf("Adding honey mustard");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_MARINARA) == SUB_SAUCE_MARINARA)
    {
        printf("Adding marinara");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_MAYONNAISE) == SUB_SAUCE_MAYONNAISE)
    {
        printf("Adding mayonnaise");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_MINT_MAYONNAISE) == SUB_SAUCE_MINT_MAYONNAISE)
    {
        printf("Adding mint mayonnaise");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_RED_CHILLI) == SUB_SAUCE_RED_CHILLI)
    {
        printf("Adding red chill sauce");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_SWEET_ONION) == SUB_SAUCE_SWEET_ONION)
    {
        printf("Adding sweet onion sauce");
        Display_waiting_dots();
    }
    if((choice_of_sauces & SUB_SAUCE_TANDORI_MAYO) == SUB_SAUCE_TANDORI_MAYO)
    {
        printf("Adding barbeque");
        Display_waiting_dots();
    }

    //add-ons
    if((choice_of_addons & SUB_CHEESE_SLICE) == SUB_CHEESE_SLICE)
    {
        printf("Adding extra cheese slice");
        Display_waiting_dots();
    }
    if((choice_of_addons & SUB_MOZARELLA_CHEESE) == SUB_MOZARELLA_CHEESE)
    {
        printf("Adding mozarella cheese");
        Display_waiting_dots();
    }
    if((choice_of_addons & SUB_VEG_PROTEIN) == SUB_VEG_PROTEIN)
    {
        printf("Adding veg protein");
        Display_waiting_dots();
    }
    if((choice_of_addons & SUB_ADDON_EGG) == SUB_ADDON_EGG)
    {
        printf("Adding add-on egg");
        Display_waiting_dots();
    }
    puts("Your sub is ready!!");
    puts("Thank you for eating with us");
}
