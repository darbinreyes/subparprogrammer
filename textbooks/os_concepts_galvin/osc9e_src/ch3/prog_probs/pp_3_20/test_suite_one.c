#include "seatest.h"
#include "prog_prob_3_20.h"

/* Given test cases.

*/

/* My test cases.


*/


void test_0()
{
  allocate_map();
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  test_fixture_end();                 // ends a fixture
}