#include <stdio.h>

int main()
{
    for(int i = 0; i < 5; ++i){
        // 'static' means the variable is initialized only once and keeps its value between iterations.
        static int n = 0;

        // If 'static' were removed, 'n' would be an automatic (stack) variable,
        // re-initialized to 0 each time the loop runs, so ++n would always be 1.
        printf("%d", ++n);
    }

    
    return 0;
}

/*
🔁 Why is the automatic variable reinitialized every time?

When you write:

int n = 0;

inside a loop or function block, n is an automatic variable, meaning:

    It is stored in the stack.

    It only exists during the execution of that block.

    Each time the loop runs, that block is entered again, and the variable is newly created and initialized to 0.

    After that iteration ends, the variable is destroyed.

That’s why it “starts from scratch” every time.
📌 Why is the static variable not reinitialized?

When you write:

static int n = 0;

you’re telling the compiler:

    Store n in a special area of memory (called static storage, not the stack).

    Initialize it only once, when the program reaches that line for the first time.

    Keep its value between calls or iterations.

    Don't destroy it when the block ends.

So the next time the loop runs, n still exists and has the value it had at the end of the last iteration.
*/