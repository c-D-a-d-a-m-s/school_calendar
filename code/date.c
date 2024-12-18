#include "date.h"

bool check_for_leap_year(int year) {
    /*Returns true if int year is a leap year*/
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

void get_first_of_month(struct date date, struct date *first_of_month) {
    /*Returns the first date of the month*/
    first_of_month->year = date.year;
    first_of_month->month = date.month;
    first_of_month->day = 1;
}

void get_last_of_month(struct date date, struct date *last_of_month) {
    /*Returns the last date of the month*/
    last_of_month->year = date.year;
    last_of_month->month = date.month;

    int last_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    last_of_month->day = last_day[date.month];
    if (date.month == 2 && check_for_leap_year(date.year)) {
        ++last_of_month->day;
    }
}

int count_days(struct date start, struct date end) {
    /*Count number of days in range, including start and end dates*/
    int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int start_index = 0;
    int end_index = 0;
    int leap_days = 0;

    for (size_t i = 0; i < start.month; start_index += days_per_month[i], i++);
    start_index += start.day;
    if (check_for_leap_year(start.year) && start.month > FEBRUARY) {
        start_index++;
    }

    for (size_t i = 0; i < end.month; end_index += days_per_month[i], i++);
    end_index += end.day;
    if (check_for_leap_year(end.year) && end.month > FEBRUARY) {
        end_index++;
    }

    if (start.year != end.year) {
        for (size_t year = start.year; year < end.year; year++) {
            if (check_for_leap_year(year)) {
                leap_days++;
            }
        }
    }

    return 365 * (end.year - start.year) + (end_index - start_index + 1) + leap_days;
}

bool check_valid_date(struct date date) {
    /*Returns true if the struct members (date.day, date.month, date.year)
    correspond to a valid date between 1/1/2000-12/31/9999*/
    if (date.year < 2000 || date.year > 9999) {
        return false;
    }

    if (date.month < 1 || date.month > 12) {
        return false;
    }

    const int total_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.day < 1 || date.day > total_days[date.month]) {
        return false;
    }

    if (date.day == 29 && date.month == FEBRUARY && !(check_for_leap_year(date.year))) {
        return false;
    }

    return true;

}