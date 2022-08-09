/*
Write a C program to toggle the case of input character
*/

#include<stdio.h>
#include<stdlib.h>

char ToggleCharacter(char ch);

int main(void)
{
    char ch;
    char toggled_character;
    printf("Enter character: ");
    scanf("%c",&ch);

    toggled_character = ToggleCharacter(ch);
    printf("Original character: %c\n",ch);
    printf("Toggled character: %c\n",toggled_character);

    exit(EXIT_SUCCESS);
}

char ToggleCharacter(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return (ch-32);
    else if(ch >= 'A' && ch <= 'Z')
        return (ch+32);
    else
        return ch;
}
