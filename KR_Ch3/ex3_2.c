#include <stdio.h>
#define MAXLINE 1000

int getline(char l[], int lim);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main() {
    int len;
    char line[MAXLINE];
    char newline[MAXLINE];

    while (len = getline(line, MAXLINE) > 0) {
        printf("Echo: %s", line);
        unescape(line, newline);
        printf("Converted: %s", newline);
    }

    return 0;
}

int getline(char l[], int lim) {
    int c, i;
    //i<lim-1 || (c=getchar()) != '\n'
    for (i=0; (c=getchar())!=EOF && c!='\n' && i<lim-1; ++i)
        l[i] = c;
    if (c == '\n')
        l[i++] = c;
    l[i] = '\0';

    return i;
}

void escape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
        ++i;
    }
    t[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i) {
        if (s[i] != '\\')
            t[j++] = s[i];
        else {
            switch (s[++i]) {
                case 'n':
                    t[j++] = '\n';
                    break;
                case 't':
                    t[j++] = '\t';
                    break;
                default:
                    t[j++] = '\\';
                    t[j++] = s[i];
            }
        }
    }
    t[j] = '\0';
}
