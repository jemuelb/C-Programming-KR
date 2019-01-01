#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

main() {
    int i, b;
    char s[MAXLEN];

    i = 8008;
    b = 8;
    itob(i, s, b);
    printf("%s", s);

    return 0;
}

void itob(int n, char s[], int b) {
    int i;
    int remain;

    do {
        remain = n % b;
        if (remain >= 10)
            s[i++] = (remain - 10) + 'A';
        else
            s[i++] = remain + '0';
    } while ((n /= b) > 0);
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
