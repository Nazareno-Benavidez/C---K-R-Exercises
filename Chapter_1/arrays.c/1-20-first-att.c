#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 3

int my_get_line(char line[], int maxline, int tab_width);

/* Every tab is transformed into 3 blanks or whatever TAB_WIDTH value shall be */
int main()
{
    int len;
    char line[MAXLINE];

    while((len = my_get_line(line, MAXLINE, TAB_WIDTH)) > 0)
        printf("%s\n", line);
}

int my_get_line(char line[], int maxline, int tab_width)
{
    int c, i, j;

    for(i = 0; i < maxline-tab_width && (c = getchar()) != EOF && c != '\n'; i++){
        if(c == '\t'){
            for(j = 0; j < tab_width; j++) {
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