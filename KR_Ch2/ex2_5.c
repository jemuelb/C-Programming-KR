#include <stdio.h>
#define MAXLEN 1000

void any(char s1[], char s2[]);

main() {
    char mystr[MAXLEN];
    char matchstr[MAXLEN];
    int c, i;

    i = 0;
    while ((c = getchar()) != '\n')
        mystr[i++] = c;
    mystr[i] = '\n';
    mystr[++i] = '\0';

    i = 0;
    while ((c = getchar()) != '\n')
        matchstr[i++] = c;
    matchstr[i] = '\n';
    matchstr[++i] = '\0';

    any(mystr, matchstr);

    return 0;
}

void any(char s1[], char s2[]) {
    enum match {NO, YES};
    enum match status = NO;
    int i = 0; // index of s1 string
    int x; // index of s2 string
    int loc;

    while (!status) {
        for (x = 0; s2[x] != '\0'; ++x) {
            if (s1[i] == s2[x] && s1[i] != '\n') {
                status = YES;
                loc = i;
            }
        }
        if (s1[i] == '\0') {
            status = YES;
            loc = -1;
        }
        ++i;
    }

    printf("First location is: %d", loc);
}
