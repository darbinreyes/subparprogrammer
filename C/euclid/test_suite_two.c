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

int
VII_3_gcm (
  unsigned int a,
  unsigned int b,
  unsigned int c
  );

int
VII_4_part_or_parts (
  unsigned int b,
  unsigned int a
  );

int
VII_4_part_or_parts_v1 (
  unsigned int b,
  unsigned int a,
  int         *m,
  int         *n
  );

void test_VII_1()
{
  /**
  Here are the correct values for the test cases computed separately in python.


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
  Here are the correct values for the test cases computed separately in python.


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

void test_VII_3 ()
{
  /**

  Here are the correct values for the test cases computed separately in python.


  >>> math.gcd(math.gcd(32,8), 4)
  4
  >>> math.gcd(math.gcd(32,64), 4)
  4
  >>> math.gcd(math.gcd(32,64), 5)
  1
  >>> math.gcd(math.gcd(32,64), 6)
  2

  TODO: Other test cases.

  **/
  unsigned int a, b, c;
  int result;

  a = 32;
  b = 8;
  c = 4;
  result = 4;
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, VII_3_gcm(a, b, c), result);
  assert_true( VII_3_gcm (a, b, c) == result);

  a = 32;
  b = 64;
  c = 4;
  result = 4;
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, VII_3_gcm(a, b, c), result);
  assert_true( VII_3_gcm (a, b, c) == result);

  a = 32;
  b = 64;
  c = 5;
  result = 1;
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, VII_3_gcm(a, b, c), result);
  assert_true( VII_3_gcm (a, b, c) == result);

  a = 32;
  b = 64;
  c = 6;
  result = 2;
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, VII_3_gcm(a, b, c), result);
  assert_true( VII_3_gcm (a, b, c) == result);

}

void test_VII_4 ()
{
  unsigned int a, b;
  int result;

  /**

  Here are the correct values for the test cases computed separately in python.

  >>> int(7 % 3 > 0)
  1
  >>> int(7 % 6 > 0)
  1
  >>> int(6 % 2 > 0)
  0
  >>> int(12 % 3 > 0)
  0
  >>> int(6 % 4 > 0)
  1
  >>> int(12 % 8 > 0)
  1

  TODO: Other test cases.

  **/
  b = 3;
  a = 7;
  result = 1; // parts.
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, VII_4_part_or_parts (b, a), result);
  assert_true( VII_4_part_or_parts (b, a) == result);

  b = 6;
  a = 7;
  result = 1; // parts.
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, VII_4_part_or_parts (b, a), result);
  assert_true( VII_4_part_or_parts (b, a) == result);

  b = 2;
  a = 6;
  result = 0; // part.
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, VII_4_part_or_parts (b, a), result);
  assert_true( VII_4_part_or_parts (b, a) == result);

  b = 3;
  a = 12;
  result = 0; // part.
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, VII_4_part_or_parts (b, a), result);
  assert_true( VII_4_part_or_parts (b, a) == result);

  b = 4;
  a = 6;
  result = 1; // parts.
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, VII_4_part_or_parts (b, a), result);
  assert_true( VII_4_part_or_parts (b, a) == result);

  b = 8;
  a = 12;
  result = 1; // parts.
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, VII_4_part_or_parts (b, a), result);
  assert_true( VII_4_part_or_parts (b, a) == result);
}

void test_VII_4_v1 (void)
{
/**

  Here are the correct values for the test cases computed separately in python.

$ python3.8 VII_4_part_or_parts_v1.py
ret, m, n =  (1, 3, 7)
ret, m, n =  (1, 6, 7)
ret, m, n =  (0, 1, 3)
ret, m, n =  (0, 1, 4)
ret, m, n =  (1, 2, 3)
ret, m, n =  (1, 2, 3)

**/
  unsigned int a, b; // Input values.
  int m, n; // Computed output argument values.
  int ret; // Computed return value.
  int expected_m, expected_n; // Expected output argument values.
  int expected_ret; // Expected return value.

  b = 3;
  a = 7;
  m = -1;
  n = -1;
  ret = -1;
  expected_ret = 1; // parts.
  expected_m = 3;
  expected_n = 7;
  printf ("b = %u, a = %u. expect ret = %d. m = %d. n = %d.\n", b, a, expected_ret, expected_m, expected_n);
  ret = VII_4_part_or_parts_v1 (b, a, &m, &n);
  assert_int_equal(expected_ret, ret);
  assert_int_equal(expected_m, m);
  assert_int_equal(expected_n, n);

  b = 6;
  a = 7;
  m = -1;
  n = -1;
  ret = -1;
  expected_ret = 1; // parts.
  expected_m = 6;
  expected_n = 7;
  printf ("b = %u, a = %u. expect ret = %d. m = %d. n = %d.\n", b, a, expected_ret, expected_m, expected_n);
  ret = VII_4_part_or_parts_v1 (b, a, &m, &n);
  assert_int_equal(expected_ret, ret);
  assert_int_equal(expected_m, m);
  assert_int_equal(expected_n, n);

  b = 2;
  a = 6;
  m = -1;
  n = -1;
  ret = -1;
  expected_ret = 0; // part.
  expected_m = 1;
  expected_n = 3;
  printf ("b = %u, a = %u. expect ret = %d. m = %d. n = %d.\n", b, a, expected_ret, expected_m, expected_n);
  ret = VII_4_part_or_parts_v1 (b, a, &m, &n);
  assert_int_equal(expected_ret, ret);
  assert_int_equal(expected_m, m);
  assert_int_equal(expected_n, n);

  b = 3;
  a = 12;
  m = -1;
  n = -1;
  ret = -1;
  expected_ret = 0; // part.
  expected_m = 1;
  expected_n = 4;
  printf ("b = %u, a = %u. expect ret = %d. m = %d. n = %d.\n", b, a, expected_ret, expected_m, expected_n);
  ret = VII_4_part_or_parts_v1 (b, a, &m, &n);
  assert_int_equal(expected_ret, ret);
  assert_int_equal(expected_m, m);
  assert_int_equal(expected_n, n);

  b = 4;
  a = 6;
  m = -1;
  n = -1;
  ret = -1;
  expected_ret = 1; // parts.
  expected_m = 2;
  expected_n = 3;
  printf ("b = %u, a = %u. expect ret = %d. m = %d. n = %d.\n", b, a, expected_ret, expected_m, expected_n);
  ret = VII_4_part_or_parts_v1 (b, a, &m, &n);
  assert_int_equal(expected_ret, ret);
  assert_int_equal(expected_m, m);
  assert_int_equal(expected_n, n);

  b = 8;
  a = 12;
  m = -1;
  n = -1;
  ret = -1;
  expected_ret = 1; // parts.
  expected_m = 2;
  expected_n = 3;
  printf ("b = %u, a = %u. expect ret = %d. m = %d. n = %d.\n", b, a, expected_ret, expected_m, expected_n);
  ret = VII_4_part_or_parts_v1 (b, a, &m, &n);
  assert_int_equal(expected_ret, ret);
  assert_int_equal(expected_m, m);
  assert_int_equal(expected_n, n);
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
  run_test(test_VII_3);
  run_test(test_VII_4);
  run_test(test_VII_4_v1);
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