#include "seatest.h"

char* isBalanced(char* s);

/* Given test cases.

*/

/* My test cases.


*/


void test_0()
{
  char *input = "{[()]}";
  char *output_actual;
  char *output_expected = "YES";

  output_actual = isBalanced(input);

  assert_string_equal(output_expected, output_actual);
}

void test_1()
{
  char *input = "{[(])}";
  char *output_actual;
  char *output_expected = "NO";

  output_actual = isBalanced(input);

  assert_string_equal(output_expected, output_actual);

}

void test_2()
{
  char *input = "{{[[(())]]}}";
  char *output_actual;
  char *output_expected = "YES";

  output_actual = isBalanced(input);

  assert_string_equal(output_expected, output_actual);

}

void test_3()
{
  char *input = "x))";
  char *output_actual;
  char *output_expected = "NO";

  output_actual = isBalanced(input);

  assert_string_equal(output_expected, output_actual);

}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  run_test(test_1);
  run_test(test_2);
  run_test(test_3);
  test_fixture_end();                 // ends a fixture
}