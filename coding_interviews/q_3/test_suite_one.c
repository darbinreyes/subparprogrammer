#include "seatest.h"

/* Given test cases.

******* Test case 1:
Input:
{'a','b','c','d','a','e','f','g','h','i','j','e'}

 0 1 2 3 4 5 6 7 8 9 10 11
[a,b,c,d,a,e,f,g,h,i,j, e]

Expected Return Value:
[5, 7] // 5 + 7 = 12

******* Test case 2:
Input:
{'z','z','c','b','z','c','h','f','i','h','i'}

 0 1 2 3 4 5 6 7 8 9 10
[z,z,c,b,z,c,h,f,i,h,i]

Expected Return Value:
[6, 5] // 6 + 5 = 11

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