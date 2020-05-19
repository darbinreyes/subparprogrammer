#include "seatest.h"
#include "demoq1.h"

/* Given test cases.

Test case 1.
Input: [1, 0, 0, 0, 0, 1, 0, 0], 1.
Expected Return Value: 0 1 0 0 1 0 1 0.

Test case 2.
Input: [1, 1, 1, 0, 1, 1, 1, 1], 2.
Expected Return Value: 0 0 0 0 0 1 1 0.

*/

/* My test cases.

Test case 2.
Input: [1, 0, 0, 0, 0, 1, 0, 0], 2.
Expected Return Value: 1, 0, 1, 1, 0, 0, 0, 1.


Test case 3.
Input: [1, 1, 1, 0, 1, 1, 1, 1], 3.
Expected Return Value: 0, 0, 0, 0, 1, 1, 1, 1.

*/


void test_cellCompete_0()
{
  int input_arr[] = {1, 0, 0, 0, 0, 1, 0, 0};
  int input_days = 1;
  int expected_arr[] = {0, 1, 0, 0, 1, 0, 1, 0};
  boundedarray *computed_result = NULL;

  computed_result = cellCompete(input_arr, input_days);
  assert_n_array_equal(expected_arr, computed_result->arr, computed_result->size);
}

void test_cellCompete_1()
{
  int input_arr[] = {1, 1, 1, 0, 1, 1, 1, 1};
  int input_days = 2;
  int expected_arr[] = {0, 0, 0, 0, 0, 1, 1, 0};
  boundedarray *computed_result = NULL;

  computed_result = cellCompete(input_arr, input_days);
  assert_n_array_equal(expected_arr, computed_result->arr, computed_result->size);
}

void test_cellCompete_2()
{
  int input_arr[] = {1, 0, 0, 0, 0, 1, 0, 0};
  int input_days = 2;
  int expected_arr[] = {1, 0, 1, 1, 0, 0, 0, 1};
  boundedarray *computed_result = NULL;

  computed_result = cellCompete(input_arr, input_days);
  assert_n_array_equal(expected_arr, computed_result->arr, computed_result->size);
}

void test_cellCompete_3()
{
  int input_arr[] = {1, 1, 1, 0, 1, 1, 1, 1};
  int input_days = 3;
  int expected_arr[] = {0, 0, 0, 0, 1, 1, 1, 1};
  boundedarray *computed_result = NULL;

  computed_result = cellCompete(input_arr, input_days);
  assert_n_array_equal(expected_arr, computed_result->arr, computed_result->size);
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_cellCompete_0);
  run_test(test_cellCompete_1);
  run_test(test_cellCompete_2);
  run_test(test_cellCompete_3);
  test_fixture_end();                 // ends a fixture
}