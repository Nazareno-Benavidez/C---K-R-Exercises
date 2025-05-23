#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 4


int my_get_line(char line[], char newline[], int maxline, int tab_width);

/* Exercise 1−21. Write a program entab that replaces strings of blanks by the minimum number of tabs and
blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank
would suffice to reach a tab stop, which should be given preference? */
int main()
{
    int len;
    char line[MAXLINE];
    char newline[MAXLINE];
    
    while((len = my_get_line(line, newline, MAXLINE, TAB_WIDTH)) > 0)
        printf("%s\n", newline);

    return 0;
}

int my_get_line(char line[], char newline[], int maxline, int tab_width)
{
    int c, i, j, k;
    int next_tab_stop = tab_width;
    int counter = 0;

    k = 0;
    for(i = 0; i < maxline-tab_width && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    for(j = 0; j < maxline-tab_width && k <= i; j++){
        next_tab_stop = ((j / tab_width) + 1) * tab_width;
        if(line[k] == ' '){
            while(line[k] == ' '){
                counter++;
                k++;
            }
            k--;
            while(next_tab_stop <= (j + counter)){
                next_tab_stop += tab_width;
                newline[j] = '\t';
                counter -= 4;
                j++;
            }
            while(counter > 0){
                newline[j] = ' ';
                j++;
                counter--;
            }
            j--;
        }
        else
            newline[j] = line[k];
        counter = 0;
        k++;
    }

    newline[j] = '\0';
    return i;
}