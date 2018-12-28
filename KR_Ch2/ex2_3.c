#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAXLEN 1000

int getline(char s[], int lim);
int htoi(char s[]);
int findvalue(char c);

main() {
    int len;
    int results;
    char line[MAXLEN];

    while ((len = getline(line, MAXLEN)) > 0) {
        results = htoi(line);
        printf("Converted to hexadecimal: %d\n", results);
    }
    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n' && i<lim-1; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* Converts the given string into the int value */
int htoi(char s[]) {
    int i, j;
    int len;
    int res;
    int mult;
    int lim; //either 0 or 2

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        lim = 2;
    else
        lim = 0;

    len = strlen(s) - 1; //since string inclues new line char
    j = 0;
    res = 0;
    for (i = len-1; i >= lim; --i) {
        mult = findvalue(s[i]);
        res += pow(16, j) * mult;
        ++j;
    }

    return res;
}

/* Finds the eqivalent value given the char */
int findvalue(char c) {
    int res;

    if (isdigit(c))
        res = c - 48;
    else if (isupper(c))
        res = c - 55;
    else if (islower(c))
        res = c - 87;

    return res;
}
