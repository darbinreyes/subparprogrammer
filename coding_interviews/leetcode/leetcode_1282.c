/**

leetcode problem.

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/


**/



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){


    if(groupSize == NULL || groupSizesSize == 0 || returnSize == NULL || returnColumnSizes) {
        // Invalid input
        return NULL;
    }

    // to begin with, handle the case group size = 1

    int AssignedCount = 0;
    int i;
    int *Group[500];
    int GroupOffset = 0;
    int CurrentGroupSize = 1;

    for(i = 0; i < groupSizesSize; i++){
        if(groupSizes[i] == CurrentGroupSize) {
            Group[GroupOffset] = malloc(sizeof(int) * CurrentGroupSize);
            if(*Group == NULL) {
                // malloc failed.
                return NULL;
            }
            Group[GroupOffset][0] = i; // Place person i in group.
            GroupOffset++;
            AssignedCount++;
        }
    }

/**
Example 1 Analysis

////
Example 1
Input: groupSizes = [3,3,3,3,3,1,3] , groupSizesSize = 7
Output: [[5],[0,1,2],[3,4,6]]

Explanation:
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
////

// Input: groupSizes = [3,3,3,3,3,1,3] , groupSizesSize = 7
 0 1 2 3 4 5 6
[3,3,3,3,3,1,3]
We have 7 people, whose IDs are 0,1,2,3,4,5,6

Person 0 belongs to a group of size 3
Person 1 ...
Person 5 belongs to a group of size 1
Person 6 belongs to a group of size 3

Output: [[5],[0,1,2],[3,4,6]]

Person 5, belongs to a group of size 1, therefore he is the only person in this group. // Handling this case may be a good place to start the implementation

Persons 0, 1, 2 belong to a group of size 3, therefore we can place them into one group.

Persons 3, 4, 6 ... similarly

Note that the sum of the lengths of the returned arrays = number of people = groupSizesSize.

for this example we return [[5],[0,1,2],[3,4,6]] and
*returnSize = 3
*returnColumnSizes = [1, 3, 3]

//

if a person belongs to a group of size 1, place them in their own group.

if a person belongs to a group of size 2, alloc an array of size 2, place that person in the group, then scan groupSizes for another person who is part of a group having size = 2. Assuming every entry in groupSizes >= 1, we can mark people who have been placed into a group by this function can be marked with -1.

We can proceed in this manner until every person has been placed in a group. We can dettect when every person has been placed in a group by counting how any people have been placed in a group and comparing that to groupSizesSize.

// Plan

while there are unassigned persons.

assign people who belong to a group size of 1
assign people who belong to a group size of 2

if done, set output arguments, return output array.

**/
}