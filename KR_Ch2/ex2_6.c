#include <stdio.h>

main() {
    int a;

    return 0;
}

unsinged setbits(unsigned x, int p, int n, unsinged y) {
    x = (x >> (p+1-n)) & ~(~0 << n);
    y =  y & ~(~0 << n);

    return (y | x);
}
