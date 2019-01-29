#include <stdio.h>

void strncpy(char s[], char t[], int n);

main() {
    char x[100], y[100];

    x[0] = 'w';
    x[1] = 'o';
    x[2] = 'r';
    x[3] = 'l';
    x[4] = 'd';
    x[5] = '\0';

    y[0] = '\0';

    printf("x echo: %s\n", x);
    printf("y echo: %s\n", y);
    strncpy(y, x, 10);
    printf("Result of copy is: %s", y);

    return 0;
}

void strncpy(char *s, char *t, int n) {
    int i = 0;
    while (i < n) {
        if (*t)
            *s++ = *t++;
        else
            *s++ = '\0';
        i++;
    }
    *s = '\0';
}
