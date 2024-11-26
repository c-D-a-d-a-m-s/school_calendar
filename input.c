#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

//data structures

struct date {
    int year;
    int month;
    int day;
};

struct date first_of_month  = {0,0,0};
struct date last_of_month  = {0,0,0};

struct date_range{
    struct date start;
    struct date end;
};

struct date_range picked_dates = {{0,0,0}, {0,0,0}};
struct date_range calendar_range = {{0,0,0}, {0,0,0}};

int school_days[];

//function prototypes
void get_date(char prompt[], struct date *date);
void get_int_array(char prompt[], int *int_arr);


int main() {


    return 0;
}

void get_date(char prompt[], struct date *date) {
    printf("%s ", prompt);
    scanf("%d/%d/%d", date->month, date->day, date->year);
}