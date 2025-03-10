/********************************/
/***          date.h          ***/
/********************************/

#ifndef DATE_H
#define DATE_H

/*** includes ***/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>

/*** data types */
typedef struct {
    int year;
    int month;
    int day;
} Date;

/*** function declarations ***/
bool check_for_leap_year(int year);
void get_first_of_month(Date date, Date*);
void get_last_of_month(Date date, Date*);
int count_days(Date start, Date end);
bool check_valid_date(Date date);
void str_to_date(const char* const str, Date* date);
bool check_str_is_date(char* str);

#endif