#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 4 /* a tab stop occurs every TAB_WIDTH columns. Example: with input "heya C#\t"
                    if C# ends at column 6 and tab stops are every 4 columns, only 2 spaces are added to reach column 8 "heya C#  \0". */

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

/* Reads a line from input, replacing tabs with the appropriate number of spaces according to fixed width tab stops. 
   Returns the length of the resulting line. */
int my_get_line(char line[], int maxline, int tab_width)
{
    int c, i;
    int next_tab_stop = tab_width; // The first tab stop is set to be at the tab_width value column. 
    //int j = 0;
    for(i = 0; i < maxline-tab_width && (c = getchar()) != EOF && c != '\n'; i++){ /* i < maxline - tab_width to ensure that if 4 blanks 
                                                                                    are added, the array has enough elements + 1*/
                      // initial failed approach: it doesn't work because i gets updated when c == '\t', so j ends up desynchronised
                     // if(j >= tab_width){
                    //     j = 0;
                   //     next_tab_stop += tab_width;
                  // }
                 // else
                //     j++;
         // Update next_tab_stop until it lies ahead of current position `i`.
         // Example: if tab stops are every 4 columns and `i == 8`, we must ensure
         // next_tab_stop becomes 12, not stay stuck at 8 (or lower).
        while(i >= next_tab_stop) 
            next_tab_stop += tab_width; 
        if(c == '\t'){ 
            // insert spaces until the next tab stop is reached
           while((next_tab_stop - i) > 0){ // while next_tab_stop - current column(i) > 0 = there are more columns from current to n_t_s
            line[i] = ' '; // current column's value is set to be a blank
            i++; // i is increased to proceed onto the next column
           }
           i--;  // i is decreased to get rid of the extra +1 that i will get once the current iteration of the for loop gets completed
        }
        else
            line[i] = c; 
    }

    line[i] = '\0';
    return i;
}