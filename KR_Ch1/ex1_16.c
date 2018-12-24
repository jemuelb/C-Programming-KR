#include <stdio.h>
#define MAXLINE 5

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) // notice that line is pass as ref
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%s", longest);
        printf("Line length of: %d", max);
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim) {
    int c, i, count;

    i = 0;
    count = 0;
    while ((c=getchar())!=EOF && c!='\n'){
        if (i < lim-1){
            s[i] = c;
            ++i;
        }
        ++count;
    }
    s[i] = '\n'; // i limited to (MAXLINE-1)
    s[++i] = '\0';
    return count;
}

/* copy: copy 'from' into 'to'; assume to is big enough*/
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
