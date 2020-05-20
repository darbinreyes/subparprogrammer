// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <stdlib.h> // malloc / qsort
#include <string.h> // strstr
#include <ctype.h> // tolower etc.
#include "realq1.h"

/*
***** Scratch work

List of quotes, about toys, from online articles. From Web crawler.

Which toys are mentioned most frequently.

Identify top N toys.Given list of quotes and list of toys.

Output - top N toys.

// Should be similar to a word count program.
*** Input
numToys = length of list of toys to count the freq of.
topToys = length of the top list e.g. top 100 songs on Itunes.
toys = list of strings = name of the toys whose freq we are computing.
numQuotes = length of the list of quotes to inspect for toy names.
quotes = list of strings = quotes.

*** Output

list of strings, length topToys, ordered 0-most to N-1-least freq.

*** other info.

str cmp should be case insensitive. // use strcmp() + tolower()
in a single quote - if "train" occurs 10 times - it only increases the count of "train" by 1.

if(topToys > numToys) return ? - exclude from returned list any toy names with freq = 0; ??

if 2 toys have an equal freq. count their order in the returned list should be determined alphabetically. // hopefully I can include qsort.

*** Example

length of returned list == _topToys_
_toys_ is a list of strings of length == _numToys_
_quotes_ is a list of strings of length == _numQuotes_.


*** Helper Description

// The given return struct

boundedStringArray *result; // malloc this
result->size = topToys;// beware of the "return ?" note above.
result->arr = computed_array_of_strings_in_freq_alpha_order;

*/

void LowerCaseStrArray(char **StrArray, int Length) {
    int Index, StrCharIndex, StrLen;
    // TODO Handle invalid args like StrArray == NULL
    for(Index = 0; Index < Length; Index++) {
        StrLen = strlen(StrArray[Index]);
        for(StrCharIndex = 0; StrCharIndex < StrLen; StrCharIndex++) {
            if(isupper(StrArray[Index][StrCharIndex])) {
                StrArray[Index][StrCharIndex] = tolower(StrArray[Index][StrCharIndex]);
            }
        }
    }
    return;
}

// Returns 1 if string _toy_ occurs in string _quote_. 0 otherwise.
int QuoteContainsToy (char *Quote, char *Toy) {
    // TODO: Handle invalid args.
    if(strstr(Quote, Toy) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

typedef struct _FreqTableEntry {
    int Freq;
    char *ToyName;
} FreqTableEntry;

/* Snippets from the man page for qsort.
The qsort() and heapsort() functions sort an array of __nel objects__, the
     __initial member__ of which is pointed to by base.  The __size of each object__
     is specified by width.

The contents of the array base are sorted in __ascending order__ according to
     a comparison function pointed to by compar, which requires two arguments
     pointing to the objects being compared.

The comparison function must return an integer less than, equal to, or
     greater than zero if the __first argument__ is considered to be respectively
     less than, equal to, or greater than the second.


 The qsort_r() function behaves identically to qsort(), except that it
     takes an ___additional argument, thunk,___ which is passed unchanged as the
     first argument to function pointed to compar.  This allows the comparison
     function to access additional data without using global variables, and
     thus qsort_r() is suitable for use in functions which must be reentrant.

The algorithms implemented by qsort(), qsort_r(), and heapsort() are not
     stable; that is, if two members __compare as equal__, their order in the
     sorted array is __undefined__.

//void     qsort(void *base, size_t nel, size_t width,
//         int (*compar)(const void *, const void *));

*/



int FreqTableEntryCmp(const void *ta, const void *tb) {
    int result;
    const FreqTableEntry *a, *b;
    a = (const FreqTableEntry *) ta;
    b = (const FreqTableEntry *) tb;
    // TODO: Handle invalid args.
    result = a->Freq - b->Freq; // Positive if a > b, 0 if a == b, negative if a < b.

    result = result * -1; // The default behavior of qsort produces an ascending order, this will reverse that.

    return result;
}

int FreqTableEntryCmpAlpha(const void *ta, const void *tb) {
    int result;
    const FreqTableEntry *a, *b;
    a = (const FreqTableEntry *) ta;
    b = (const FreqTableEntry *) tb;
    // TODO: Handle invalid args.
    result = strcmp(a->ToyName, b->ToyName); // Positive if a > b, 0 if a == b, negative if a < b.

    return result;
}

/* Snippets from the man page for strcmp

The strcmp() and strncmp() functions return an integer greater than,
     equal to, or less than 0, according as the string s1 is greater than,
     equal to, or less than the string s2.  The comparison is done using
     unsigned characters, so that `\200' is greater than `\0'.

// int strcmp(const char *s1, const char *s2);

s1="a"
s2="z"

should return less than 0.

*/

// Alphabetically sort the elements of FreqTableSorted in the range StartIndex to EndIndex, inclusive.
void AlphabeticallySortSubset(int StartIndex, int EndIndex, FreqTableEntry **FreqTableSorted) {
    int NumEqual;
    // TODO: Handle invalid args.
    NumEqual = EndIndex - StartIndex;

    if(NumEqual <= 1) { // Nothing to sort.
        return;
    }

    qsort((void *)&FreqTableSorted[StartIndex], (size_t)NumEqual, sizeof(*FreqTableSorted), FreqTableEntryCmpAlpha);
}

// Identifies the elements in FreqTableSorted that have equal frequency counts and sorts those elements alphabetically.
void AlphabeticallySortEqualFreq(int numToys, FreqTableEntry **FreqTableSorted) {
    int StartIndex, EndIndex;

    // TODO: Handle invalid args.

    StartIndex = 0;
    EndIndex = 0;

    while(EndIndex < numToys) {

        while(EndIndex < numToys && FreqTableSorted[StartIndex]->Freq == FreqTableSorted[EndIndex]->Freq) {
            EndIndex++;
        }
        // EndIndex should point to the first element whose frequency differs from the previous element
        AlphabeticallySortSubset(StartIndex, EndIndex, FreqTableSorted);
        StartIndex = EndIndex;
        //EndIndex = StartIndex;
    }

}

boundedStringArray *dup_boundedStringArray(boundedStringArray *s) {
    boundedStringArray *t;
    // TODO: Handle invalid args.
    t = calloc((size_t)1, sizeof(*s));
    if(t == NULL) {
        // calloc error.
        return NULL;
    }

    t->size = s->size;
    t->arr = calloc((size_t)t->size, sizeof(*(t->arr)));
    for(int i = 0; i < t->size; i++) {
        t->arr[i] = strdup(s->arr[i]);
    }
    return t;
}
boundedStringArray* popularNToys(int numToys, int topToys,
                                    boundedStringArray* toys,
                                    int numQuotes,
                                    boundedStringArray* quotes)
{
    // WRITE YOUR CODE HERE
    boundedStringArray *Result, *toysdup, *quotesdup;
    FreqTableEntry *FreqTable;
    FreqTableEntry **FreqTableSorted;
    int QuotesIndex, ToysIndex, Index;

    toysdup = dup_boundedStringArray(toys); // Duplicate the arrays because we will need to lower case them.
    quotesdup = dup_boundedStringArray(quotes);

    // TODO: Handle invalid args like toys == NULL

    /*
    *** Scratch work.

    Consider the case of a single toy "train". Let us determine
    the freq count of "train" in quotes.

    First, lower case the toys array and the quotes array. I assume touching the input arrays is OK but I could copy them if not.
    Helper function - void LowerCaseStrArray(char **StrArray...); // Coverts all alphabetic chars in StrArray to lower case.

    // Great, now don't need to worry about the case-sensitivity of our freq count for toy = "train"

    Lets consider the quote "This train is so cool. The train makes choo choo sounds."
    "train" occurs twice but the freq count = 1, since we don't count the same toy within a single quote more than once.

    Well, we need a place to store our freq counts as we go along.
    */

    FreqTable = calloc((size_t)numToys, sizeof(*FreqTable)); // calloc 0's the mem.
    if(FreqTable == NULL) {
        // calloc error.
        return NULL;
    }

    FreqTableSorted = calloc((size_t)numToys, sizeof(*FreqTableSorted));
    if(FreqTableSorted == NULL) {
        // calloc error.
        return NULL;
    }

    // Lower the _toys_ array of strings.

    LowerCaseStrArray(toysdup->arr, toysdup->size);

    // Lower the _quotes_ array of strings
    LowerCaseStrArray(quotesdup->arr, quotesdup->size);

    // for every toy name
    for (ToysIndex = 0; ToysIndex < numToys; ToysIndex++){
        FreqTable[ToysIndex].ToyName = toysdup->arr[ToysIndex]; // Current toy whose freq is being computed.
        // for every quote
        for(QuotesIndex = 0; QuotesIndex < numQuotes; QuotesIndex++) {
            FreqTable[ToysIndex].Freq += QuoteContainsToy (quotesdup->arr[QuotesIndex], FreqTable[ToysIndex].ToyName);
        }
        FreqTableSorted[ToysIndex] = &FreqTable[ToysIndex];
    }

    // De-erroring progress. At this point, the contents of FreqTable[0-5] are correct.
    // De-erroring progress. What about FreqTableSorted[0-5]? ANS: Yes.
    /*
      At this point FreqTable[ should store the freq count of each toy name
      Now we need to sort it by freq, then resolve ties by alphabetic order.
    */

    // call qsort,

//void     qsort(void *base, size_t nel, size_t width,
//         int (*compar)(const void *, const void *));

    qsort((void *)FreqTableSorted, (size_t)numToys, sizeof(*FreqTableSorted), FreqTableEntryCmp);

    // De-erroring progress. Discovered the FreqTableSorted is not correct after above call. Why?

    // call qsort again, handle ties.

    /*

    Given the starting index and the ending index of toys having equal frequency
    call qsort on that subset of the frequency table.
    Does the problem specify if alphabetic order means a-z or z-a? ANS: No.
    I will assume a-z order.
    numToys = 8
    0 1 2 3 4 5 6 7
    9 9 9 7 7 7 1 1

    StartIndex 0
    EndIndex 3
    NumEqual = EndIndex - StartIndex = 3
    qsort((void *)&FreqTableSorted[StartIndex], (size_t)NumEqual, sizeof(*FreqTableSorted), FreqTableEntryCmpAlpha);

    StartIndex = EndIndex = 3
    EndIndex = StartIndex = 3
    while (EndIndex < numToys && FreqTableSorted[StartIndex]->Freq == FreqTableSorted[EndIndex]->Freq) EndIndex++;
    EndIndex = 4
    EndIndex = 5
    EndIndex = 6
    NumEqual = EndIndex - StartIndex = 6 - 3 = 3

    qsort

    StartIndex = EndIndex = 6
    EndIndex = StartIndex = 6
    while ....
    EndIndex = 7 // if( EndIndex + 1 == numToys)
    NumEqual = EndIndex - StartIndex + 1;
    qsort((void *)&FreqTableSorted[StartIndex], (size_t)NumEqual, sizeof(*FreqTableSorted), FreqTableEntryCmpAlpha);

    */

    AlphabeticallySortEqualFreq(numToys, FreqTableSorted);

    // return result.

    Result = calloc((size_t)1, sizeof(*Result));

    if(Result == NULL) {
        // calloc error.
        return NULL;
    }

    if(topToys > numToys) { // The problem description on this case is unclear to me.
        topToys = numToys; // It may mean, at most numToys, but possibly less if some toys have a freq count of 0.
    }

    Result->size = topToys;
    Result->arr = calloc((size_t)topToys, sizeof(*(Result->arr)));

    for(Index = 0; Index < topToys; Index++) {
        Result->arr[Index] = FreqTableSorted[Index]->ToyName;
    }

    return Result;
}
// FUNCTION SIGNATURE ENDS