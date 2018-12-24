#include <stdio.h>
#define MAXLINE 1000

main() {
    char line1[MAXLINE];
    char line2[MAXLINE];
    int i;

    line1[0] = 'a';
    line1[1] = '\t';
    line1[2] = 'c';
    line1[3] = '\t';
    line1[4] = 'e';
    line1[5] = '\n';
    line1[6] = '\0';

    line2[0] = 'A';
    line2[1] = 'B';
    line2[2] = 'C';
    line2[3] = 'D';
    line2[4] = 'E';
    line2[5] = '\n';
    line2[6] = '\0';

    for (i=0; line1[i]!='\0')

    printf("%s", line1);
    printf("%s", line2);

    return 0;
}
