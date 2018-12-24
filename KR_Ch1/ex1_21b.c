#include <stdio.h>
#define TABLEN 8 //powershell tab length
#define MAXLINE 1000

int getline(char line[], int maxline);

main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s", line);
    }

    return 0;
}

/* Ingest line and replace blanks with tabs*/
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

void convertline(char s[]) {

}
