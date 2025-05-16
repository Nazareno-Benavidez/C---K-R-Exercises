#include <stdio.h>
//character counter program.
void main()
{
    // long nc; 

    // nc = 0;
    
    // while(getchar() != EOF)
    //     ++nc;
    // printf("%ld \n", nc);

    double nc;

    for(nc = 0; getchar() != EOF; ++nc)
        ;
    printf("\n%.0f \n", nc);
}