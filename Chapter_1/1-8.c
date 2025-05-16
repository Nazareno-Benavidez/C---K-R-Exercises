#include <stdio.h>

/* Call pass by value */
void my_function(int x);

int main()
{
    int a = 10;
    my_function(a); // my function receives the value of a BUT DOES NOT CHANGE a ITSELF! It just stores its value in a temporary variable, x.
    printf("%d", a); // prints 10 -> the value of a
}

void my_function(int x)
{
    ++x; // the current value of x increase by one. If we pass the value of a, then x = 11. However, it is all temporal
    printf("%d", x); // prints x + 1; 11 in this example.
}

/* Call by value is an asset, however, not a liability. 
It could never be a liability. It simplifies everything a lot, you would just need to make a pointer be a parameter
in case you wanted to directly modify a variable or just return the value of the modified one and assign it to the original variable. 
Very simple yet so useful. */ 