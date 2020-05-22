/*

  /\/\
 /- - \
 \ i  /
 /    \
/||  ||\_
\\\  ///))
 \\\/////
  UOOU//
      V

*/

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED

#include <stdlib.h> // calloc
#include <stdio.h> // NULL
#include "realq2.h"
#include <assert.h>

/*
******* Original Scratch work.

 cut films into scenes = take a video file, and break it up in smaller video files, break up at points in the video called scenes.
automate - breaking up - individual shots
individual shots = short video, from a particular camera angle.
break up _individual shots_ into _scenes_
scenes = a _sequence of shots_
given helper function - film.breakup_into_shots_and_letter_label().
duplicate shots get the same letter label.

todo - partition(sequence_of_labels) into scenes.
in a scene, no shot labels appear in more than 1 scene. ??? // I don't understand this.

Output scene.length for each scene.

******* Output

WTF is up with that struct def. its formated all wonKy!

Most of the work here is figuring out what the problem statement means.

*/

/*

******* Scratch Work

Film, broken up into shots and labeled.

Given - an array of letters - each letter is a label for a shot - same label = same shot.

Do - partition the array of labels into scenes, such no shot labels appear in more than one scene.

Output - length of each scene.

******** Input

An array of chars containing letters. Ostensibly all lower case, from the alphabet.

******* Output

Array of integers - each element = length of the corresponding scene.
In the order "in which it appears in the sequence of shots".

******* Example 1:
Input:
inputList=

{'a','b','a','b','c','b','a','c','a','d','e','f','e','g','d','e','h','i','j','h','k','l','i','j'}

[
0 a
1 b
2 a
3 b
4 c
5 b
6 a
7 c
8 a
9 d
10 e
11 f
12 e
13 g
14 d
15 e
16 h
17 i
18 j
19 h
20 k
21 l
22 i
23 j
] Remark: Length = 24.

Output:
[9,7,8]

Explanation:
1st scene - shots a b c.
2nd scene - shots d e f g.
3rd scene - shots h i j k.

9, 7, 8 because a b c only appear in the first 9 chars.
d e f g appear in the NEXT 7 chars.
last 8 chars consists entirely of h i j k.

Remark: The sum of the output array elements 9 + 7 + 8 = 16 + 8 = 24 = length of _inputList_.


******* Example 2:
Input:
inputList=
{'a','b','c'}
[
0 a
1 b
2 c
] Remark: Length = 3.

Output:
[1,1,1]

Explanation:
Because no shot label occurs more than once, all shots can be in a length 1 subsequence.

******* Example 3:
Input:
inputList=
{'a','b','c','a'}
[
0 a
1 b
2 c
3 a
] Remark: Length = 4.

Output:
[4]

Explanation:
'a' occurs more than once, everything between first and last appearance of 'a'
must be in the same subsequence.

*/

/*
******* Scratch Work

******* inputList =
  0   1   2   3
{'a','b','c','a'}
Can I compute the answer given first occurrence + last occurrence for each letter?
First we need to identify the individual letters that occur.

{a,b,c}  individual letters
{0,1,2}  first occurrence
{3,1,2}  last occurrence
{3,0,0}  last - first
{4,1,1}  last - first + 1 = sublen

Output:
[4]

******* inputList =
  0   1   2
{'a','b','c'}

{a,b,c}  individual letters
{0,1,2}  first occurrence
{0,1,2}  last occurrence
{0,0,0}  last - first
{1,1,1}  last - first + 1 = sublen

Output:
[1,1,1]

******* inputList =
  0   1   2   3   4   5   6   7   8   9   10
{'a','b','a','b','c','b','a','c','a','d','e',

 11  12  13  14  15  16  17  18  19  20  21  22  23
'f','e','g','d','e','h','i','j','h','k','l','i','j'}

{a,b,c,d,e, f, g, h, i, j, k, l}   individual letters
{0,1,4,9,10,11,13,16,17,18,20,21}  first occurrence

{a,b,c,d, e, f, g, h, i, j, k, l}  individual letters
{8,5,7,14,15,11,13,19,22,23,20,21} last occurrence

{8,4,3,5 ,5, 0, 0, 3, 5, 5, 0, 0} last occurrence minus first occurrence. Where this array == 0, we need not worry about the letter occurring more than once.

d = l - f // diff = last - first

f + d = l // first + diff = last

d + 1 = length of subsequence containing all occurrence of a letter.
d + 1 // diff + 1 = sublen

{9,5,4,6 ,6, 1, 1, 4, 6, 6, 1, 1} // sublen = last occurrence minus first occurrence + 1.

IMPORTANT REMARK: With respect to the above array, we may need to worry about
handling the case of subsequence length (sublen) = 1 in a special way, e.g. when
we are processing subsequences of length = 1, and if that subsequence has a
subsequence adjacent to its left (lower index), the length 1 subsequence should
be merged with the subsequence adjacent to its left.

Output:
[9,7,8]

"because a b c only appear in the first 9 chars, d e f g appear in the NEXT 7
chars, and the last 8 chars consists entirely of h i j k"
*/

/*
******* Observations, and attempt to develop a first draft argument.

  Considering

  inputList =
  0   1   2   3   4   5   6   7   8   9   10
  {'a','b','a','b','c','b','a','c','a','d','e',

  11  12  13  14  15  16  17  18  19  20  21  22  23
  'f','e','g','d','e','h','i','j','h','k','l','i','j'}

  {9,5,4,6 ,6, 1, 1, 4, 6, 6, 1, 1} Copied from above. sublen = last occurrence minus first occurrence + 1.

  The sum of the output array == length of _inputList_.
  Any adjacent letters that occur only once (l - f == 0) can be grouped into the same scene. See "IMPORTANT REMARK" above.

  Let us consider the largest subsequence, max(sublen)
' a' letter
  9  sublen
  0  first
  8  last

  Let us do the obvious, create a subset
  starting at a.first == 0
  ending at a.last == 8
  a.sublen == 9.

  The next largest subsequence is 6
  (note there is more than one letter with this subsequence
  length) let us take the first, which is 'd'.
  'd' // letter
  6  // sublen
  9  // first
  14 // last
  Remark, we may need to sort so that we process subsequence length in decreasing order, with ties in the length resolved by lower index processed first.

  Let us now say that we will merge the current subsequence with the previous subsequence if there is any overlap.

  Pseudo code for overlap test.

  struct {
    char Letters[26];
    int NumLetters;
    int Start;
    int End;
  }

  prev_subsequence
  current_subsequence

  if prev_subsequence.first <= current_subsequence.first
    lower_subsequence = prev_subsequence
    upper_subsequence = current_subsequence
  else
    lower_subsequence = current_subsequence
    upper_subsequence = prev_subsequence

  lower_subsequence is the subsequence that starts at the lesser index.
  upper_subsequence is the subsequence that starts at the greater index.

  Note all subsequences have length >= 1

  In what ways can the sequences can overlap?

  1. They are the same.
    lower.start == upper.start && lower.end == upper.end

    *---*
    *---*

  2. Partial overlap.
    upper.start > lower.start && upper.start < lower.end

  *---*
    *---*

  3. Single point overlap.
    *---*
        *---*

  4. No overlap.
    *---*
            *---*

  It is manifest that they certainly don't overlap if
  (i.e. the above 4 cases can be reduced to the if statement below.)

  if(upper.start > lower.end) {
    // No overlap.
    // Let this be a new subsequence.
    new_subsequence.start = current_subsequence.start
    new_subsequence.end = current_subsequence.end
    subsequences.append(new_subsequence)
  }
  else {
    // Yes overlap.
    // Merge upper and lower into a single subsequence. No new sequence is created but an existing subsequence is enlarged.
    prev_subsequence.start = lower.start
    prev_subsequence.end = MAX(upper.end, lower.end) IMPORTANT REMARK: MAX() is essential here!
  }

  Move on to the next largest subsequence and repeat above until every subsequence
  length has been processed. See also "IMPORTANT REMARK" regarding processing
  subsequence length = 1.

  By inspection, this solves Example 2.

*/

/*
******* Scratch Work

  Does above draft algorithm work on this input?

  inputList =
    0   1   2   3
  {'a','b','c','a'}

  Can I compute the answer given first occurrence + last occurrence for each letter.
  First we need to identify the individual letters that occur.

  {a,b,c}  individual letters
  {0,1,2}  first occurrence
  {3,1,2}  last occurrence
  {3,0,0}  last - first
  {4,1,1}  last - first + 1 = sublen

  Output:
  [4]

******* Analysis of above test case.

  Largest subsequence length = 4, corresponding to letter 'a'.
  subsequences = []
  prev_subsequence = NULL.
  current_subsequence.start = first['a'] = 0
  current_subsequence.end = last['a'] = 3

  subsequences.append(current_subsequence)
  prev_subsequence = current_subsequence

  current_subsequence = next largest subsequence length, resolving duplicates by lower index. In this case 'b'.
  current_subsequence.start = first['b'] = 1
  current_subsequence.end = last['b'] = 1

  if prev_subsequence.first <= current_subsequence.first // 0 <= 1 // true
    lower = prev_subsequence , 0, 3
    upper = current_subsequence , 1, 1

  if(upper.start > lower.end) { // 1 > 3 // false
    // No overlap
  else
    // Yes overlap.
    // Merge upper and lower.
    prev_subsequence.start = lower.start = 0
    prev_subsequence.end = max(upper.end, lower.end) = max(1, 3) = 3 // !!! max is essential here.

  current_subsequence = next largest subsequence length, resolving duplicates by lower index. In this case 'c'.
  current_subsequence.start = first['c'] = 2
  current_subsequence.end = last['c'] = 2

  if prev_subsequence.first <= current_subsequence.first // "first:=start" // 0 <= 2 // true
    lower = prev_subsequence , 0, 3
    upper = current_subsequence , 2, 2

  if(upper.start > lower.end) { // 2 > 3 // false
    // No overlap.
  else
    // Yes overlap.
    // merge upper and lower
    prev_subsequence.start = lower.start = 0
    prev_subsequence.end = max(upper.end, lower.end) = max(2, 3) = 3

  DONE!
  And we have terminated with subsequences = [{0,3}] which we can transform
  into the desired output format by converting the range into a length

  output = []
  for subsequence in subsequences
    output.append(subsequence.end - subsequence.start + 1)

  assert length of _inputList_ = sum of output array elements.

  return output; // Above assert. As an extra correctness check note that sum([4]) == len(inputList) == len({'a','b','c','a'}) == 4.

  Remark: My intuition tells me that  at most there will not be more
  subsequences than there are unique letters. Therefore the list of subsequences
  can be allocated to this size. Can I prove this?

*/

// Duplicate the given boundedarray
boundedarray *AllocDupBoundedArray(boundedarray *Input) {
  boundedarray *Dup = NULL;

  assert(Input != NULL);

  if(!(Input != NULL)) {
    return NULL;
  }

  Dup = calloc((size_t) 1, sizeof(boundedarray));

  if(Dup == NULL) {
    return NULL;
  }

  Dup->size = Input->size;
  Dup->arr = calloc((size_t) Dup->size, sizeof(*(Dup->arr)));

  for(int Index = 0; Index < Dup->size; Index++) {
    Dup->arr[Index] = Input->arr[Index];
  }

  return Dup;
}

// Duplicate the given charboundedarray
charboundedarray *AllocDupCharBoundedArray(charboundedarray *Input) {
  charboundedarray *Dup = NULL;

  assert(Input != NULL);

  if(!(Input != NULL)) {
    return NULL;
  }

  Dup = calloc((size_t) 1, sizeof(charboundedarray));

  if(Dup == NULL) {
    return NULL;
  }

  Dup->size = Input->size;
  Dup->arr = calloc((size_t) Dup->size, sizeof(*(Dup->arr)));

  for(int Index = 0; Index < Dup->size; Index++) {
    Dup->arr[Index] = Input->arr[Index];
  }

  return Dup;
}



// Returns inputList after removing all duplicate labels.
charboundedarray *AllocUniqueLabelsArray(charboundedarray *inputList) {

#define LABEL_IS_DUPLICATE 0

  charboundedarray *inputListDup = NULL;
  char CurrentLabel  = LABEL_IS_DUPLICATE;
  int NumUniqueLabels = 0;
  charboundedarray *Result = NULL;

  assert(inputList != NULL);

  if(!(inputList != NULL)) {
    return NULL;
  }

  inputListDup = AllocDupCharBoundedArray(inputList);

  assert(inputListDup != NULL);

  if(!(inputListDup != NULL)) {
    return NULL;
  }

  // Mark all duplicate labels with LABEL_IS_DUPLICATE so that the resulting array contains only a single occurrence of each label.
  for(int Index = 0; Index < inputListDup->size; Index++) {
    CurrentLabel = inputListDup->arr[Index];
    for(int Index2 = Index; Index2 < inputListDup->size; Index2++) {
      if(Index2 > Index && inputListDup->arr[Index2] == CurrentLabel) {
        inputListDup->arr[Index2] = LABEL_IS_DUPLICATE;
      }
    }
  }

  // Determine the number of unique labels.
  for(int Index = 0; Index < inputListDup->size; Index++) {
    if(inputListDup->arr[Index] != LABEL_IS_DUPLICATE) {
      NumUniqueLabels++;
    }
  }

  Result = calloc((size_t) 1, sizeof(*Result));

  Result->size = NumUniqueLabels;
  Result->arr = calloc((size_t) Result->size, sizeof(*(Result->arr)));

  // Copy the unique labels to the result array.
  int Index2 = 0;
  for(int Index = 0; Index < inputListDup->size; Index++) {
    if(inputListDup->arr[Index] != LABEL_IS_DUPLICATE) {
      Result->arr[Index2] = inputListDup->arr[Index];
      Index2++;
    }
  }

  return Result;
}

boundedarray *AllocLabelStartIndex(charboundedarray *UniqueLabels, charboundedarray *inputList) {
  boundedarray *Result = NULL;
  // TODO: Validate args.

  Result = calloc((size_t) 1, sizeof(boundedarray));

  if(Result == NULL) {
    return NULL;
  }

  Result->size = UniqueLabels->size;
  Result->arr = calloc((size_t) Result->size, sizeof(*(Result->arr)));

  for(int Index = 0; Index < UniqueLabels->size; Index++){
    for(int Index2 = 0; Index2 < inputList->size; Index2++) {
      if(UniqueLabels->arr[Index] == inputList->arr[Index2]) {
        Result->arr[Index] = Index2;
        break;
      }
    }
  }

  return Result;
}

boundedarray *AllocLabelEndIndex(charboundedarray *UniqueLabels, charboundedarray *inputList) {
  boundedarray *Result = NULL;
  // TODO: Validate args.

  Result = calloc((size_t) 1, sizeof(boundedarray));

  if(Result == NULL) {
    return NULL;
  }

  Result->size = UniqueLabels->size;
  Result->arr = calloc((size_t) Result->size, sizeof(*(Result->arr)));

  for(int Index = 0; Index < UniqueLabels->size; Index++){
    for(int Index2 = 0; Index2 < inputList->size; Index2++) {
      if(UniqueLabels->arr[Index] == inputList->arr[Index2]) {
        Result->arr[Index] = Index2;
      }
    }
  }

  return Result;
}

boundedarray *AllocSubsequenceLength(boundedarray *UniqueLabelsStart, boundedarray *UniqueLabelsEnd) {
  boundedarray *Result = NULL;
  // TODO: Validate args.
  Result = calloc((size_t) 1, sizeof(boundedarray));

  if(Result == NULL) {
    return NULL;
  }

  Result->size = UniqueLabelsStart->size;
  Result->arr = calloc((size_t) Result->size, sizeof(*(Result->arr)));

  for(int Index = 0; Index < UniqueLabelsStart->size; Index++){
    Result->arr[Index] = UniqueLabelsEnd->arr[Index] - UniqueLabelsStart->arr[Index] + 1;
  }

  return Result;

}
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
boundedarray* lengthEachScene(charboundedarray* inputList)
{
    charboundedarray *UniqueLabels = NULL;
    boundedarray *UniqueLabelsStart = NULL;
    boundedarray *UniqueLabelsEnd = NULL;
    boundedarray *SubsequenceLength = NULL;
    // WRITE YOUR CODE HERE
    assert(inputList != NULL);

    if(!(inputList != NULL)) {
      return NULL;
    }

    /*
      1. Compute an array containing each unique letter that occurs in inputList.
      2. Compute an array containing the start index of each letter corresponding to array #1.
      3. Same as #2 but for the end index.
      4. Same as #2 but for the subsequence length.
      5. Implement "Pseudo code for overlap test."

      Remark: Don't forget to use qsort(), if necessary. Don't forget to use
      max(). Don't forget you may need to handle subsequence lengths = 1 such
      that they are merged into left adjacent subsequences.

    */

      UniqueLabels = AllocUniqueLabelsArray(inputList);
      UniqueLabelsStart = AllocLabelStartIndex(UniqueLabels, inputList);
      UniqueLabelsEnd = AllocLabelEndIndex(UniqueLabels, inputList);
      SubsequenceLength = AllocSubsequenceLength(UniqueLabelsStart, UniqueLabelsEnd);
    // Finally, allocate and return the result.

    return NULL;
}
// FUNCTION SIGNATURE ENDS