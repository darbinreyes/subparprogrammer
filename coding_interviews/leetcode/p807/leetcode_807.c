/*

  https://leetcode.com/problems/max-increase-to-keep-city-skyline/

*/

/*

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation:
The grid is:
[ [3, 0, 8, 4],
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7] // col. 0 - col. (n - 1)
The skyline viewed from left or right is: [8, 7, 9, 3] // row 0 - row (n - 1)

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

******* Scratch Work

"The skyline viewed from top or bottom is: [9, 4, 8, 7]"
= Max value in each column of the original grid.

"The skyline viewed from left or right is: [8, 7, 9, 3]"
= Max value of each row of the original grid.

Does the following work?

For a given i, j , we may increment under the constraint that the result of
incrementing is at most column max, and at most row max.

From this it is manifest that we can increment grid 1, j min(col. max, row max).

*******

In the above example i, j = 0, 0

row max = 8  = lr_max[i=0]
col. max = 9 = tb_max[j=0]

min(8, 9) = 8 = grid_max.

inc = grid_max - grid[i][j]

********

i, j = 0, 1

row max = 8 = lr_max[i=0]
col. max = 4 = tb_max[j=1]

min(8, 4) = 4 = grid_max

inc = grid_max - grid[i][j]

********

i, j = 1, 2

row max = 7 = lr_max[i=1]
col. max = 8 = tb_max[j=2]

min(7, 8) = 7 = grid_max


*/

/*
******* Scratch work

"1 < grid.length = grid[0].length <= 50."
I assume this means the grid is square and between size 2-50 inclusive.

"All heights grid[i][j] are in the range [0, 100]."
TODO: Does this mean we should not increase any height beyond 100?


*/

#include <assert.h>
#include <stdio.h>

#define MAX(a,b) (  ( (a) > (b) ) ? (a) : (b) )
#define MIN(a,b) (  ( (a) < (b) ) ? (a) : (b) )
#define MAX_GRID_SIZE 50

// Returns the max value in row r.
int row_max(const int r, int const * const * const grid, const int gridSize,  int const * const gridRowSize) {
  int m;
  // TODO: Validate args.
  assert(r < gridSize);

  m = 0;

  /* Note on using the const qualifier with pointers.

    You can always do a sanity check using the compiler, by ensuring that an
    error is reported for changes to a variable that you do not want.

    Notes:

    const int i;
    and
    int const i;
    have the same meaning.

    to make grid read-only, place a const qualifier immediately before grid in
    the parameter type.

    Use "int const * const * const grid" all three of the following cause the
    expected read-only error. The compiler will still generate the warning
    "discards qualifiers in nested pointer types".

    grid = NULL;     // Use "int ** const grid"
    grid[0] = NULL;  // Use "int * const *grid"
    grid[0][0] = 7;  // Use "int const * const *grid"

    The declaration:

    const int *gridRowSize

    gridRowSize = NULL; // Does not cause an error.
    gridRowSize[0] = 7; // Does cause an error.

    It is equivalent to:
    int const * gridRowSize

    Therefore, when const is applied as a prefix, it applies to the deepest
    level indirection only.

    When const is applied immediately before the variable name, it applies to the
    variable name, which is the shallowest level of indirection.

    To have const can be applied to all levels of indirection, insert const
    before and after each occurrence of *.

    To ensure an error on both of the above use:

    int const * const gridRowSize

    The level of indirection to which a const applies is equal to the number of
    "*" characters that appear after that const. Thus, in the above, the first
    const has 1 "*" after it, therefore it applies to gridRowSize[0].

  */

  for (int i = 0; i < gridRowSize[r]; i++) {
    if (grid[r][i] > m) {
      m = grid[r][i];
    }
  }

  return m;
}

// Returns the max value in column c.
int col_max(const int c, int * const *grid, const int gridSize, const int *gridRowSize) {
  int m;
  // TODO: Validate args.

  m = 0;

  for (int i = 0; i < gridSize; i++) {
    assert(c < gridRowSize[i]);
    if (grid[i][c] > m) {
      m = grid[i][c];
    }
  }

  return m;
}

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
  // ? Is gridColSize really a row size?
  int tb_grid_max[MAX_GRID_SIZE];
  int lr_grid_max[MAX_GRID_SIZE];
  int *gridRowSize;
  int sum, tmp_max;

  gridRowSize = gridColSize;

  for (int i = 0; i < gridSize; i++) {
    lr_grid_max[i] = row_max(i, grid, gridSize, gridRowSize);
  }

  for (int i = 0; i < gridSize; i++) {
    assert(gridSize == gridRowSize[i]);
    tb_grid_max[i] = col_max(i, grid, gridSize, gridRowSize);
  }

  sum = 0;

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridRowSize[i]; j++) {
      tmp_max = MIN(lr_grid_max[i], tb_grid_max[j]);
      sum += tmp_max - grid[i][j];
    }
  }

  return sum;
}