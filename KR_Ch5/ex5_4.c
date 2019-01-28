#include <stdio.h>

int strend(char s[], char t[]);

main() {
    char x[100], y[100];
    int res;

    x[0] = 'w';
    x[1] = 'o';
    x[2] = 'r';
    x[3] = 'l';
    x[4] = 'd';
    x[5] = '\0';

    y[0] = 'r';
    y[1] = 'x';
    y[2] = 'd';
    y[3] = '\0';

    printf("x echo: %s\n", x);
    printf("y echo: %s\n", y);
    res = strend(x, y);
    printf("Result is: %d", res);

    return 0;
}

int strend(char *s, char *t) {
    int n;

    while (*s) {
        if (*s == *t) {
            n = 0;
            while (*s++ == *t++ && *s && *t)
                n++;
            if (!*s && !*t)
                return 1;
            else {
                t -= n;
                s -= n;
            }
        }
        s++;
    }
    return 0;
}
