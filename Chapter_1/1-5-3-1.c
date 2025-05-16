#include <stdio.h> 
//program to count newlines, blanks and tabs

int main()
{
    char c;
    int nc = 0, b = 0, t = 0, nl = 0; //c = character, nc = new character, b = blanks, t = tabs and nl = newlines.
    
    while((c = getchar()) != EOF){
        switch(c){
            case '\n':
                ++nl;
                break;
            case '\t':
                ++t;
                break;
            case ' ':
                ++b;
                break;
            default:
                ++nc; 
        }
    }
    printf("\n Character count: %d\n Newline count: %d\n Tab count: %d\n Blank count: %d\n", nc, nl, t, b);

    return 0;
}