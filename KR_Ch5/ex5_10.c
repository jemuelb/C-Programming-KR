#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 500

/* function expr */
int main(int argc, char *argv[]) {

    char buffer[BUFSIZE];
    char *bufp = buffer;

    int type = 0;
    int temp;
    int res = 0;

    while (*++argv) {
        if (isdigit(*argv[0])) {
            *bufp++ = *argv[0];
            type = 0;
        } else
            type = *argv[0];

        if (type) {
            switch (type) {
            case '+':
                res += *bufp-- + *bufp--;
                break;
            // case '*':
            //     res *= *stack--;
            }
        }

    }

    printf("result: %d", res);

    return 0;
}
