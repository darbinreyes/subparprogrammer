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

#include <assert.h>

#define MAX(a,b) (  ( (a) > (b) ) ? (a) : (b) )
#define MIN(a,b) (  ( (a) < (b) ) ? (a) : (b) )

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
  // ? Is gridColSize really a row size?
}