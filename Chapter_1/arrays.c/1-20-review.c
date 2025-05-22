#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

int my_get_line(char line[], int maxline, int tab_width);

/* Exercise 1−20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. 
Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? Symbolic parameter. (defined above) */
int main()
{
    int len;
    char line[MAXLINE];

    while((len = my_get_line(line, MAXLINE, TAB_WIDTH)) > 0)
        printf("%s\n", line);
}

int my_get_line(char line[], int maxline, int tab_width)
{
    int c, i;
    int next_tab_stop = tab_width;

    for(i = 0; i < maxline-tab_width && (c = getchar()) != EOF && c != '\n'; i++){
        next_tab_stop = ((i / tab_width) + 1) * tab_width;
        if(c == '\t'){
            while((next_tab_stop - i) > 0){
                line[i] = ' ';
                i++;
            }
            i--;
        }
        else
            line[i] = c;
    }

    line[i] = '\0';
    return i;
}