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

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

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

*/

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
// ? Is gridColSize really a row size?
}