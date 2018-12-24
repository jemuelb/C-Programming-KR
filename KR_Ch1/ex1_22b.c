/* Version 2: breaks the line before the max length. Finds the length of a word
before determining whether or not it is too long to put into the current print
string. If it is too long to fit, starts the new line. */

#include <stdio.h>
#define MAXLENGTH 80 //max chars per line
#define MAXLINE 1000
#define IN 1
#define OUT 0

int getline(char line[], int maxline);
void breakline(char s[], int len);

main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > MAXLENGTH)
            breakline(line, len);
        else
            // breakline(line, len);
            printf("%s", line);
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
    char pstring[MAXLENGTH + 2];

    l_count = 0;
    status = OUT;
    for (i = 0; i < len; ++i) {

        /* Beginning of word */
        if (status == OUT && (s[i] != ' ' || s[i] != '\n' || s[i] != '\t')) {
            // printf("TEST1\n");
            status = IN;
            st_index = i;
        }

        /* End of word */
        if (status == IN && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')) {
            // printf("TEST2\n");
            status = OUT;
            end_index = i;
            word_len = end_index - st_index;

            /* Decide whether or not word fits */
            if (l_count + word_len < MAXLENGTH) {
                for (j = st_index; j < end_index; ++j) {
                    pstring[l_count] = s[j];
                    ++l_count;
                }
            }
            else { // hits MAXLENGTH limit
                pstring[l_count] = '\n';
                ++l_count;
                pstring[l_count] = '\0';
                printf("%s", pstring);

                l_count = 0;
                for (j = st_index; j < end_index; ++j) {
                    pstring[l_count] = s[j];
                    ++l_count;
                }
            }
        }

        /* Dealing with blanks */
        if (status == OUT && s[i] == ' ') {
            // printf("TEST3\n");
            pstring[l_count] = s[i];
            ++l_count;
        }
    }

    /* Print the remainder of the string */
    // printf("%d\n", l_count);
    pstring[l_count] = '\n';
    ++l_count;
    pstring[l_count] = '\0';
    printf("%s", pstring);
}
