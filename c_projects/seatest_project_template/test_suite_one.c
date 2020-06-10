#include "seatest.h"

/* Given test cases.

*/

/* My test cases.


*/


void test_0()
{

}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  test_fixture_end();                 // ends a fixture
}