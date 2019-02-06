#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main() {

    int m, d;

    printf("results for day_of_year function\n");
    printf("1st: %d\n", day_of_year(2020, 2, 29));
    printf("2nd: %d\n", day_of_year(2019, 1, 15));
    printf("3rd: %d\n", day_of_year(2020, 12, 25));
    putchar('\n');

    printf("results for month_day function\n");
    month_day(2019, 60, &m, &d);
    printf("month: %d, day: %d\n", m, d);
    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 20, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 20, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    while (--month)
        day += *++p;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p, *s;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = s = daytab[leap];
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - s;
    *pday = yearday;
}
