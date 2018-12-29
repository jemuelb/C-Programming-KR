#include <stdio.h>

main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar((c >= 'A' && c <= 'Z') ? c+32 : c);
    }
    return 0;
}
