#include <stdio.h>
#include <string.h>

main() {
    enum hexx {A = 10, B, C, D, E, F};
    enum hexx c;
    char i[10];

    i[0] = '1';
    i[1] = 'B';
    i[2] = '9';

    printf("%d", i[0]);

    return 0;
}
