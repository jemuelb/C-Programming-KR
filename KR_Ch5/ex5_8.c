#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main() {

    int m, d;

    printf("results for day_of_year function\n");
    printf("1st: %d\n", day_of_year(2019, 2, 29));
    printf("2nd: %d\n", day_of_year(2019, 1, 15));
    printf("3rd: %d\n", day_of_year(2019, 12, 25));
    putchar('\n');

    printf("results for month_day function\n");
    month_day(2019, 349, &m, &d);
    printf("month: %d, day: %d\n", m, d);
    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 20, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 20, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if (year < 0 || yearday < 0 || yearday > 366) {
        *pmonth = -1;
        *pday = -1;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
