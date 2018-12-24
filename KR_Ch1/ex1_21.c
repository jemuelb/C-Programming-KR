#include <stdio.h>
#define TABLEN 8 //powershell tab length

main() {
    int c;
    int blank_cnt, total_cnt;

    blank_cnt = 0;
    total_cnt = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blank_cnt;
            ++total_cnt;
            while ((c = getchar()) == ' ') {
                ++blank_cnt;
                ++total_cnt;
            }

            /* Print as many tabs as will fit */
            while (blank_cnt >= TABLEN) {
                putchar('\t');
                blank_cnt = blank_cnt - TABLEN;
            }
            /* Print remaining blanks */
            while (blank_cnt > 0){
                putchar(' ');
                --blank_cnt;
            }

        }

        else { //c is non blank char
            putchar(c);
        }
    }
    return 0;
}
