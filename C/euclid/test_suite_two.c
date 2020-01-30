#include "seatest.h"
// der: "test suite" = group of individual tests in single file e.g. this file.

int
VII_1_relatively_prime (
  unsigned int a,
  unsigned int b
  );

int
VII_2_gcm (
  unsigned int a,
  unsigned int b
  );

void test_VII_1()
{
  /**
  Here are the correct values for the test cases.
  Obtained Python's built in functions.

  >>> int(math.gcd(12,4) == 1)
  0
  >>> int(math.gcd(13,4) == 1)
  1
  >>> int(math.gcd(54,85) == 1)
  1
  >>> int(math.gcd(31,85) == 1)
  1

  TODO: Other test cases.

  **/
  unsigned int a, b;
  int result;

  a = 12;
  b = 4;
  result = 0;
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, VII_1_relatively_prime(a, b), result);
  assert_true( VII_1_relatively_prime (a, b) == result);
  a = 13;
  b = 4;
  result = 1;
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, VII_1_relatively_prime(a, b), result);
  assert_true( VII_1_relatively_prime (a, b) == result);
  a = 54;
  b = 85;
  result = 1;
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, VII_1_relatively_prime(a, b), result);
  assert_true( VII_1_relatively_prime (a, b) == result);
  a = 31;
  b = 85;
  result = 1;
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, VII_1_relatively_prime(a, b), result);
  assert_true( VII_1_relatively_prime (a, b) == result);

  // assert_true( VII_1_relatively_prime (7, 7) == 0); // See comment below line.
  /**
  der:

  What does seatest do if an assert occurs inside VII_1_relatively_prime ()?

  ANS: Seatest doesn't continue. Assert forces immediate termination, same as
  without seatest.

  " Output is:
  a = 31, b = 85. rp = 1. expect rp = 1.
  Assertion failed: (0), function VII_1_relatively_prime, file euclid.c, line 140.
  Abort trap: 6
  " No test summary is printed.
  **/
}

void test_VII_2()
{
  /**
  Here are the correct values for the test cases.
  Obtained Python's built in functions.

  >>> math.gcd(884,3009)
  17
  >>> math.gcd(32,4)
  4
  >>> math.gcd(32,5)
  1

  TODO: Other test cases.

  **/
  unsigned int a, b;
  int result;

  a = 884;
  b = 3009;
  result = 17;
  printf ("a = %u, b = %u. gcm = %d. expect gcm = %d.\n", a, b, VII_2_gcm(a, b), result);
  assert_true( VII_2_gcm (a, b) == result);

  a = 32;
  b = 4;
  result = 4;
  printf ("a = %u, b = %u. gcm = %d. expect gcm = %d.\n", a, b, VII_2_gcm(a, b), result);
  assert_true( VII_2_gcm (a, b) == result);

  a = 32;
  b = 5;
  result = 1;
  printf ("a = %u, b = %u. gcm = %d. expect gcm = %d.\n", a, b, VII_2_gcm(a, b), result);
  assert_true( VII_2_gcm (a, b) == result);
}

/**
void test_asserting()
{
  assert_true( 1 == 1);
  assert_false(1 == 2);
  assert_int_equal(1, 1);
}

void test_assert_fails()
{
  assert_true( 1 == 2);
  assert_true( 3 == 5); // for checking END_TEST_IF_ASSERT_FAIL option (will be skipped)
}
**/

void test_fixture_two( void )
{

  test_fixture_start();
  run_test(test_VII_1);
  run_test(test_VII_2);
  // run_test(test_asserting);
  // run_test(test_assert_fails);
  test_fixture_end();
  /**

  der: At the end of a test suite "4 run  3 failed":
  means
  4 = number of calls to run_test() that were executed.
  3 = number of asserts that failed e.g. assert_true(0) is 1 failure.

  When compiled without "-D ABORT_TEST_IF_ASSERT_FAIL", all calls to run_test()
  execute to completion.
  Hence if the test is simply:
  assert_true (0);
  assert_true (0);
  This will result is "2 failed"

  When compiled with "-D ABORT_TEST_IF_ASSERT_FAIL"
  a call to run_test(test_VII_1) will stop further execution of test_VII_1()
  immediately after an assert fails. Hence if the test is simply:
  assert_true (0);
  assert_true (0);
  This will result is "1 failed".

  **/
}