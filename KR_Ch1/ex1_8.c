#include <stdio.h>

main() {
    int aa, cnt;

    cnt = 0;
    while ((aa = getchar()) != EOF) {
        if(aa == '\t')
            ++cnt;
    printf("%d\n", cnt);
    }
}
