#include <stdio.h>
#define MAXLEN 1000

void squeeze(char s1[], char s2[]);

main() {
    char mystr[MAXLEN];
    char delstr[MAXLEN];
    int c, i;

    i = 0;
    while ((c = getchar()) != '\n')
        mystr[i++] = c;
    mystr[i] = '\n';
    mystr[++i] = '\0';

    i = 0;
    while ((c = getchar()) != '\n')
        delstr[i++] = c;
    delstr[i] = '\n';
    delstr[++i] = '\0';

    squeeze(mystr, delstr);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    enum match {NO, YES};
    enum match status = NO;
    int i; // index of s1 string
    int j; // index for writing out new string
    int x; // index of s2 string

    for (i = j = 0; s1[i] != '\0'; i++) {
        /* cycle through all of s2, if there is a match, change status for
        exclusion in new version of string */
        for (x = 0; s2[x] != '\0'; x++) {
            if (s2[x] == s1[i])
                status = YES;
        }
        if (status == NO) // there is no match, include char
            s1[j++] = s1[i];
        status = NO;
    }
    s1[j] = '\0';

    printf("New string: %s", s1);
}
