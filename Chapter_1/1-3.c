#include <stdio.h>

void main()
{
    int fahr;

    for(fahr = 300; fahr >= 0; fahr -= 20)
        printf("%3d %6.1f\n", fahr, (5.0f/9.0f) * (fahr-32));
}