#include <stdio.h>
#include "../calendar.h"
#include "minunit.h"

int mu_tests_run = 0;
int mu_tests_success = 0;

static void test_is_leap_year() {
  ASSERT_FALSE(is_leap_year(1900), "error, 1900 is not a leap year");
  ASSERT_TRUE(is_leap_year(1996), "error, 1996 is a leap year");
  ASSERT_TRUE(is_leap_year(2000), "error, 2000 is a leap year");
  ASSERT_FALSE(is_leap_year(2009), "error, 2009 is not a leap year");
}

static void test_days_in_month() {
  ASSERT_INT_EQ(31, last_day_of_month(2000, 1));
  ASSERT_INT_EQ(29, last_day_of_month(2000, 2));
  ASSERT_INT_EQ(31, last_day_of_month(2000, 3));
  ASSERT_INT_EQ(30, last_day_of_month(2000, 4));
  ASSERT_INT_EQ(31, last_day_of_month(2000, 5));
  ASSERT_INT_EQ(30, last_day_of_month(2000, 6));
  ASSERT_INT_EQ(31, last_day_of_month(2000, 7));
  ASSERT_INT_EQ(31, last_day_of_month(2000, 8));
  ASSERT_INT_EQ(30, last_day_of_month(2000, 9));
  ASSERT_INT_EQ(31, last_day_of_month(2000, 10));
  ASSERT_INT_EQ(30, last_day_of_month(2000, 11));
  ASSERT_INT_EQ(31, last_day_of_month(2000, 12));
  ASSERT_INT_EQ(28, last_day_of_month(1900, 2));
}

static void test_day_of_week() {
  ASSERT_INT_EQ(Monday, day_of_week(1900, 1, 1));
  ASSERT_INT_EQ(Sunday, day_of_week(1950, 1, 1));
  ASSERT_INT_EQ(Wednesday, day_of_week(1987, 1, 14));
  ASSERT_INT_EQ(Saturday, day_of_week(2013, 8, 10));
  ASSERT_INT_EQ(Thursday, day_of_week(2020, 12, 31));
}

int main() {
  test_is_leap_year();
  test_days_in_month();
  test_day_of_week();

  TEST_SUMMARY();
  return 0;
}