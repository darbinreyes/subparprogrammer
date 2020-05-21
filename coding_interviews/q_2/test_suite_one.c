#include "seatest.h"
#include "realq1.h"

/* Given test cases.
Input:
numToys = 6
topToys = 2
toys = ["elmo", "elsa", "legos", "drone", "tablet", "warcraft"]
numQuotes = 6
quotes=
["Elmo is the hottest toy of the season! Elmo will be on every kid's wishlist!",
"The new Elmo dolls are super high quality.",
"Expect the Elsa dolls to be very popular this year",
"Elsa and Elmo are the toys I'll be buying for my kids",
"For parents of older kids, look into buying them a drone.",
"Warcraft is slowly rising in popularity ahead of the holiday season"]

Output:
["elmo", "elsa"]

Explanation:
"elmo" - 3 quotes
"elsa" - 2 quotes
"drone" - 1 quote
"warcraft" - 1 quote
*/

/* My test cases.

  See test_1.

*/

#define SIZE_OF_ARRAY(arr) (sizeof((arr))/sizeof(*(arr)))

void test_0()
{
  char *input_toys_arr[] = {"elmo", "elsa", "legos", "drone", "tablet", "warcraft"};
  char *input_quotes_arr[] = {
  "Elmo is the hottest toy of the season! Elmo will be on every kid's wishlist!",
  "The new Elmo dolls are super high quality.",
  "Expect the Elsa dolls to be very popular this year",
  "Elsa and Elmo are the toys I'll be buying for my kids",
  "For parents of older kids, look into buying them a drone.",
  "Warcraft is slowly rising in popularity ahead of the holiday season"
  };
  char *output_expected_arr[] = {"elmo", "elsa"};
  int input_numToys = 6, input_topToys = 2, input_numQuotes = 6, output_expected_size = 2;
  boundedStringArray input_toys = {SIZE_OF_ARRAY(input_toys_arr), input_toys_arr};
  boundedStringArray input_quotes = {SIZE_OF_ARRAY(input_quotes_arr), input_quotes_arr};
  boundedStringArray output_expected_b_str_arr = {SIZE_OF_ARRAY(output_expected_arr), output_expected_arr};
  boundedStringArray *output_b_str_arr = NULL;

  assert_int_equal(input_numToys, input_toys.size);
  assert_int_equal(input_numQuotes, input_quotes.size);
  assert_int_equal(output_expected_size, output_expected_b_str_arr.size);

  output_b_str_arr = popularNToys(input_numToys, input_topToys, &input_toys, input_numQuotes, &input_quotes);

  assert_int_equal(output_expected_b_str_arr.size, output_b_str_arr->size);

  for(int i = 0; i < output_expected_b_str_arr.size; i++) {
    assert_string_equal(output_expected_b_str_arr.arr[i], output_b_str_arr->arr[i]);
  }
}

/*

  This test case is the same as above except "elsa" is replaced with "aelsa".
  An additional quote is added containing "aelsa" so that there is a tie between
  "elmo" and "aelsa". I used this to verify that the alphabetic sort works.

*/
void test_1()
{
  char *input_toys_arr[] = {"elmo", "aelsa", "legos", "drone", "tablet", "warcraft"};
  char *input_quotes_arr[] = {
  "Elmo is the hottest toy of the season! Elmo will be on every kid's wishlist!",
  "The new Elmo dolls are super high quality.",
  "Expect the aElsa dolls to be very popular this year",
  "aElsa and Elmo are the toys I'll be buying for my kids",
  "For parents of older kids, look into buying them a drone.",
  "Warcraft is slowly rising in popularity ahead of the holiday season",
  "Why would you name a toy aElsa?"
  };
  char *output_expected_arr[] = {"aelsa", "elmo"};
  int input_numToys = 6, input_topToys = 2, input_numQuotes = 7, output_expected_size = 2;
  boundedStringArray input_toys = {SIZE_OF_ARRAY(input_toys_arr), input_toys_arr};
  boundedStringArray input_quotes = {SIZE_OF_ARRAY(input_quotes_arr), input_quotes_arr};
  boundedStringArray output_expected_b_str_arr = {SIZE_OF_ARRAY(output_expected_arr), output_expected_arr};
  boundedStringArray *output_b_str_arr = NULL;

  assert_int_equal(input_numToys, input_toys.size);
  assert_int_equal(input_numQuotes, input_quotes.size);
  assert_int_equal(output_expected_size, output_expected_b_str_arr.size);

  output_b_str_arr = popularNToys(input_numToys, input_topToys, &input_toys, input_numQuotes, &input_quotes);

  assert_int_equal(output_expected_b_str_arr.size, output_b_str_arr->size);

  for(int i = 0; i < output_expected_b_str_arr.size; i++) {
    assert_string_equal(output_expected_b_str_arr.arr[i], output_b_str_arr->arr[i]);
  }
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  run_test(test_1);
  test_fixture_end();                 // ends a fixture
}