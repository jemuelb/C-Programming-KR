#include <stdio.h>

#define IN 1
#define OUT 0

main() {
    int c, in_space;

    in_space = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (in_space == OUT) { //detects the first space char
                putchar('\n');
                in_space = IN;
            }
            else
                ; //do not print if in_space == IN
        }
        else {
            putchar(c);
            in_space = OUT;
        }
    }
}
