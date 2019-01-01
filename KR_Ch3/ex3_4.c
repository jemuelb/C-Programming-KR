/* not complete */

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
void itoa(int n, char s[]);
void reverse(char s[]);

main() {
    int c;
    char s[MAXLEN];

    c = -99101;
    itoa(c, s);
    printf("%s", s);

    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0; j = strlen(s)-1, i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
