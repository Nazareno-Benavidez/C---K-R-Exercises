#include <stdio.h>

void main()
{
    float celsius, fahr;
    float lowest, uppermost, step;

    lowest = -17.8;
    uppermost = 148.9;
    step = (5.0/9) * 20;

    celsius = lowest;
    printf("---- Celsius to Fahrenheit conversion program ---- \n");
    while(celsius <= uppermost){
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("\t \t %3.1f %6.1f \n", celsius, fahr);
        celsius = celsius + step;
    }
}
/* 
%6d print as decimal integer, at least 6 characters wide
%f print as floating point
%6f print as floating point, at least 6 characters wide
%.2f print as floating point, 2 characters after decimal point
%6.2f print as floating point, at least 6 wide and 2 after decimal point
Among others, printf also recognizes %o for octal, %x for hexadecimal, %c for character, %s for character
string and %% for itself.
*/