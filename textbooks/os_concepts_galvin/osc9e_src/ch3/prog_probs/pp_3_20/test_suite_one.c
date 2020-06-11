#include "seatest.h"
#include "prog_prob_3_20.h"

/* Given test cases.

*/

/* My test cases.


*/


void test_0()
{
  char const * const pid_state = test_get_pid_state_arr();

  allocate_map();

  // Verify that the pid_state array is initialized to "all free".
  for (int i = 0; i < NUM_PIDS; i++) {
    assert_int_equal(PID_STATE_IS_FREE, pid_state[i]);
  }
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  test_fixture_end();                 // ends a fixture
}