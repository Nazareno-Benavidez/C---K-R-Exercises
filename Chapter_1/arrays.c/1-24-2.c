#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 1000

int len;

void my_get_code(char code[], int maxlen);
void check_syntax(char code[], char opening, char ending);
void check_esc_seq(char code[]);
void check_comments(char code[]);

/* Exercise 1−24. Write a program to check a C program for rudimentary syntax errors like unmatched
parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and
comments. (This program is hard if you do it in full generality.) */
// to solve for comments, where parantheses, brackets, braces, etc, might be unmaatched, create a bool variable "isComment". if(!isComment)
int main()
{
    char code[MAXLEN];

    my_get_code(code, MAXLEN);

    check_syntax(code, '{', '}');
    check_syntax(code, '(', ')');
    check_syntax(code, '[', ']');
    check_syntax(code, '\'', '\'');
    check_syntax(code, '\"', '\"'); 
    check_esc_seq(code);
    check_comments(code);

    return 0;
}

void my_get_code(char code[], int maxlen)
{
    int c;
    
    extern int len;

    for(len = 0; len < maxlen-1 && (c = getchar()) != EOF; len++)
        code[len] = c;
    code[len] = '\0';
}

void check_syntax(char code[], char opening, char ending)
{
    int i, k;
    int last_token = 0;
    int unmatched_tokens = 0;
    bool matchedToken = false;
    extern int len;

    i = 0;
    for(k = 0; k < len; k++){
        i = k;
        if(code[k] == opening){
            i++;
            while(code[k] == opening && matchedToken == false && i < len){
                if(code[i] == ending && i > last_token){
                    last_token = i;
                    matchedToken = true;
                }
                else
                    i++;
            }
            if(matchedToken == false)
                unmatched_tokens++;
            matchedToken = false;
        }
    }
    
    printf("\nNumber of unmatched %c%c tokens: %d\n", opening, ending, unmatched_tokens);
}

void check_esc_seq(char code[])
{
    int k, i;
    int unmatched_esc_seq = 0;
    bool unmatched_esc = false;

    i = 0;

    extern int len;

    for(k = 0; k < len; k++){
        if(code[k] == '\'' && code[k+1] == '\\'){
            k+=2;
            if(code[k] == 'a' || code[k] == 'b' || code[k] == 'e' || code[k] == 'f' || code[k] == 'n' || code[k] == 'r' 
                || code[k] == 't' || code[k] == 'v' || code[k] == '\\' || code[k] == '\'' || code[k] == '\"' || code[k] == '\?'
                || code[k] == 'x' || code[k] == 'u')
                {
                    unmatched_esc = false;
                }
            else
                unmatched_esc = true;
        } 
        if(unmatched_esc == true)
            unmatched_esc_seq++;
        unmatched_esc = false;
    }

    printf("\nNumber of unmatched ESCAPE SEQUENCES: %d\n", unmatched_esc_seq);
}

void check_comments(char code[])
{
    int k, i;
    int unmatched_comments = 0;

    extern int len;

    i = 0;
    for(k = 0; k < len; k++){
        if(code[k] == '/' && code[k+1] == '*'){
            k+=2;
            while((code[k] != '*' && code[k+1] != '/') && k < len)
                k++;
            if(code[k] == '*' && code[k+1] == '/')
                k+=2;
            else
                unmatched_comments++;
                // break;      
        }
    }
    printf("\nNumber of unmatched COMMENTS: %d\n", unmatched_comments);
}