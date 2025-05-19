#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 8

int my_get_line(char line[], char newline[], int maxline, int tab_width);

/* Exercise 1−21. Write a program entab that replaces strings of blanks by the minimum number of tabs and
blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank
would suffice to reach a tab stop, which should be given preference? */
int main()
{
    int len;
    char line[MAXLINE], newline[MAXLINE];

    while((len = my_get_line(line, newline, MAXLINE, TAB_WIDTH)) > 0)
        printf("%s\n", newline);
}

int my_get_line(char line[], char newline[], int maxline, int tab_width)
{
    int c, i, j, n_b;

    int next_tab_stop = tab_width; 
    for(i = 0; i < maxline-tab_width && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    line[i] = '\0';

    for(j = 0; j <= i; j++){
        if(line[j] == ' '){
            while(line[j] == ' '){
                counter++;
                j++;
            }
            if(counter > 1){
                next_tab_stop = ((j/tab_width)+ 1) / tab_width - j;

            }
        }
    }
}