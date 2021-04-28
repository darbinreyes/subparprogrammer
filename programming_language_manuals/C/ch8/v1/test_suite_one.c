#include "seatest.h"
#include "private-knr-malloc.h"
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

    printf("Size of unit = Size of header = %lu\n", sizeof(Header));
    printf("Size of STR0 = %lu\n", sizeof(STR0));

    p = knr_malloc(sz);

    assert_true(p != NULL);

    if (p == NULL) {
        printf("knr_malloc returned NULL\n");
        return;
    }

    printf("AFTER knr_malloc()\n");
    print_free_list();

    memcpy(p, str, sz);

    assert_string_equal(str, p);

    knr_free(p);
    printf("AFTER knr_free()\n");
    print_free_list();
}

void test_1()
{
    #define STR0 "The lone and level sands stretch far away."
    #define STR1 "Nothing beside remains. Round the decay"
    char *p, *s;

    printf("Size of STR0 = %lu\n", sizeof(STR0));
    printf("Size of STR1 = %lu\n", sizeof(STR1));

    p = knr_malloc(sizeof(STR0));

    assert_true(p != NULL);

    if (p == NULL) {
        printf("knr_malloc returned NULL\n");
        return;
    }

    memcpy(p, STR0, sizeof(STR0));

    assert_string_equal(STR0, p);

    //////////

    s = knr_malloc(sizeof(STR1));

    assert_true(s != NULL);

    if (s == NULL) {
        printf("knr_malloc returned NULL\n");
        return;
    }

    memcpy(s, STR1, sizeof(STR1));

    assert_string_equal(STR1, s);


    printf("AFTER knr_malloc()\n");
    print_free_list();



    //knr_free(p);
    //printf("AFTER knr_free()\n");
    //print_free_list();
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  run_test(test_1);
  test_fixture_end();                 // ends a fixture
}