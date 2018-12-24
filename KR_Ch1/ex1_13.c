#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 10

main() {
    int c, i, j, status, wlen, plus;
    int hist[MAXLEN + 1];

    for (i = 0; i < MAXLEN + 1; ++i)
        hist[i] = 0;

    wlen = plus = 0;
    status = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            status = IN;
            ++wlen;
        }
        else
            status = OUT;

        if (status == OUT) {
            if (wlen == 0)
                ; // multiple space condition
            else if (wlen > MAXLEN){
                ++hist[MAXLEN];
                wlen = 0;
            }
            else {
                ++hist[wlen - 1];
                wlen = 0;
            }
        }
    }
    /* Print out the histogram */
    for (i = 0; i < MAXLEN + 1; ++i) {
        if (i == MAXLEN)
            printf("%3d+:", i + 1);
        else
            printf("%4d:", i + 1);

        j = 1;
        while (j <= hist[i]) {
            printf("|");
            ++j;
        }

        printf("\n");
    }
}
