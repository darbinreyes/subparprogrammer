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


*/


void test_0()
{
  int input_numToys, input_topToys, input_numQuotes;
  char *input_toys_arr[] = {"elmo", "elsa", "legos", "drone", "tablet", "warcraft"};
  char *input_quotes_arr[] = {
  "Elmo is the hottest toy of the season! Elmo will be on every kid's wishlist!",
  "The new Elmo dolls are super high quality.",
  "Expect the Elsa dolls to be very popular this year",
  "Elsa and Elmo are the toys I'll be buying for my kids",
  "For parents of older kids, look into buying them a drone.",
  "Warcraft is slowly rising in popularity ahead of the holiday season"
  };
  char *expected_result_arr[] = {"elmo", "elsa"};
  int expected_result_size = 2;
  boundedStringArray *computed_result, input_toys, input_quotes, expected_result;

  input_numToys = 6;
  input_topToys = 2;
  input_numQuotes = 6;

  input_toys.size = input_numToys;
  input_toys.arr = input_toys_arr;

  input_quotes.size = input_numQuotes;
  input_quotes.arr = input_quotes_arr;

  expected_result.size = expected_result_size;
  expected_result.arr = expected_result_arr;

// boundedStringArray* popularNToys(int numToys, int topToys,
//                                     boundedStringArray* toys,
//                                     int numQuotes,
//                                     boundedStringArray* quotes);

  computed_result = popularNToys(input_numToys, input_topToys, &input_toys, input_numQuotes, &input_quotes);

  assert_int_equal(expected_result.size, computed_result->size);

  for(int i = 0; i < expected_result.size; i++) {
    assert_string_equal(expected_result.arr[i], computed_result->arr[i]);
  }
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  test_fixture_end();                 // ends a fixture
}