#include <stdio.h>

void strcat(char s[], char t[]);

main() {
    char x[100], y[100];

    x[0] = 'a';
    x[1] = 'w';
    x[2] = 'f';
    x[3] = 'q';
    x[4] = '1';
    x[5] = '\0';

    y[0] = '\0';

    printf("X var: %s\n", x);
    strcat(y, x);
    printf("Y var: %s\n", y);

    return 0;
}

void strcat(char *s, char *t) {
/* Pointer version */

    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}
