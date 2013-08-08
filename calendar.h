#ifndef CALENDAR_H_
#define CALENDAR_H_

typedef enum _DayOfWeek {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
} DayOfWeek;

int is_leap_year(int year);
int last_day_of_month(int year, int month);
DayOfWeek day_of_week(int year, int month, int day);
char* month_num_to_alphabet(int month);

#endif