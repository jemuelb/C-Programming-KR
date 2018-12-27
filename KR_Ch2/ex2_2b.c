#include <stdio.h>

main() {
    int c, i;
    int lim = 1000;
    char s[1000];
    enum loop {NO, YES};
    enum loop status = YES;

    i = 0;
    while (status == YES) {
        if (i >= lim-1)
            status = NO;
        else if ((c = getchar()) == '\n')
            status = NO;
        else if (c == EOF)
            status = NO;
        else {
            s[i] = c;
            ++i;
        }
    }
    printf("%s", s);
    return 0;
}
