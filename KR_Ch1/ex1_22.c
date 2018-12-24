/* Version 1: does not break before the max length, potentionally can
exceed the max line length for printing. */

#include <stdio.h>
#define MAXLEN 80 //max chars per line

main() {
    int c, i;
    int count;

    count = 0;
    while ((c = getchar()) != EOF) {
        /* print char if under the MAXLEN*/
        if ( (count < MAXLEN) || (count >= MAXLEN && c != ' ' && c != '\t') ) {
            putchar(c);
        }
        else {
            putchar('\n');
            for (i = 0; i < 3; ++i)
                putchar('.'); // denotes break in line
            count = -1; // since count occurs at end
        }
        ++count;
    }
    return 0;
}
