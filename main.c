#include <stdio.h>
#include "calendar.h"

void render_header(int year, int month);
void render_body(int year, int month);
void render_day(int week, int day);

int main() {
  int year, month;

  do {
    printf("input year:");
    scanf("%d", &year);

    printf("input month:");
    scanf("%d", &month);
  } while (year < 1900 || (month < 1 || month > 12));

  render_header(year, month);
  render_body(year, month);

  return 0;
}

void render_header(int year, int month) {
  printf("\n%4d %s\n", year, month_num_to_alphabet(month));
  printf("-------------------------------\n");
  printf("| SUN MON TUE WED THU FRI SAT |\n");
  printf("-------------------------------\n");
}

void render_body(int year, int month) {
  int pos, day, first_day_pos, last_day, week;

  printf("|");
  first_day_pos = day_of_week(year, month, 1);
  for (pos = 0; pos < first_day_pos; pos++) {
    printf("    ");
  }

  last_day = last_day_of_month(year, month);
  for (day = 1; day <= last_day; pos++, day++) {
    week = pos % 7;
    if (week == 0 && pos != 0) {
      printf(" |\n|");
    }
    render_day(week, day);
  }

  for ( ; pos < 35; pos++) {
    printf("    ");
  }
  printf(" |\n-------------------------------\n");
}

void render_day(int week, int day) {
  if (week == Sunday) {
    printf("\x1b[35m"); // color magenta
    printf(" %2d ", day);
    printf("\x1b[39m"); // default
  } else if (week == Saturday) {
    printf("\x1b[34m"); // color blue
    printf(" %2d ", day);
    printf("\x1b[39m"); // default
  } else {
    printf(" %2d ", day);
  }
}