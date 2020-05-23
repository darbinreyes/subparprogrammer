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

  if (upper.start > lower.end) {
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

  if (upper.start > lower.end) { // 1 > 3 // false
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

/*

All functions with "alloc" in their name return dynamically allocated objects.
The caller is responsible for calling free().

*/

// Duplicate the given boundedarray
boundedarray *alloc_dup_bounded_array(boundedarray *input) { // DELETE IF NOTE USED
  boundedarray *dup = NULL;

  assert(input != NULL);

  if (!(input != NULL)) {
    return NULL;
  }

  dup = calloc((size_t) 1, sizeof(boundedarray));

  if (dup == NULL) {
    return NULL;
  }

  dup->size = input->size;
  dup->arr = calloc((size_t) dup->size, sizeof(*(dup->arr)));

  for (int i = 0; i < dup->size; i++) {
    dup->arr[i] = input->arr[i];
  }

  return dup;
}

// Duplicate the given charboundedarray
charboundedarray *alloc_dup_char_bounded_array(charboundedarray *input) { // DELETE IF NOTE USED
  charboundedarray *dup = NULL;

  assert(input != NULL);

  if (!(input != NULL)) {
    return NULL;
  }

  dup = calloc((size_t) 1, sizeof(charboundedarray));

  if (dup == NULL) {
    return NULL;
  }

  dup->size = input->size;
  dup->arr = calloc((size_t) dup->size, sizeof(*(dup->arr)));

  for (int i = 0; i < dup->size; i++) {
    dup->arr[i] = input->arr[i];
  }

  return dup;
}

// Appends l to labels
void append_label(charboundedarray *labels, char l) {
  // TODO: Args check.
  labels->arr[labels->size] = l;
  labels->size++;
}


// Returns 1 if l does not occur in labels, 0 otherwise.
int is_unique_label(charboundedarray *labels, char l) {
  // TODO: Args check.

  for (int i = 0; i < labels->size; i++) {
    if (labels->arr[i] == l) {
      // l is not unique in labels
      return 0;
    }
  }

  return 1;
}

// Identifies all unique labels in input_list, returns them in an array.
charboundedarray *alloc_get_unique_labels(charboundedarray *input_list) {
  charboundedarray *unique_labels = NULL;

  assert(input_list != NULL && input_list > 0);

  if (!(input_list != NULL && input_list > 0)) {
    return NULL;
  }

  unique_labels = calloc(1, sizeof(*unique_labels));

  assert(unique_labels != NULL);

  if (!(unique_labels != NULL)) {
    return NULL;
  }

  /*

    At most, every element of input_list is a unique label, so allocate
    enough mem for input_list->size labels.

  */

  unique_labels->size = 0;
  unique_labels->arr = calloc(input_list->size, sizeof(*(unique_labels->arr)));

  /* Identify all unique labels in input_list, save them in unique_labels. */
  for (int i = 0; i < input_list->size; i++) {
    if (is_unique_label(unique_labels, input_list->arr[i])) {
      append_label(unique_labels, input_list->arr[i]);
    }
  }

  return unique_labels;
}

// Returns the index of the first occurrence of l in input_list.
int get_start_index(char l, charboundedarray *input_list) {
  // TODO: Args check.
  int i;

  for (i = 0; i < input_list->size; i++) {
    if (input_list->arr[i] == l) {
      return i;
    }
  }

  assert(0); // This function expects l to be in input_list

  return -1;
  // FYI: we could use memchr(cs,c,n) here.
}

// Returns the index of the last occurrence of l in input_list.
int get_end_index(char l, charboundedarray *input_list) {
  // TODO: Args check.
  int i, end, found;

  /*

    found is used to verify that at least 1 occurrence of l was found in input_list.

  */

  found = 0;
  end = 0;

  for (i = 0; i < input_list->size; i++) {
    if (input_list->arr[i] == l) {
      end = i;

      if (!found)
        found = 1;
    }
  }

  assert(found);

  return end;
}

// Stores information about a subsequence.
typedef struct _subsequence_table_entry {
  charboundedarray *labels; // Labels in this subsequence.
  int start; // Starting index of this subsequence.
  int end;   // Ending index of this subsequence.
  int len;   // end - start + 1
} subsequence_table_entry;

/*

  Returns an array of subsequence_table_entry's for each label in labels
  corresponding to input_list. The length of the returned array is equal to
  labels->size, upon return table_length is set to this value.

*/
subsequence_table_entry *alloc_get_subsequences(charboundedarray *labels, charboundedarray *input_list, int *table_length) {
  // TODO: Args check.
  subsequence_table_entry *subsequence_table = NULL;

  /*

  At most, every element of labels will correspond to a subsequence, so
  allocate labels->size subsequence_table_entry's.

  */

  subsequence_table = calloc(labels->size, sizeof(subsequence_table_entry));

  assert(subsequence_table != NULL);

  if (!(subsequence_table != NULL)) {
    return NULL;
  }

  // For each label


  for (int i = 0; i < labels->size; i++) {
    /*

      At most, a subsequence will contain label->size labels, so allocate that
      much mem for storing the labels that are part of the same sequence. To
      begin with, every subsequence contains a single label. Later, when we
      merge two subsequences, the resulting subsequence will contain more than
      one label.

    */
    subsequence_table[i].labels = calloc(1, sizeof(charboundedarray));

    assert(subsequence_table[i].labels != NULL);

    if (!(subsequence_table[i].labels != NULL)) {
      return NULL;
    }

    subsequence_table[i].labels->arr = calloc(labels->size, sizeof(*(labels->arr)));

    assert(subsequence_table[i].labels->arr != NULL);

    if (!(subsequence_table[i].labels->arr != NULL)) {
      return NULL;
    }

    subsequence_table[i].labels->arr[0] = labels->arr[i];
    subsequence_table[i].labels->size = 1;

    /*

      Get the starting index and ending index, save that info. in a
      subsequence_table_entry.

    */
    subsequence_table[i].start = get_start_index(labels->arr[i], input_list);
    subsequence_table[i].end = get_end_index(labels->arr[i], input_list);

    subsequence_table[i].len = subsequence_table[i].end - subsequence_table[i].start + 1;
  }

  *table_length = labels->size;
  return subsequence_table;
}

#define MAX(a, b) ( ( (a > b)? (a) : (b) ) )
#define MIN(a, b) ( ( (a < b)? (a) : (b) ) )

/*

  Returns a array of subsequence_table_entry's that result from merging the
  adjacent and overlapping subsequences occurring in subsequence table. Upon
  return merged_length will be set to the length of the merged table.

*/
subsequence_table_entry *alloc_merge_adjacent_overlapping_subsequences(subsequence_table_entry *subsequence_table, int table_length, int *merged_length) {
  // TODO: Args check.
  subsequence_table_entry *merged_table = NULL;
  int merged_table_length = 0;

  /*

    Since merging subsequences can only reduce the number of total subsequences
    at most we need mem for table_length merged subsequences.

  */
  merged_table = calloc(table_length, sizeof(*(merged_table)));

  for (int i = 0; i < table_length - 1; i++) {
    // If the current table entry overlaps with the next table entry, merge them.
    if (subsequence_table[i+1].start > subsequence_table[i].end) { // next_subsequence.start > current_subsequence.end
      // Don't overlap. Keep the current subsequence as is.
      merged_table[merged_table_length].labels = NULL; // TODO
      merged_table[merged_table_length].start = subsequence_table[i].start;
      merged_table[merged_table_length].end = subsequence_table[i].end;
      merged_table[merged_table_length].len = subsequence_table[i].len;
      merged_table_length++;
    } else {
      // Do overlap. Merge.

      merged_table[merged_table_length].labels = NULL; // TODO
      merged_table[merged_table_length].start = MIN(subsequence_table[i].start, subsequence_table[i + 1].start);
      merged_table[merged_table_length].end = MAX(subsequence_table[i].end, subsequence_table[i + 1].end); // TODO: I'm unsure now if max is necessary in the case that we can solve the problem by merging adjacent overlapping subsequences vs. merging overlapping sequences in order from largest subsequence length to smallest.
      merged_table[merged_table_length].len = merged_table[merged_table_length].end - merged_table[merged_table_length].start + 1;
      merged_table_length++;
    }
  }

  *merged_length = merged_table_length;

  return merged_table;
}

// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
boundedarray* lengthEachScene(charboundedarray* input_list)
{
  charboundedarray *unique_labels = NULL;
  subsequence_table_entry *subsequence_table = NULL;
  int table_length = 0;
  subsequence_table_entry *merged_table = NULL;
  int merged_length = 0;
  boundedarray *result = NULL;

  // WRITE YOUR CODE HERE
  assert(input_list != NULL);

  if (!(input_list != NULL)) {
    return NULL;
  }

  /*

    1. Compute an array containing each unique letter that occurs in input_list.
    2. Compute an array containing the start index of each letter corresponding to array #1.
    3. Same as #2 but for the end index.
    4. Same as #2 but for the subsequence length.
    5. Implement "Pseudo code for overlap test."

    Remark: Don't forget to use qsort(), if necessary. Don't forget to use
    max(). Don't forget you may need to handle subsequence lengths = 1 such
    that they are merged into left adjacent subsequences.

    IMPORTANT REMARK: #5 above can generate the subsequences out of order so as a
    final step you may need to sort the subsequences.

    Remark: The mem functions in string.h look like they might be very helpful.
    Remark: Once we compute the starting and ending indexes for each label we
    can focus on merging those index intervals in cases were they overlap, for
    , if there is overlap, and we do not merge, a label will certainly appear
    in more than one "scene"(a.k.a. subsequence).

  */

  unique_labels = alloc_get_unique_labels(input_list);
  subsequence_table = alloc_get_subsequences(unique_labels, input_list, &table_length);
  merged_table = alloc_merge_adjacent_overlapping_subsequences(subsequence_table, table_length, &merged_length);

  /*

    NEXT: Implement step #5 above. Can I get away with simply merging all
    overlapping and adjacent subsequences in the order in which they occur in
    the input? It is manifest that it would work for test_1 and test_2 and test_4.

  */

  // Finally, allocate and return the result.
  result = calloc(1, sizeof(*(result)));

  assert(result != NULL);

  if (!(result != NULL)) {
    return NULL;
  }

  result->size = merged_length;

  result->arr = calloc(result->size, sizeof(*(result->arr)));

  assert(result->arr != NULL);

  for (int i = 0; i < result->size; i++) {
    result->arr[i] = merged_table[i].len;
  }

  return result;
}
// FUNCTION SIGNATURE ENDS


/*

-------------------------- test_suite_one.c --------------------------
test_1                         Line 91    Expected 3 but was 2
test_2                         Line 108   Expected 1 but was 2
test_2                         Line 109   Expected 1 to be 4 at position 1
                           2 run  3 failed



============================ SEATEST v1.0 ============================

                                Failed
                             2 tests run
                               in 0 ms

======================================================================

*/