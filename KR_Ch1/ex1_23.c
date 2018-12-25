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
            else if ((c = getchar()) == '*') {
                status = IN;
                c = getchar(); //move to next char
            }
        }

        if (status == IN && c == '*') {
            if ((c = getchar()) == '/')
                status = OUT;
        }
        // else if (status == IN)
        //     ;

        if (status == OUT)
            putchar(c);
    }

    return 0;
}
