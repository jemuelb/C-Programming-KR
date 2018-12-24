/* Version 2: some pseudo code:
1. Ingest entire line of text into a string
2. Break long line into strings of MAXLEN
3. Mark when last blank occured to know where to resume from
  */

#include <stdio.h>
#define MAXLEN 20 //max chars per line
#define MAXLINE 1000
#define IN 1
#define OUT 0

int getline(char line[], int maxline);
void breakline(char s[], int len);

main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) // notice that line is passed as ref
        breakline(line, len);
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

void breakline(char s[], int len) {
    int c, i, j, status;
    int l_count, marker;
    int word_len;
    int st_index, end_index;
    char pstring[MAXLEN + 2];

    l_count = 0;
    for (i = 0; i < len; ++i) {
        if (s[i] != ' ' || s[i] != '\n' || s[i] != '\t') {
            status = IN;
            st_index = i;
        }

        if (status == IN && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')) {
            status = OUT;
            end_index = i;
            word_len = end_index - st_index;

            if (l_count + word_len < MAXLEN) {
                for (j = st_index; j < end_index; ++j) {
                    pstring[l_count] = s[j];
                    ++l_count;
                }
            }
        }
    }
    ++l_count;
    pstring[l_count] = '\0';
    printf("%s", pstring);
}
