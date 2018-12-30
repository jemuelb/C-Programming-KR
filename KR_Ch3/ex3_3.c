#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char l[], int lim);
void expand(char s1[], char s2[]);

main() {
    int len;
    char line[MAXLINE];
    char newline[MAXLINE];

    while (len = getline(line, MAXLINE) > 0) {
        printf("Echo: %s", line);
        expand(line, newline);
        printf("Converted: %s", newline);
    }

    return 0;
}

int getline(char l[], int lim) {
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n' && i<lim-1; ++i)
        l[i] = c;
    if (c == '\n')
        l[i++] = c;
    l[i] = '\0';

    return i;
}

void expand(char s1[], char s2[]) {
    int i, j, x;
    int char_diff;
    int c;

    for (i = x = 0; i < strlen(s1)-1; ++i) {
        if (s1[i] == '-' && i != 0 && i != strlen(s1)-2) {
            char_diff = s1[i+1] - s1[i-1];
            for (j = 1; j < char_diff; ++j) {
                c = s1[i-1] + j;
                s2[x++] = c;
            }
        }
        else
            s2[x++] = s1[i];
    }
    s2[x++] = '\n';
    s2[x++] = '\0';
}
