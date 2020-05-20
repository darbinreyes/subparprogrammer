#include "seatest.h"
#include "demoq2.h" // int generalizedGCD(int num, int* arr);

/* Given test cases.

Test case 1:

Input:
5,
[2, 3, 4, 5, 6]

Expected Return Value:
1

Test case 2:

Input:
5,
[2, 4, 6, 8, 10]

Expected Return Value:
2

*/

/* My test cases.

Test case 3:
Input:
4,
[20, 30, 100, 200]

Expected Return Value:
10

Test case 4:
Input:
3,
[51, 884, 3009]

Expected Return Value:
17

*/


void test_0()
{
  int input_num = 5;
  int input_arr[] = {2, 3, 4, 5, 6};
  int expected_result = 1;
  int computed_result;
  computed_result = generalizedGCD(input_num, input_arr);
  assert_int_equal(expected_result, computed_result);
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  test_fixture_end();                 // ends a fixture
}