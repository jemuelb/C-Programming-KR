#include <stdio.h>

int rlen(int k);

main() {
    int i;
    i = rlen(2);

    char s[i]; //you define string length after running a func
    s[0] = 'h';
    s[1] = 'e';
    s[2] = 'y';
    s[3] = '!';
    printf("%s", s);
}

int rlen(int k) {
    return k * 2;
}
