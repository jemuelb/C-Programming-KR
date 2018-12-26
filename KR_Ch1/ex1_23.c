#include <stdio.h>
#define IN 1
#define OUT 0

main () {
    int c;
    int status;

    status = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            /* Single line comment */
            if ((c = getchar()) == '/') {
                while ((c = getchar()) != '\n')
                    ; // do nothing until new line
                // putchar('\n');
            }

            /* May be multi-line comment */
            else if (c == '*') {
                status = IN;
                c = getchar(); //move to next char
            }
            else
                putchar('/');
        }

        if (status == IN && c == '*') {
            if ((c = getchar()) == '/')
                status = OUT;
                c = getchar();
        }

        if (status == OUT)
            putchar(c);
    }

    return 0;
}
