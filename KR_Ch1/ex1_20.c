#include <stdio.h>
#define TABLEN 8 //powershell tab length

main() {
    int c;
    int count;

    count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (count; count < TABLEN; ++count)
                putchar(' ');
        }
        else if (c != '\n') {
            putchar(c);
            ++count;
        }
        else { // when '\n' appears, need to reset tab count
            putchar(c);
            count = 0;
        }

        if (count == TABLEN)
            count = 0;
    }

    return 0;
}
