#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 1000

int len;

void my_get_code(char code[], int maxlen);
void check_braces(char code[]);
void check_parentheses(char code[]);
void check_brackets(char code[]);

/* Exercise 1−24. Write a program to check a C program for rudimentary syntax errors like unmatched
parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and
comments. (This program is hard if you do it in full generality.) */
// to solve for comments, where parantheses, brackets, braces, etc, might be unmaatched, create a bool variable "isComment". if(!isComment)
int main()
{
    char code[MAXLEN];
    
    my_get_code(code, MAXLEN);
    check_braces(code);
    check_parentheses(code);
    check_brackets(code);
}

void my_get_code(char code[], int maxlen)
{
    int c;
    
    extern int len;

    for(len = 0; len < maxlen-1 && (c = getchar()) != EOF; len++)
        code[len] = c;
    code[len] = '\0';
}

void check_braces(char code[])
{
    int i, k;
    int last_brace = 0;
    int unmatched_braces = 0;
    bool matchedBrace = false;
    extern int len;

    i = 0;
    for(k = 0; k < len; k++){
        i = k;
        if(code[k] == '{'){
            while(code[k] == '{' && matchedBrace == false && i < len){
                if(code[i] == '}' && i > last_brace){
                    last_brace = i;
                    matchedBrace = true;
                }
                else
                    i++;
            }
            if(matchedBrace == false)
                unmatched_braces++;
            matchedBrace = false;
        }
    }

    printf("\nNumber of unmatched braces: %d\n", unmatched_braces);
}

void check_parentheses(char code[])
{
    int i, k;
    int last_par = 0;
    int unmatched_par = 0;
    bool matchedPar = false;
    extern int len;

    i = 0;
    for(k = 0; k < len; k++){
        i = k;
        if(code[k] == '('){
            while(code[k] == '(' && matchedPar == false && i < len){
                if(code[i] == ')' && i > last_par){
                    last_par = i;
                    matchedPar = true;
                }
                else
                    i++;
            }
            if(matchedPar == false)
                unmatched_par++;
            matchedPar = false;
        }
    }

    printf("\nNumber of unmatched parentheses: %d\n", unmatched_par);
}

void check_brackets(char code[])
{
    int i, k;
    int last_bracket = 0;
    int unmatched_brackets = 0;
    bool matchedBracket = false;
    extern int len;

    i = 0;
    for(k = 0; k < len; k++){
        i = k;
        if(code[k] == '['){
            while(code[k] == '[' && matchedBracket == false && i < len){
                if(code[i] == ']' && i > last_bracket){
                    last_bracket = i;
                    matchedBracket = true;
                }
                else
                    i++;
            }
            if(matchedBracket == false)
                unmatched_brackets++;
            matchedBracket = false;
        }
    }

    printf("\nNumber of unmatched brackets: %d\n", unmatched_brackets);
}