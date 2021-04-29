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
    #define STR0_SIZE (sizeof(STR0))
    #define STR0_USIZE (NBYTES_TO_NUNITS(STR0_SIZE))
    char *p;
    Header *hp;

    assert_true(sizeof(Header) == 16);

    printf("Size of STR0 (bytes, units) = (%lu, %lu)\n", STR0_SIZE, STR0_USIZE);

    p = knr_malloc(STR0_SIZE);

    assert_true(p != NULL);

    if (p == NULL) {
        printf("knr_malloc returned NULL\n");
        return;
    }

    printf("AFTER knr_malloc()\n");
    print_free_list();

    // Test that we can write to the block without errors.
    memcpy(p, STR0, STR0_SIZE);
    assert_string_equal(STR0, p);

    // Verify the size of the returned block
    hp = (Header *) p;
    hp--;
    assert_true(hp->s.size == STR0_USIZE);

    // Test that free works without error
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
  //run_test(test_1);
  test_fixture_end();                 // ends a fixture
}