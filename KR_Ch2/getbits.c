#include <stdio.h>

main() {
    int a;
    a = getbits()
    printf("%d", )
    return 0;
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}
