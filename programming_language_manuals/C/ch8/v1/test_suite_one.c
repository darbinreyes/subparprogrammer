#include "seatest.h"
#include "knr-malloc.h"
#include "string.h"

/* Given test cases.

*/

/* My test cases.


*/


void test_0()
{
    #define STR0 "The lone and level sands stretch far away."
    char *str = STR0;
    int sz = sizeof (STR0);
    char *p;

    assert_true (0);
    assert_true(p != NULL);

    if (p == NULL) {
        return;
    }

    memcpy(p, str, sz);

    assert_string_equal(str, p);

    knr_free(p);
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  test_fixture_end();                 // ends a fixture
}