#include <stdio.h>

main() {
    int c, i, lim;
    char s[1000];

    lim = 1000;
    // for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //     s[i] = c;

    i = 0;
    while ((c=getchar()) != '\n') {
        if (i < lim-1)
            s[i] = c;

        ++i;
    }

    s[i] = '\n';
    s[++i] = '\0';

    printf("%s", s);

    return 0;
}
