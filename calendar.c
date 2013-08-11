#include <stdio.h>
#include "calendar.h"

/*
 * うるう年かどうか判定する
 *
 * @return 0:false, 1:true
 */
int is_leap_year(int year) {
  if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
    return 1;
  }
  return 0;
}

/*
 * 指定月の最終日を取得
 */
int last_day_of_month(int year, int month) {
  static int days[] = {
    31, 28, 31, 30, 31, 30, 
    31, 31, 30, 31, 30, 31
  };
  int day = days[month - 1];

  return month != 2 ? day: day + is_leap_year(year);
}

/* 
 * 指定された年月日の曜日を取得   
 *
 * 基準日：1900/1/1 月曜日
 *
 * @return 0:Sunday, 1:Monday, ... , 6:Saturday
 */
DayOfWeek day_of_week(int year, int month, int day) {
  int i, sum_of_day = 0;

  for (i = 1900; i < year; i++) {
    sum_of_day += 365 + is_leap_year(i);
  }

  for (i = 1; i < month; i++) {
    sum_of_day += last_day_of_month(year, i);
  }

  sum_of_day += day;

  return (DayOfWeek)(sum_of_day % 7);
}

/*
 * 指定月の英語表記を取得
 *
 * @return 指定月の英語表記 ex.) January
 */
char* month_num_to_alphabet(int month) {
  static char *alphabet[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  };

  return alphabet[month - 1];
}