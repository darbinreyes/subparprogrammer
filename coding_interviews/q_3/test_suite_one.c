#include "seatest.h"
#include "realq2.h"

/* Given test cases from the problem tab.
******* Example 1:
Input:
inputList=
{'a','b','a','b','c','b','a','c','a','d','e','f','e','g','d','e','h','i','j','h','k','l','i','j'}

Output:
[9,7,8]

******* Example 2:
Input:
inputList=
{'a','b','c'}

Output:
[1,1,1]

******* Example 3:
Input:
inputList=
{'a','b','c','a'}

Output:
[4]

*/

/* Given test cases. From the test cases tab.

******* Test case 1:
Input:
{'a','b','c','d','a','e','f','g','h','i','j','e'}

 0 1 2 3 4 5 6 7 8 9 10 11
[a,b,c,d,a,e,f,g,h,i,j, e]

Expected Return Value:
[5, 7]

******* Test case 2:
Input:
{'z','z','c','b','z','c','h','f','i','h','i'}

 0 1 2 3 4 5 6 7 8 9 10
[z,z,c,b,z,c,h,f,i,h,i]

Expected Return Value:
[6, 5]

*/

/* My test cases.


*/

#define ARRAY_LEN(arr) ( sizeof((arr))/sizeof(*(arr)) )

void test_0()
{
  char inputList_arr[] = {'a','b','a','b','c','b','a','c','a','d','e','f','e','g','d','e','h','i','j','h','k','l','i','j'};
  charboundedarray inputList = {ARRAY_LEN(inputList_arr), inputList_arr};
  int expected_output_arr[] = {9,7,8};
  boundedarray expected_outputList = {ARRAY_LEN(expected_output_arr), expected_output_arr};
  boundedarray *actual_outputList = NULL;

  actual_outputList = lengthEachScene(&inputList);

  assert_true(actual_outputList != NULL);

  assert_int_equal(expected_outputList.size, actual_outputList->size);
  //assert_n_array_equal(expected_outputList.arr, actual_outputList->arr, actual_outputList->size);
  for(int i = 0; i < actual_outputList->size; i++) {
    assert_int_equal(expected_outputList.arr[i], actual_outputList->arr[i]);
  }
}

void test_1()
{
  char inputList_arr[] = {'a','b','c'};
  charboundedarray inputList = {ARRAY_LEN(inputList_arr), inputList_arr};
  int expected_output_arr[] = {1,1,1};
  boundedarray expected_outputList = {ARRAY_LEN(expected_output_arr), expected_output_arr};
  boundedarray *actual_outputList = NULL;

  actual_outputList = lengthEachScene(&inputList);

  assert_true(actual_outputList != NULL);

  assert_int_equal(expected_outputList.size, actual_outputList->size);
  //assert_n_array_equal(expected_outputList.arr, actual_outputList->arr, actual_outputList->size);
  for(int i = 0; i < actual_outputList->size; i++) {
    assert_int_equal(expected_outputList.arr[i], actual_outputList->arr[i]);
  }
}

void test_2()
{
  char inputList_arr[] = {'a','b','c','a'};
  charboundedarray inputList = {ARRAY_LEN(inputList_arr), inputList_arr};
  int expected_output_arr[] = {4};
  boundedarray expected_outputList = {ARRAY_LEN(expected_output_arr), expected_output_arr};
  boundedarray *actual_outputList = NULL;

  actual_outputList = lengthEachScene(&inputList);

  assert_true(actual_outputList != NULL);

  assert_int_equal(expected_outputList.size, actual_outputList->size);
  //assert_n_array_equal(expected_outputList.arr, actual_outputList->arr, actual_outputList->size);
  for(int i = 0; i < actual_outputList->size; i++) {
    assert_int_equal(expected_outputList.arr[i], actual_outputList->arr[i]);
  }
}

void test_3()
{
  char inputList_arr[] = {'a','b','c','a'};
  charboundedarray inputList = {ARRAY_LEN(inputList_arr), inputList_arr};
  int expected_output_arr[] = {4};
  boundedarray expected_outputList = {ARRAY_LEN(expected_output_arr), expected_output_arr};
  boundedarray *actual_outputList = NULL;

  actual_outputList = lengthEachScene(&inputList);

  assert_true(actual_outputList != NULL);

  assert_int_equal(expected_outputList.size, actual_outputList->size);
  //assert_n_array_equal(expected_outputList.arr, actual_outputList->arr, actual_outputList->size);
  for(int i = 0; i < actual_outputList->size; i++) {
    assert_int_equal(expected_outputList.arr[i], actual_outputList->arr[i]);
  }
}

void test_4()
{
  char inputList_arr[] = {'a','b','c','d','a','e','f','g','h','i','j','e'};
  charboundedarray inputList = {ARRAY_LEN(inputList_arr), inputList_arr};
  int expected_output_arr[] = {5, 7};
  boundedarray expected_outputList = {ARRAY_LEN(expected_output_arr), expected_output_arr};
  boundedarray *actual_outputList = NULL;

  actual_outputList = lengthEachScene(&inputList);

  assert_true(actual_outputList != NULL);

  assert_int_equal(expected_outputList.size, actual_outputList->size);
  //assert_n_array_equal(expected_outputList.arr, actual_outputList->arr, actual_outputList->size);
  for(int i = 0; i < actual_outputList->size; i++) {
    assert_int_equal(expected_outputList.arr[i], actual_outputList->arr[i]);
  }
}

void test_5()
{
  char inputList_arr[] = {'z','z','c','b','z','c','h','f','i','h','i'};
  charboundedarray inputList = {ARRAY_LEN(inputList_arr), inputList_arr};
  int expected_output_arr[] = {6, 5};
  boundedarray expected_outputList = {ARRAY_LEN(expected_output_arr), expected_output_arr};
  boundedarray *actual_outputList = NULL;

  actual_outputList = lengthEachScene(&inputList);

  assert_true(actual_outputList != NULL);

  assert_int_equal(expected_outputList.size, actual_outputList->size);
  //assert_n_array_equal(expected_outputList.arr, actual_outputList->arr, actual_outputList->size);
  for(int i = 0; i < actual_outputList->size; i++) {
    assert_int_equal(expected_outputList.arr[i], actual_outputList->arr[i]);
  }
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  run_test(test_1);
  run_test(test_2);
  run_test(test_3);
  run_test(test_4);
  run_test(test_5);
  test_fixture_end();                 // ends a fixture
}