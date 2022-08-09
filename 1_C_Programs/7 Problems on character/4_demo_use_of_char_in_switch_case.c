/*
Problem statement: Demo of use of character in switch case construct. Accept division of student from user and depends on the division display exam timing. 
There are 4 divisions in school as A,B,C,D. Exam for different divisions is as per following schedule:
A at 7 AM, 
B at 8.30 AM, 
C at 9.20 AM
D at 10.30 AM. (Application should be case insensitive)
Input : C
Output : Your exam at 9.20 AM
Input : d
Output : Your exam at 10.30 AM
*/

#include<stdio.h>
#include<stdlib.h>

void DisplayExamTimings(char div);

int main(void)
{
    char div;
    printf("Enter class division: ");
    scanf("%c",&div);

    DisplayExamTimings(div);

    exit(EXIT_SUCCESS);
}

void DisplayExamTimings(char div)
{
    switch(div)
    {
        case 'A':
        case 'a':
            puts("Your exam is at 7 a.m.");
            break;
        case 'B':
        case 'b':
            puts("Your exam is at 8.30.");
            break;
        case 'C':
        case 'c':
            puts("Your exam is at 9.20 a.m.");
            break;
        case 'D':
        case 'd':
            puts("Your exam is at 10.30 a.m.");
        default:
            puts("Incorrect division");
    }
}
