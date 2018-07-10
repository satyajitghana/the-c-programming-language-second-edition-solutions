#include <stdio.h>
#define dprintf(d) printf(#d " : %d\n", d);

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {

    printf("year: 1999, month : 6, day : 17\n");
    int year = 1999, month = 6, day = 17;
    int dayofyear = day_of_year(year, month, day);
    dprintf(dayofyear);
    int _month, _day;
    month_day(year, dayofyear, &_month, &_day);
    dprintf(_month);
    dprintf(_day);
    
    printf("error : dayofyear: 370, year: 1999\n");
    dayofyear = 370;
    dprintf(dayofyear);
    month_day(year, dayofyear, &_month, &_day);
    dprintf(_month);
    dprintf(_day);
    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of the year from month & day */
/* @example: March 1 1998 is the 60th day, 1988 is a non-leap year */
int day_of_year(int year, int month, int day) {
    int i, leap;

    if (month < 1 || month > 12)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (day < 1 || day > daytab[leap][month])
        return -1;

    for (i = 1 ; i < month ; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = year%4 == 0 && year%100 != 0 || year %400 == 0;

    if ((leap && yearday > 366) || (!leap && yearday > 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
