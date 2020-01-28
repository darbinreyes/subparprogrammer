#include "seatest.h" // der: access to seatest's built in functions.

/**
  der: declare function defined in test_suite_one.c.
  test_suite_one.c defines five functions
  The first four functions correspond to individual test cases.
  The last function defined is test_fixture_one() the function declared here
  - this function calls each test via a call to run_test().
  The calls to run_test() are sandwiched between calls to
  test_fixture_start()/test_fixture_end()


**/
void test_fixture_one( void );
/**
  der: This function is analogous to the above. It is defined in the file
  test_suite_two.c. This demonstrates how would separate our tests into different
  C files.
**/
void test_fixture_two( void );

void all_tests( void ) // der: a function to execute all tests. This is an argument seatest_testrunner().
{
	test_fixture_one();
	test_fixture_two();
	// add new test fixtures here.
}

/**
  der: each of these functions is run before/after every unit test,
  i.e. before/after each call to run_test().
**/
void my_suite_setup( void )
{
	printf("I'm done before every single test in the suite\r\n");
}

void my_suite_teardown( void )
{
	printf("I'm done after every single test in the suite\r\n");
}
/**
  der: Main function for running tests. See below for alternate mechanisms.
**/
int main( int argc, char** argv )
{
	return seatest_testrunner(argc, argv, all_tests, my_suite_setup, my_suite_teardown);	
}

/*************************************************************************************************************************************************************/
/*  Everything after this point are just alternative "main" functions which show different ways you can run the tests....they don't get used in this example */
/*************************************************************************************************************************************************************/

/*
Use this if you don't have any global setup/teardown...
*/
int main_no_setup_or_teardown( int argc, char** argv )
{
	return seatest_testrunner(argc, argv, all_tests, NULL, NULL);	
}

/*
Use this if you don't want to use the test runner...
*/
int main_do_it_myself( int argc, char** argv )
{
	suite_setup(my_suite_setup);
	suite_teardown(my_suite_teardown); 
	return run_tests(all_tests);	
}

/*
Use this if you don't want to use the test runner and don't have any global setup/teardown...
*/
int main_do_it_myself_really_simply( int argc, char** argv )
{	
	return run_tests(all_tests);	
}

