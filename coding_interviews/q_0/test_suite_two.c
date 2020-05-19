#include "seatest.h"
//  SEATEST NOTE. der: "test suite" = group of individual tests in single file e.g. this file.

/** SEATEST NOTE.

  der:
  What does seatest do if an assert occurs inside my C code?

  ANS: Seatest doesn't continue. Assert forces immediate termination, same as
  without seatest. No test summary is printed.

**/

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

void test_fixture_two( void )
{

  test_fixture_start();
  run_test(test_asserting);
  run_test(test_assert_fails);
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