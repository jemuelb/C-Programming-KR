#include <stdio.h>

main() {
    int c;
    int p_status, b_status;

    p_status = 0;
    b_status = 0;
    while ((c = getchar()) != EOF) {
        if (c == '(')
            ++p_status;
        if (c == ')')
            --p_status;

        if (c == '{')
            ++b_status;
        if (c == '}')
            --b_status;
    }

    printf("%d", b_status);

    if (p_status > 0 || b_status > 0)
        printf("This script has an error.\n");
    else
        printf("No bracket imbalance found.\n");

    return 0;
}
