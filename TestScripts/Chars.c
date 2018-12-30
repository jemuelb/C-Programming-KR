#include <stdio.h>

main() {
    char c[10];
    char b[10];

    c[0] = 'a';
    c[1] = 'b';
    c[2] = 'c';
    c[3] = '\n';
    c[4] = '\0';

    b[0] = c[0] + 10;
    b[1] = c[1] + 10;
    b[2] = c[2] + 10;
    b[3] = '\n';
    b[4] = '\0';

    printf("String c: %s", c);
    printf("String b: %s", b);

    return 0;
}
