#include <stdio.h>

#define MAXLEN 100

void reverse(char s[]);

main() {
    char c[MAXLEN];

    c[0] = 'h';
    c[1] = 'e';
    c[2] = 'l';
    c[3] = 'l';
    c[4] = 'o';
    c[5] = '\0';
    printf("Echo: %s\n", c);
    reverse(c);
    printf("Reversed string: %s\n", c);

    return 0;
}

void reverse(char s[]) {
    int c;
    static int i = 0;
    static int j = 0;

    if (s[i] != '\0') {
        c = s[i++];
        reverse(s);
        s[j++] = c;
    }
}
