#include "seatest.h"

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
  assert_true( VII_1_relatively_prime (12, 4) == 0);
  assert_true( VII_1_relatively_prime (13, 4) == 1);
  assert_true( VII_1_relatively_prime (54, 85) == 1);
}

void test_VII_2()
{
  int a, b, result;

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

void test_asserting()
{
  assert_true( VII_1_relatively_prime (12, 4) == 0);
  assert_true( VII_1_relatively_prime (13, 4) == 1);
  assert_true( VII_1_relatively_prime (54, 85) == 1);

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
  run_test(test_VII_1);
  run_test(test_VII_2);
	run_test(test_asserting);
	run_test(test_assert_fails);
	test_fixture_end();	
}