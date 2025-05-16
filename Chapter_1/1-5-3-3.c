#include <stdio.h>
// This program copies its input to its output, replacing each tab by \t, each backspace by \b,
//and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
int main()
{
    char c;

    while((c = getchar()) != EOF) {
        switch(c){
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\b':
                putchar('\\');
                putchar('b');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            default:
                putchar(c);
        }
    }
    return 0;
}