#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
void itoa(int n, char s[], int min);
void reverse(char s[]);

main() {
    int c, min;
    char s[MAXLEN];

    c = -90999;
    min = 10;
    itoa(c, s, min);
    printf("%s", s);

    return 0;
}

void itoa(int n, char s[], int min) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';

    while (i < min) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
