#include <stdio.h>

int main()
{
    enum day { sunday, monday, tuesday, wednesday, thursday, friday, saturday};
    // starting at 0, it goes like -> sunday = 0, monday = sunday+1, tuesday = monday+1, etc.

    printf("%d", tuesday); // prints the number 2 to the screen.
}