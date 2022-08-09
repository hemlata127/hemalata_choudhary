#ifndef _SUBWAY_H
#define _SUBWAY_H

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

/* Choice of patty - select one option */
#define SUB_PATTY_ALOO 1
#define SUB_PATTY_HARA_BHARA_KABAB 2
#define SUB_PATTY_MEXICAN 3
#define SUB_PATTY_PANEER_TIKKA 4
#define SUB_PATTY_SHAMMI_KABAB 5

/* Choice of bread - select one option */
#define SUB_BREAD_FLAT 1
#define SUB_BREAD_HONEY_OAT 2
#define SUB_BREAD_MULTIGRAIN 3
#define SUB_BREAD_PARMESAN_OREGANO 4
#define SUB_BREAD_ROASTED_GARLIC 5
#define SUB_BREAD_WHITE_ITALIAN 6

/* choice of preparation - select one option */
#define SUB_PLAIN_BREAD 1
#define SUB_PLAIN_BREAD_WITH_CHEESE_SLICE 2
#define SUB_TOASTED_BREAD 3
#define SUB_TOASTED_BREAD_WITH_CHEESE_SLICE 4
#define SUB_TOASTED_BREAD_WITH_MOZARELLA_CHEESE 5

/* choice of veggies - can select multiple options */
#define SUB_VEG_CAPSICUM 1
#define SUB_VEG_CUCUMBER 2
#define SUB_VEG_JALEPANO 4
#define SUB_VEG_LETTUCE 8
#define SUB_VEG_ONION 16
#define SUB_VEG_PICKLE 32
#define SUB_VEG_SALT_AND_PEPPER 128
#define SUB_VEG_TOMATO 256

/* choice of sauces - can select multiple options */
#define SUB_SAUCE_BARBEQUE 1
#define SUB_SAUCE_CHIPTALE_SOUTH_WEST 2
#define SUB_SAUCE_HONEY_MUSTARD 4
#define SUB_SAUCE_MARINARA 8
#define SUB_SAUCE_MAYONNAISE 16
#define SUB_SAUCE_MINT_MAYONNAISE 32
#define SUB_SAUCE_RED_CHILLI 64
#define SUB_SAUCE_SWEET_ONION 128
#define SUB_SAUCE_TANDORI_MAYO 256

/* choice of addons - can select multiple options */
#define SUB_CHEESE_SLICE 1
#define SUB_MOZARELLA_CHEESE 2
#define SUB_VEG_PROTEIN 4
#define SUB_ADDON_EGG 8

#define TRUE 1
#define HALF_SECOND 500
#define ONE_SECOND 1000

//function declaration
static void Display_waiting_dots(void);

void display_banner();
void make_my_sub(int choice_of_patty, int choice_of_bread, int choice_of_prep, int choice_of_veggies, int choice_of_sauces, int choice_of_addons);

#endif
