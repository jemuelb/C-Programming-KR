#include <stdio.h>
#define TABLEN 8
#define IN 1
#define OUT 0

main() {
    int c, i;
    int status, s_count, t_count, t_init;

    t_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            status = IN;
            s_count = 0;
        }
        else {
            status = OUT;
            ++t_count;
            putchar(c);
        }
        /* Deal with blank chars below */
        if (status == IN) {
            t_init = t_count;
            ++s_count;
            ++t_count;

            while ((c = getchar()) == ' ') {
                ++s_count;
                ++t_count;
            }

            if (t_count >= TABLEN) {
                putchar('\t');
                s_count -= TABLEN - t_init;
                t_count = 0;

                while (s_count >= TABLEN) {
                    putchar('\t');
                    s_count -= TABLEN;
                }
            }
            if (s_count > 0) {
                for (i=0; i<s_count; ++i) {
                    putchar(' ');
                    ++t_count;
                }
            }
            ++t_count;
            putchar(c);
        }

        if (t_count >= TABLEN || c == '\n' || c == '\t')
            t_count = 0;
    }

    return 0;
}
