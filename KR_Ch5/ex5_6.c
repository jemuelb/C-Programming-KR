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

int getline(char *s, int lim) {
    int c;
    char *t = s;

    while (--lim>0 && (c=getchar())!=EOF && c!='\n')
        *s++ = c;
    if (c=='\n')
        *s++ = c;

    *s = '\0';
    return s - t;
}

int atoi(char *s) {
    int n;

    n = 0;
    while (*s >= '0' && *s <= '9')
        n = 10 * n + (*s++ - '0');
    return n;
}
