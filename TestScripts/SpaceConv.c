#include <stdio.h>
#define MAXLINE 1000

int getword(char w[], int lim);

main() {
    int len;
    char word[MAXLINE];

    while ((len = getword(word, MAXLINE)) > 0) {
        printf("%s", word);
    }

    return 0;
}

int getword(char w[], int lim) {
    int c, i;

    for (i=0; (c = getchar()) != EOF && i < lim - 1 &&
               c != '\n' && c != ' ' && c != '\t'; ++i)
        w[i] = c;
    if (c == '\n' || c == ' ' || c == '\t') {
        w[i] = '\n';
        ++i;
    }
    w[i] = '\0';
    return i;
}
