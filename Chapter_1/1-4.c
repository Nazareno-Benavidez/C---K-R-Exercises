#include <stdio.h>

#define LOWEST 0    /* lowest limit of the table */
#define UPPERMOST 300   /* highest limit of the table */
#define STEP 20 /* step size */

/*print Fahrenheit-Celsius table*/
void main()
{
    int fahr;

    printf("\t -- Fahrenheit-Celsius Table -- \n");
    for(fahr = LOWEST; fahr <= UPPERMOST; fahr += STEP)
        printf("\t \t %3d %6.1f \n", fahr, (5.0/9.0) * (fahr-32));
}
/*
 A #define line defines a symbolic name or symbolic constant to be a particular string of characters.
 Thereafter, any occurrence of name (not in quotes and not part of another name) will be replaced by the
 corresponding replacement text.
 There is no semicolon at the end of a #define
 line.
*/