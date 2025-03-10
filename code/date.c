/********************************/
/***          date.c          ***/
/********************************/

/*** includes ***/
#include "date.h"

/*** function definitions ***/
bool check_for_leap_year(int year) {
    /*Returns true if int year is a leap year*/
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

void get_first_of_month(Date date, Date *first_of_month) {
    /*Returns the first date of the month*/
    first_of_month->year = date.year;
    first_of_month->month = date.month;
    first_of_month->day = 1;
}

void get_last_of_month(Date date, Date *last_of_month) {
    /*Returns the last date of the month*/
    last_of_month->year = date.year;
    last_of_month->month = date.month;

    int last_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    last_of_month->day = last_day[date.month];
    if (date.month == 2 && check_for_leap_year(date.year)) {
        ++last_of_month->day;
    }
}

int count_days(Date start, Date end) {
    /*Count number of days in range, including start and end dates*/
    int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int start_index = 0;
    int end_index = 0;
    int leap_days = 0;
    const int FEBRUARY = 2;

    for (int i = 0; i < start.month; start_index += days_per_month[i], i++);
    start_index += start.day;
    if (check_for_leap_year(start.year) && start.month > FEBRUARY) {
        start_index++;
    }

    for (int i = 0; i < end.month; end_index += days_per_month[i], i++);
    end_index += end.day;
    if (check_for_leap_year(end.year) && end.month > FEBRUARY) {
        end_index++;
    }

    if (start.year != end.year) {
        for (int year = start.year; year < end.year; year++) {
            if (check_for_leap_year(year)) {
                leap_days++;
            }
        }
    }

    return 365 * (end.year - start.year) + (end_index - start_index + 1) + leap_days;
}

bool check_valid_date(Date date) {
    /*Returns true if the struct members (date.day, date.month, date.year)
    correspond to a valid date between 1/1/2000-12/31/9999*/
    const int FEBRUARY = 2;

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

void str_to_date(const char* const str, Date* date) {
    /*Takes a string argument of the format "month/day/year", where month, day, and year are integers,
    and passes the integers into the corresponding date members pointed to by the Date* argument.
    WARNING: This function does not guarantee the values stored in *date correspond to a valid date. If a valid date
             is required, use check_str_is_date() to check the string prior to calling this function.*/
    char tempStr[strlen(str) + 1];
    enum dateMember {YEAR, DAY, MONTH};
    int dateMemberArr[3];
    int dateMemberIdx = 0;

    strncpy(tempStr, str, strlen(str) + 1);
    for (int i = strlen(tempStr) - 1; i >= 0; i--) {
        if (*(tempStr + i) == '/') {
            *(tempStr + i) = '\0';
            dateMemberArr[dateMemberIdx] = atoi(tempStr + i + 1);
            dateMemberIdx++;
        }
    }
    dateMemberArr[dateMemberIdx] = atoi(tempStr);

    *date = (Date){.year = dateMemberArr[YEAR], .day = dateMemberArr[DAY], .month = dateMemberArr[MONTH]};
}

bool check_str_is_date(char* str) {
    /*Returns true if a string represents a valid date in the format "month/day/year",
    where month, day, and year are integers. Otherwise, returns false.*/
    regex_t dateRegex;
    Date date;
    if(regcomp(&dateRegex, "^[0,1,2,3,4,5,6,7,8,9]*/[0,1,2,3,4,5,6,7,8,9]*/[0,1,2,3,4,5,6,7,8,9]*$", REG_NOSUB) != 0) die("check_str_is_date", "regcomp() failed to compile regex.");
    if(regexec(&dateRegex, str, 0, NULL, 0) != 0) {
        return false;
    }
    else {
        str_to_date(str, &date);
        if (!check_valid_date(date)) {
            return false;
        }
    }
    return true;
}