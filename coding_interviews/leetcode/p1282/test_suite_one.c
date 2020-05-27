#include "seatest.h"

int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes);

/* Given test cases.

*******
Example 1
Input: groupSizes = [3,3,3,3,3,1,3] , groupSizesSize = 7
Output: [[5],[0,1,2],[3,4,6]]

Explanation:
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
*******

*******
Example 2:

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
*******

*/

/* My test cases.


*/


void test_0()
{
  int groupSizes[] = {3,3,3,3,3,1,3};
  int groupSizesSize = 7;
  int **assigned_groups = NULL;
  int return_size = 0;
  int *return_column_sizes = NULL;
  int total_assigned = 0;
  assigned_groups = groupThePeople(groupSizes, groupSizesSize, &return_size, &return_column_sizes);
  // Since there are multiple valid solutions per input. We can only check the sizes of the output.
  for (int i = 0; i < return_size; i++) {
    total_assigned += return_column_sizes[i];
    for (int j = 0; j < return_column_sizes[i]; j++) {
      assert_true(assigned_groups[i][j] < groupSizesSize); // Person ID < groupSizesSize
    }
  }

  assert_int_equal(groupSizesSize, total_assigned); // Total number of people remains the same.
}

void test_fixture_one( void )
{
  test_fixture_start();               // starts a fixture
  run_test(test_0);
  test_fixture_end();                 // ends a fixture
}