/*
  See README.md.

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

All functions with "alloc" in their name return dynamically allocated objects.
The caller is responsible for calling free().

*/

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

// Free memory allocated by alloc_get_unique_labels().
void free_get_unique_labels(charboundedarray *unique_labels) {
  assert(unique_labels != NULL);

  if (!(unique_labels != NULL)) {
    return;
  }

  free(unique_labels->arr);
  free(unique_labels);
}

// Returns the index of the first occurrence of l in input_list.
int get_start_index(char l, charboundedarray *input_list) { // Using memchr() might be more efficient.
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
  int len;   // End - start + 1.
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

  // For each label.
  for (int i = 0; i < labels->size; i++) {
    /*

      At most, a subsequence will contain label->size labels, so allocate that
      much mem for storing the labels that are part of the same sequence. To
      begin with, every subsequence contains a single label. Later, when we
      merge two subsequences, the resulting subsequence will contain more than
      one label.

      FYI: Storing the labels is not necessary, but it is nice to have for debugging.

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

// Free memory allocated by alloc_get_subsequences().
void free_get_subsequences(subsequence_table_entry *subsequence_table, int table_length) {

  assert(subsequence_table != NULL);
  if (!(subsequence_table != NULL)) {
    return;
  }

  for (int i = 0; i < table_length; i++) {
    free(subsequence_table[i].labels->arr);
    free(subsequence_table[i].labels);
  }

  free(subsequence_table);
}

/*

  Returns an array of subsequence_table_entry's that result from merging the
  adjacent and overlapping subsequences occurring in subsequence_table. Upon
  return merged_length will be set to the length of the merged table.

*/
subsequence_table_entry *alloc_merge_adjacent_overlapping_subsequences(subsequence_table_entry *subsequence_table, int table_length, int *merged_length) {
  // TODO: Args check.
  subsequence_table_entry *merged_table = NULL;
  subsequence_table_entry *prev_subsequence = NULL;
  int merged_table_length = 0;

  /*

    Since merging subsequences can only reduce the number of total subsequences,
    at most we need mem for table_length merged subsequences.

  */
  merged_table = calloc(table_length, sizeof(*(merged_table)));
  // Take the first subsequence as is.
  merged_table[merged_table_length].labels = NULL; // TODO. Nice to have.
  merged_table[merged_table_length].start = subsequence_table[0].start;
  merged_table[merged_table_length].end = subsequence_table[0].end;
  merged_table[merged_table_length].len = subsequence_table[0].len;
  merged_table_length++;
  prev_subsequence = &(merged_table[0]);

  for (int i = 1; i < table_length; i++) {
    // If the current table entry overlaps with the previous table entry, merge them.
    if (subsequence_table[i].start > prev_subsequence->end) { // current_subsequence.start > prev_subsequence.end
      // Don't overlap. Keep the current subsequence as is.
      merged_table[merged_table_length].labels = NULL; // TODO. Nice to have.
      merged_table[merged_table_length].start = subsequence_table[i].start;
      merged_table[merged_table_length].end = subsequence_table[i].end;
      merged_table[merged_table_length].len = subsequence_table[i].len;
      merged_table_length++;
      prev_subsequence++;
    } else {
      // Do overlap. Merge. merged_table_length does NOT need to be incremented.
      prev_subsequence->labels = NULL; // TODO. Append label.
      prev_subsequence->start = MIN(prev_subsequence->start, subsequence_table[i].start); // TODO. Are MIN/MAX really needed? Seems like no.
      prev_subsequence->end = MAX(prev_subsequence->end, subsequence_table[i].end);
      prev_subsequence->len = prev_subsequence->end - prev_subsequence->start + 1;
    }
  }

  *merged_length = merged_table_length;

  return merged_table;
}

// Free memory allocated by alloc_merge_adjacent_overlapping_subsequences().
void free_merge_adjacent_overlapping_subsequences(subsequence_table_entry *merged_table, int merged_length) {
  assert(merged_table != 0);

  if (!(merged_table != 0)) {
    return;
  }

  free(merged_table);
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
    2. Compute an array containing the start/end index of each letter corresponding to array #1.
    3. Implement merge overlapping subsequences test.

    Remark: The mem functions in string.h look like they might be very helpful.

    Remark: Once we compute the starting and ending indexes for each label we
    can focus on merging those index intervals in cases were they overlap, for
    , if there is overlap, and we do not merge, a label will certainly appear
    in more than one "scene"(a.k.a. subsequence).

  */

  unique_labels = alloc_get_unique_labels(input_list);
  subsequence_table = alloc_get_subsequences(unique_labels, input_list, &table_length);
  merged_table = alloc_merge_adjacent_overlapping_subsequences(subsequence_table, table_length, &merged_length);


  // Finally, allocate and return the result.
  result = calloc(1, sizeof(*(result)));

  assert(result != NULL);

  if (!(result != NULL)) {
    return NULL;
  }

  result->size = 0;

  result->arr = calloc(merged_length, sizeof(*(result->arr)));

  assert(result->arr != NULL);

  if (!(result->arr != NULL)) {
    return NULL;
  }

  for (int i = 0; i < merged_length; i++) {
    result->arr[result->size] = merged_table[i].len;
    result->size++;
  }

  // TODO: Add calls to free().
  free_get_unique_labels(unique_labels);
  free_get_subsequences(subsequence_table, table_length);
  free_merge_adjacent_overlapping_subsequences(merged_table, merged_length);
  return result;
}
// FUNCTION SIGNATURE ENDS