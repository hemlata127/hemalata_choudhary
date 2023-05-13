#include<stdio.h>

int main(void)
{
	//code
	printf("\n\n");
	printf("Goimg on to the next line using \\n escape sequence\n\n");
	printf("Demonstrating \t Horizontal \t Tab \t using \\t escape sequence\n\n");
	printf("\"This is a Double Quoted output\" done using \\\" escape sequence\\n\n");

	printf("\'This is a Single Quoted output\' done using \\\' escape sequence\\n\n");
	printf("BACKSPACE turned to BACKSPACE\b using \\b escape sequence\n\n");

	printf("\r Demonstrating carriage return using \\r escape sequence\n");
	printf("Demonstrating \r carriage return using \\r escape sequence\n");
	printf("Demonstrating carriage \r return using \\r escape sequence\n\n");

	printf("Demonstrating \x41 using \\xhh escape sequence\n\n");
	//0x41 is the hexadecimal code for letter 'A'. xhh is the place holder for 'x'
	//followed by 2 digits (hh), altogether formating a hexadecimal number
	printf("Demonstrating \102 using \\ooo escape sequence\n\n");
	//octal code for letter 'B'. ooo is the place holder for 3 digits formatting an octal number

	return (0);
}
