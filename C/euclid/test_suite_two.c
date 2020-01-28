#include "seatest.h"

int
VII_1_relatively_prime (
  unsigned int a,
  unsigned int b
  );

void test_VII_1()
{
  assert_true( VII_1_relatively_prime (12, 4) == 0);
  assert_true( VII_1_relatively_prime (13, 4) == 1);
  assert_true( VII_1_relatively_prime (54, 85) == 1);
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
	run_test(test_asserting);
	run_test(test_assert_fails);
	test_fixture_end();	
}