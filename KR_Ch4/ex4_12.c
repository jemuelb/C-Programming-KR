#include <stdio.h>

#define MAXLEN 100

void itoa_re(int n, char s[]);

main() {
    int i;
    char c[MAXLEN];

    i = -92139;

    itoa_re(i, c);
    printf("This is the new string: %s", c);

    return 0;
}

void itoa_re(int n, char s[]) {
    static int i = 0;

    if (n < 0 && i == 0) {
        n = -n;
        s[i++] = '-';
    }

    if (n / 10)
        itoa_re(n / 10, s);
    s[i++] = n % 10 + '0';
}
