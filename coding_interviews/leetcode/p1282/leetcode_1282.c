/**
leetcode problem.

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/


**/

#include <stdlib.h>
#include <assert.h>

/**
******* Scratch work

*******
Example 1
Input: groupSizes = [3,3,3,3,3,1,3] , groupSizesSize = 7
Output: [[5],[0,1,2],[3,4,6]]

Explanation:
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
*******

groupSizes =
 0 1 2 3 4 5 6
[3,3,3,3,3,1,3]

groupSizesSize =
7
          0   1       2
return  [[5],[0,1,2],[3,4,6]]

returnSize =
3

returnColumnSizes =
[1, 3, 3]

*************************************************
*******
Example 2:

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
*******

groupSizes =
 0 1 2 3 4 5
[2,1,3,3,3,2]

groupSizesSize =
6
          0   1     2
return  [[1],[0,5],[2,3,4]]

returnSize =
3

returnColumnSizes =
[1, 2, 3]

**/

// Duplicates groupSizes array.
int *alloc_group_sizes_dup(int *group_sizes, int group_sizes_size) {
  int *dup;
  // TODO Args check.

  dup = calloc(group_sizes_size, sizeof(*(group_sizes)));
  assert(dup != NULL);

  if (!(dup != NULL)) {
    return NULL;
  }

  for (int i = 0; i < group_sizes_size; i++) {
    dup[i] = group_sizes[i];
  }

  return dup;
}

/*

Indicates this person has been allocated to a group. -1 is never a valid group
size so this is a safe value to use.

*/
#define PERSON_ASSIGNED_TO_GROUP -1

/*

Marks group_sz entries in the group_sizes array with PERSON_ASSIGNED_TO_GROUP,
if not already done, and returns an array of size group_sz containing the person
ID of each person allocated to the returned group.

*/
int *assign_group(int group_sz, int *group_sizes, int group_sizes_size) {
  // TODO Args check.
  int *group;
  int p;

  group = calloc(group_sz, sizeof(*(group)));

  // TODO NULL check.

  p = 0;
  for (int i = 0; i < group_sizes_size && p < group_sz; i++) {
    /*

    If this person belongs to a group of size group_sz and they have not been
    assigned to a group. Assign them to the current group and mark them as
    assigned.

    */
    if (group_sizes[i] == group_sz) {
      group[p] = i; // Save this person's ID.
      p++; // Increment the number of people assigned so far.
      group_sizes[i] = PERSON_ASSIGNED_TO_GROUP; // Mark this person as assigned to a group.
    }

  }

  return group;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
  // TODO: Args check.
  int *group_sizes_dup;
  int **assigned_groups;
  int return_size;
  int *return_column_sizes;

  // Duplicate the groupSizes array because we will be modifying it.
  group_sizes_dup = alloc_group_sizes_dup(groupSizes, groupSizesSize);

  // TODO NULL test.

  // At most, every person belongs to their own group.
  assigned_groups = calloc(groupSizesSize, sizeof(*(assigned_groups)));
  // TODO NULL test.

  return_column_sizes = calloc(groupSizesSize, sizeof( *(return_column_sizes) ));
  // TODO NULL test.

  // Assign every person to a group.
  return_size = 0;
  for (int i = 0; i < groupSizesSize; i++) {
    if (group_sizes_dup[i] != PERSON_ASSIGNED_TO_GROUP) {
      return_column_sizes[return_size] = group_sizes_dup[i]; // Save the size of this group.
      assigned_groups[return_size] = assign_group(group_sizes_dup[i], group_sizes_dup, groupSizesSize);
      return_size++;
    }
  }

  // Return result.
  *returnSize = return_size;
  *returnColumnSizes = return_column_sizes;

  return assigned_groups;
}