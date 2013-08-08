/*
 * This Program based on MinUnit.
 * @see http://www.jera.com/techinfo/jtns/jtn002.html
 */
#ifndef MU_TEST_
#define MU_TEST_

#include <stdio.h>

#define ASSERT_TRUE(test, message) do { mu_tests_run++;if (!(test)) {printf("%s:%d: %s\n", __FUNCTION__, __LINE__, message);} else {mu_tests_success++;} } while (0)
#define ASSERT_FALSE(test, message) do { mu_tests_run++;if ((test)) {printf("%s:%d: %s\n", __FUNCTION__, __LINE__, message);} else {mu_tests_success++;} } while (0)
#define ASSERT_INT_EQ(expected, actual) do { mu_tests_run++;if (expected != actual) {printf("%s:%d: expected %d but actual %d.\n", __FUNCTION__, __LINE__, expected, actual); } else {mu_tests_success++;} } while (0)
#define TEST_SUMMARY() do { if (mu_tests_run == mu_tests_success) { printf("ALL TESTS PASSED\n");} printf("Tests run: %d/%d\n", mu_tests_success, mu_tests_run); } while (0)

extern int mu_tests_run;
extern int mu_tests_success;

#endif