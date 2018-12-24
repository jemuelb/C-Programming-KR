#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char to[], char from[], int length);

main() {
    int len;
    char line[MAXLINE];
    char rline[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(rline, line, len);
        printf("Reversed string: %s", rline);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim) {
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n' && i<lim-1; ++i)
        s[i] = c; // here s is being modified directly
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: reverse 'from' into 'to'; assume to is big enough*/
void reverse(char to[], char from[], int length) {
    int i;

    for (i = 0; i < length; ++i){
        to[i] = from[(length-2) - i]; // skip the new line and null char
    }
    /* place the newline and null char at end of the line*/
    to[length-1] = '\n';
    to[length] = '\0';

}
