# Problem Tab

You are working on a project for Amazon Video and need to cut films into scenes.
To help streamline the creation of the final films, the team needs to develop an
automated way of breaking up individual shots (short sequence from a particular
camera angle) in a film into scenes (a sequence of shots).
There is already an algorithm that breaks the film up into shots and labels them
with a letter.
Identical shots are labeled with the same letter.
Write a function which will partition a sequence of shot labels into scenes so
that no shot labels appear in more than one scene.
The output should be the length of each scene.


**Input**

The input to the function/method consists of an argument - inputList, a list of
characters representing the sequence of shots.


**Output**

Return a list of integers representing the length of each scene, in the order in
which it appears in the given sequence of shots.


**Examples**


Example 1


Input:
inputList = [a,b,a,b,c,b,a,c,a,d,e,f,e,g,d,e,h,i,j,h,k,l,i,j]

Output:
[9,7,8]

Explanation:
The first scene consists of the shots a, b, and c. The second scene consists of
d, e, f and g. Finally, the last scene consists of h, i, j, and k. The answer is
9, 7, 8 because a, b, and c, only appear in the first 9 characters, then d, e, f
, and g appear in the next 7. The final 8 characters consist entirely of h, i, j
, and k.


Example 2


Input:
inputList = [a,b,c]

Output:
[1,1,1]

Explanation:
Because there are no recurring shots, all shots can be in the minimal length 1
subsequence.

Example 3


Input:
inputList = [a,b,c,a]

Output:
[4]

Explanation:
Because 'a' appears more than once, everything between the first and last
appearance of 'a' must be in the same list.

**Helper Description**
[Darbin: Text here just says to the following structures.]

typedef struct BoundedArrayChar {
    int size;
    char *arr;
} charboundedarray;

typedef struct boundedarrayInt {
    int size;
    int* arr;
} boundedarray;



# Test Cases Tab


**Testcase 1:**
**Input:**
[a,b,c,d,a,e,f,g,h,i,j,e]

**Expected Return Value:**
5 7

**Testcase 2:**
**Input:**
[z,z,c,b,z,c,h,f,i,h,i]

**Expected Return Value:**
6 5

