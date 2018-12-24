#include <stdio.h>

/* Since all inputs are ASCII ints, input from 0-127 */

main() {
    int c, i, j;
    int hist[128];

    for (i = 0; i < 128; ++i)
        hist[i] = 0;

    while( (c = getchar()) != EOF) {
        if (c < 32)
            ; //do nothing
        else
            ++hist[c];
    }

    for (i = 32; i < 128; ++i) { // only start with space char
        putchar(i);
        printf(": ");
        j = 1;
        while (j <= hist[i]) {
            printf("|");
            ++j;
        }
        printf("\n");
    }
}
