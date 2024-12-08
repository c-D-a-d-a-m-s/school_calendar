/*date.h*/

#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//data structures

struct date {
    int year;
    int month;
    int day;
};

struct date_range{
    struct date start;
    struct date end;
};

enum months {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
    AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

enum weekdays {SUNDAY, MONDAY, TUESDAY, WEDNESDAY,THURSDAY, FRIDAY, SATURDAY};

//function prototypes
bool check_for_leap_year(int year);
void get_first_of_month(struct date date, struct date*);
void get_last_of_month(struct date date, struct date*);
int count_days(struct date start, struct date end);
bool check_valid_date(struct date date);

#endif