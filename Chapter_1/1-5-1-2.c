#include <stdio.h>
/* EOF (End of File) Summary:
   - EOF is a special integer constant (usually -1) defined in <stdio.h>.
   - It signals that there is no more input from stdin or a file.
   - getchar() and fgetc() return EOF when input is exhausted.
   - Useful for controlling loops that read input dynamically.
   - To manually enter EOF: Ctrl+D (Linux/macOS) or Ctrl+Z then Enter (Windows).
*/
/* EOF in file handling:
   - Used to detect the end of a file when reading data.
   - fgetc() returns EOF when no more characters can be read.
   - feof(FILE*) confirms if EOF was reached.
   - Prevents reading invalid data beyond the file's content.
*/

void main()
{
    int c;

    printf("%d \n", EOF);

    while(c = (getchar() != EOF) != 0){ //getchar() takes input
        printf("\n%d\n", c);
    }

    printf("EOF Reached: %d \n", c);
}