#include <stdio.h>

main() {
    int aa, blank_count;

    blank_count = 0;
    while((aa = getchar()) != EOF) {
        if(aa == ' ') {
            putchar(aa); //prints first blank char
            while( (aa = getchar()) == ' ')
                ; //do nothing while reading next blanks
        }
        putchar(aa); //if not blank, then just print char
    }
}
