/* Re-write the routines day_of_year and month_day to use
 * pointers instead of 2-d arrays
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int year_day, int *p_month, int *p_day);

char *day_tab[2];
char regular_year[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char leap_year[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
day_tab[0] = regular_year;
day_tab[1] = leap_year;

int main() {

    /* test day_of_year int*/
    int year_day;
    if ((year_day = day_of_year(1994, 5, 9)) > 0) {
        printf("May 9th, 1994 was day #%d of that year\n", year_day);
    }

    /* test month_day */
    int month, day;
    if (month_day(1994, year_day, &month, &day) > 0) {
        printf("Day #%d of 1994 was %d/%d\n", year_day, month, day);
    }
    
    return 0;
}

int day_of_year(int year, int month, int day) {
    int i, leap;

    if (day < 0) {
        return -1;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (day > day_tab[leap][month]) {
        return -1;
    }

    for (i = 1; i < month; ++i) {
        day += day_tab[leap][i];
    }

    return day;
}

int month_day(int year, int year_day, int *p_month, int *p_day) {
    int i, leap;

    if (year_day < 0) {
        return -1;
    }
        
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (year_day > (365 + leap)) {
        return -1;
    }

    for (i = 1; year_day > day_tab[leap][i]; ++i) {
        year_day -= day_tab[leap][i];
    }

    *p_month = i;
    *p_day = year_day;

    return 1;
}
