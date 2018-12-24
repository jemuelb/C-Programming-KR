#include <stdio.h>

main() {
    int aa;

    while((aa = getchar()) != EOF) {
        if(aa == '\t') {
            putchar('\\');
            putchar('\\');
            aa = getchar();
        }
        if(aa == '\b') {
            putchar('\\');
            putchar('\\');
            aa = getchar();
        }
        if(aa == '\\') {
            putchar('\\');
            putchar('\\');
            aa = getchar();
        }
        putchar(aa);
    }
}
