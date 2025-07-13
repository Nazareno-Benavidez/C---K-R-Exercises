#include <stdio.h>

int main()
{
    int a[12] = { 4, 2, 8, 1, 9, 3, 7, 6, 0 };
    int b[12] = { 2, 3, 7, 1, 0};

    printf("%d%d%d%d%d", a[b[0]], a[b[1]], a[b[2]], a[b[3]], a[b[4]]); // prints 81624
}