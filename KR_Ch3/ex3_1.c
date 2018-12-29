#include <stdio.h>

int binsearch(int x, int v[], int n);

main() {
    int v[10];
    int n = 10;
    int i;

    for (i = 0; i < 10; ++i)
        v[i] = i + 20;

    printf("The result is: %d\n", binsearch(29, v, n));

    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;

}
