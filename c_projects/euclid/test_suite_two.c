#include "seatest.h"
//  SEATEST NOTE. der: "test suite" = group of individual tests in single file e.g. this file.
#include "euclid.h"

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
  unsigned int a, b; // Inputs.
  int ret; // Computed return value.
  int expected_ret; // Expected return value.

  printf("%s\n",__FUNCTION__);

  a = 12;
  b = 4;
  expected_ret = NOT_RELATIVELY_PRIME;
  ret = VII_1_relatively_prime (a, b);
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 13;
  b = 4;
  expected_ret = RELATIVELY_PRIME;
  ret = VII_1_relatively_prime (a, b);
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 54;
  b = 85;
  expected_ret = RELATIVELY_PRIME;
  ret = VII_1_relatively_prime (a, b);
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 31;
  b = 85;
  expected_ret = RELATIVELY_PRIME;
  ret = VII_1_relatively_prime (a, b);
  printf ("a = %u, b = %u. rp = %d. expect rp = %d.\n", a, b, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  /** SEATEST NOTE.
  der:
  // assert_true( VII_1_relatively_prime (7, 7) == 0); // See comment below.
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
  unsigned int a, b; // Inputs.
  int ret; // Computed return value.
  int expected_ret; // Expected return value.

  printf("%s\n",__FUNCTION__);

  a = 884;
  b = 3009;
  expected_ret = 17;
  ret = VII_2_gcm (a, b);
  printf ("a = %u, b = %u. gcm = %d. expect gcm = %d.\n", a, b, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 32;
  b = 4;
  expected_ret = 4;
  ret = VII_2_gcm (a, b);
  printf ("a = %u, b = %u. gcm = %d. expect gcm = %d.\n", a, b, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 32;
  b = 5;
  expected_ret = 1;
  ret = VII_2_gcm (a, b);
  printf ("a = %u, b = %u. gcm = %d. expect gcm = %d.\n", a, b, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

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
  unsigned int a, b, c; // Inputs.
  int ret; // Computed returned value.
  int expected_ret; // Expected return value.

  printf("%s\n",__FUNCTION__);

  a = 32;
  b = 8;
  c = 4;
  expected_ret = 4;
  ret = VII_3_gcm (a, b, c);
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 32;
  b = 64;
  c = 4;
  expected_ret = 4;
  ret = VII_3_gcm (a, b, c);
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 32;
  b = 64;
  c = 5;
  expected_ret = 1;
  ret = VII_3_gcm (a, b, c);
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  a = 32;
  b = 64;
  c = 6;
  expected_ret = 2;
  ret = VII_3_gcm (a, b, c);
  printf ("a = %u, b = %u, c = %u. gcm = %d. expect gcm = %d.\n", a, b, c, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

}

void test_VII_4 ()
{
  /**

  Here are the correct values for the test cases computed separately in python.

  >>> int(7 % 3 > 0)
  1 // parts
  >>> int(7 % 6 > 0)
  1
  >>> int(6 % 2 > 0)
  0 // part
  >>> int(12 % 3 > 0)
  0
  >>> int(6 % 4 > 0)
  1
  >>> int(12 % 8 > 0)
  1
  >>> int(3 % 1 > 0)
  0
  TODO: Other test cases.

  **/
  unsigned int a, b; // Inputs.
  int ret; // Computed returned value.
  int expected_ret; // Expected return value.

  printf("%s\n",__FUNCTION__);

  b = 3;
  a = 7;
  expected_ret = 1; // parts.
  ret = VII_4_part_or_parts (b, a);
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  b = 6;
  a = 7;
  expected_ret = 1; // parts.
  ret = VII_4_part_or_parts (b, a);
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  b = 2;
  a = 6;
  expected_ret = 0; // part.
  ret = VII_4_part_or_parts (b, a);
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  b = 3;
  a = 12;
  expected_ret = 0; // part.
  ret = VII_4_part_or_parts (b, a);
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  b = 4;
  a = 6;
  expected_ret = 1; // parts.
  ret = VII_4_part_or_parts (b, a);
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  b = 8;
  a = 12;
  expected_ret = 1; // parts.
  ret = VII_4_part_or_parts (b, a);
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, ret, expected_ret);
  assert_int_equal(expected_ret, ret);

  b = 1;
  a = 3;
  expected_ret = 0; // part.
  ret = VII_4_part_or_parts (b, a);
  printf ("b = %u, a = %u. part_or_parts = %d. expect part_or_parts = %d.\n", b, a, ret, expected_ret);
  assert_int_equal(expected_ret, ret);
}

void test_VII_4_v1 (void)
{
/**

  Here are the correct values for the test cases computed separately in python.

$ python3.8 VII_4_part_or_parts_v1.py
ret, m, n =  (1, 3, 7)
ret, m, n =  (1, 6, 7)
ret, m, n =  (0, 2, 6)
ret, m, n =  (0, 3, 12)
ret, m, n =  (1, 2, 3)
ret, m, n =  (1, 2, 3)
ret, m, n =  (0, 1, 3)
ret, m, n =  (0, 1, 4)

**/
  unsigned int a, b; // Input values.
  int m, n; // Computed output argument values.
  int ret; // Computed return value.
  int expected_m, expected_n; // Expected output argument values.
  int expected_ret; // Expected return value.

  printf("%s\n",__FUNCTION__);

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

  b = 1;
  a = 3;
  m = -1;
  n = -1;
  ret = -1;
  expected_ret = 0; // parts.
  expected_m = 1;
  expected_n = 3;
  printf ("b = %u, a = %u. expect ret = %d. m = %d. n = %d.\n", b, a, expected_ret, expected_m, expected_n);
  ret = VII_4_part_or_parts_v1 (b, a, &m, &n);
  assert_int_equal(expected_ret, ret);
  assert_int_equal(expected_m, m);
  assert_int_equal(expected_n, n);
}

void test_VII_5 (void)
{
  /**

  Test cases computed separately in python.

  >>> 9/3 == 12/4 == (9 + 12)/(3 + 4)
  True
  >>> 9/3 == 3/1 == (9 + 3)/(3 + 1)
  True
  >>> 9/3 == 4/1 == (9 + 4)/(3 + 1)
  False
  >>> 16/4 == 4/1 == (16 + 4)/(4 + 1)
  True
  >>> 7/1 == 21/3 == (7 + 21)/(1 + 3)
  True

  **/
  PAIR p0, p1; // Input values.
  int ret; // Computed return value.
  int expected_ret; // Expected return value.

  p0.a = 3;
  p0.b = 9;

  p1.a = 4;
  p1.b = 12;
  // sum = 7, 21
  expected_ret = 1;
  printf("(%d, %d) , (%d, %d), expected_ret = %d.\n", p0.a, p0.b, p1.a, p1.b, expected_ret);
  ret = VII_5_sum_same_part (p0, p1);
  assert_int_equal(expected_ret, ret);

  p0.a = 3;
  p0.b = 9;

  p1.a = 1;
  p1.b = 3;
  // sum = 4, 12
  expected_ret = 1;
  printf("(%d, %d) , (%d, %d), expected_ret = %d.\n", p0.a, p0.b, p1.a, p1.b, expected_ret);
  ret = VII_5_sum_same_part (p0, p1);
  assert_int_equal(expected_ret, ret);

  p0.a = 3;
  p0.b = 9;

  p1.a = 1;
  p1.b = 4;
  // sum = 4, 13
  expected_ret = 0;
  printf("(%d, %d) , (%d, %d), expected_ret = %d.\n", p0.a, p0.b, p1.a, p1.b, expected_ret);
  ret = VII_5_sum_same_part (p0, p1);
  assert_int_equal(expected_ret, ret);

  p0.a = 4;
  p0.b = 16;

  p1.a = 1;
  p1.b = 4;
  // sum = 5, 20
  expected_ret = 1;
  printf("(%d, %d) , (%d, %d), expected_ret = %d.\n", p0.a, p0.b, p1.a, p1.b, expected_ret);
  ret = VII_5_sum_same_part (p0, p1);
  assert_int_equal(expected_ret, ret);

  p0.a = 1;
  p0.b = 7;

  p1.a = 3;
  p1.b = 21;
  // sum = 4, 28
  expected_ret = 1;
  printf("(%d, %d) , (%d, %d), expected_ret = %d.\n", p0.a, p0.b, p1.a, p1.b, expected_ret);
  ret = VII_5_sum_same_part (p0, p1);
  assert_int_equal(expected_ret, ret);
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
  run_test(test_VII_5);
  // run_test(test_asserting);
  // run_test(test_assert_fails);
  test_fixture_end();
  /** SEATEST NOTE.

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