#include "seatest.h"

void test_fixture_one( void );

void all_tests( void )
{
  test_fixture_one();
  // add new test fixtures here.
}

/**
  Main function for running tests.
**/
int main( int argc, char** argv )
{
  return seatest_testrunner(argc, argv, all_tests, NULL, NULL);
}