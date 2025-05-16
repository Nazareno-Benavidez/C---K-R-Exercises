#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300.*/
void main()
{
    float fahr, celsius;
    float lowest, uppermost, step; 

    lowest = 0;  /* lowest limit of temperature scale */
    uppermost = 300; /* uppermost limit */
    step = 20; /* step size */


    fahr = lowest;
    printf("---- Fahrenheit to Celsius conversion program ---- \n");
    while(fahr <= uppermost) {
        celsius = (5.0/9.0) * (fahr-32.0); // Fahrenheit-Celsius formula
        printf("\t \t %3.0f %6.1f \n", fahr, celsius); // Print f, where %3f refers to the number of characters wide of fahr and 0 to the number of floating-point numbers. 
        fahr = fahr + step;
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