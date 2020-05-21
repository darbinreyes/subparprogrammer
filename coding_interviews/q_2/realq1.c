// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <stdlib.h> // malloc / qsort
#include <string.h> // strstr
#include <ctype.h> // tolower etc.
#include "realq1.h"
#include <assert.h>

/*
******* Scratch work

List of quotes, about toys, from online articles. From Web crawler.

Which toys are mentioned most frequently.

Identify top N toys.Given list of quotes and list of toys.

Output - top N toys.

// Should be similar to a word count program.
************** Input
numToys = length of list of toys to count the freq of.
topToys = length of the top list e.g. top 100 songs on Itunes.
toys = list of strings = name of the toys whose freq we are computing.
numQuotes = length of the list of quotes to inspect for toy names.
quotes = list of strings = quotes.

************** Output

list of strings, length topToys, ordered 0-most to N-1-least freq.

************** other info.

str cmp should be case insensitive. // use strcmp() + tolower()
in a single quote - if "train" occurs 10 times - it only increases the count of "train" by 1.

if(topToys > numToys) return ? - exclude from returned list any toy names with freq = 0; ??

if 2 toys have an equal freq. count their order in the returned list should be determined alphabetically. // hopefully I can include qsort.

************** Example

length of returned list == _topToys_
_toys_ is a list of strings of length == _numToys_
_quotes_ is a list of strings of length == _numQuotes_.


************** Helper Description

// The given return struct

boundedStringArray *result; // malloc this
result->size = topToys;// beware of the "return ?" note above.
result->arr = computed_array_of_strings_in_freq_alpha_order;

*/

// Lower case the given string array.
void LowerCaseStrArray(char **StrArray, int Length) {
    int Index, StrCharIndex, StrLen;

    assert(StrArray != NULL && Length > 0);

    if(StrArray == NULL || Length <= 0) {
        return;
    }

    for(Index = 0; Index < Length; Index++) {
        assert(StrArray[Index] != NULL);

        if(StrArray[Index] == NULL) {
            continue;
        }

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
    assert(Quote != NULL && Toy != NULL);

    if(Quote == NULL || Toy == NULL) {
        return -1;
    }

    if(strstr(Quote, Toy) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Struct to hold the name and frequency of toy names.
typedef struct _FreqTableEntry {
    int Freq; // Frequency of ToyName.
    char *ToyName; // The name of the toy.
} FreqTableEntry;

// Comparison function for qsort(). Compares frequency. Descending order.
int FreqTableEntryCmp(const void *ta, const void *tb) {
    int result;
    const FreqTableEntry **a, **b;

    assert(ta != NULL && tb != NULL);

    if(ta == NULL || tb == NULL) {
        return 0;
    }

    a = (const FreqTableEntry **) ta;
    b = (const FreqTableEntry **) tb;

    result = (*a)->Freq - (*b)->Freq; // Positive if a > b, 0 if a == b, negative if a < b.

    result = result * -1; // The default behavior of qsort produces an ascending order, this will reverse that.

    return result;
}

// Comparison function for qsort(). Compares alphabetically. Ascending order.
int FreqTableEntryCmpAlpha(const void *ta, const void *tb) {
    int result;
    const FreqTableEntry **a, **b;

    assert(ta != NULL && tb != NULL);

    if(ta == NULL || tb == NULL) {
        return 0;
    }

    a = (const FreqTableEntry **) ta;
    b = (const FreqTableEntry **) tb;

    result = strcmp((*a)->ToyName, (*b)->ToyName); // Positive if a > b, 0 if a == b, negative if a < b.

    return result;
}

// Alphabetically sort the elements of FreqTableSorted in the range StartIndex to EndIndex, inclusive.
void AlphabeticallySortSubset(int StartIndex, int EndIndex, FreqTableEntry **FreqTableSorted) {
    int NumEqual;

    assert(StartIndex >= 0 && EndIndex >= 0 && FreqTableSorted != NULL);

    if(!(StartIndex >= 0 && EndIndex >= 0 && FreqTableSorted != NULL)) {
        return;
    }

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
    assert(numToys >= 0 && FreqTableSorted != NULL);

    if(!(numToys >= 0 && FreqTableSorted != NULL)) {
        return;
    }

    StartIndex = 0;
    EndIndex = 0;

    while(EndIndex < numToys) {

        while(EndIndex < numToys && FreqTableSorted[StartIndex]->Freq == FreqTableSorted[EndIndex]->Freq) {
            EndIndex++;
        }
        // EndIndex should point to the first element whose frequency differs from the previous element
        AlphabeticallySortSubset(StartIndex, EndIndex, FreqTableSorted);
        StartIndex = EndIndex;
    }

}

boundedStringArray *dup_boundedStringArray(boundedStringArray *s) {
    boundedStringArray *t;

    assert(s != NULL);
    if(!(s != NULL)) {
        return NULL;
    }

    t = calloc((size_t)1, sizeof(*s));
    if(t == NULL) {
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

    assert(numToys > 0 && topToys > 0 && toys != NULL && numQuotes > 0 && quotes != NULL);
    if(!(numToys > 0 && topToys > 0 && toys != NULL && numQuotes > 0 && quotes != NULL)) {
        return NULL;
    }

    toysdup = dup_boundedStringArray(toys); // Duplicate the arrays because we will need to lower case them.
    quotesdup = dup_boundedStringArray(quotes);

    /*
    ************** Scratch work.

    Consider the case of a single toy "train". Let us determine
    the freq count of "train" in quotes.

    First, lower case the toys array and the quotes array. I assume touching the input arrays is OK but I could copy them if not.
    Helper function - void LowerCaseStrArray(char **StrArray...); // Coverts all alphabetic chars in StrArray to lower case.

    // Great, now don't need to worry about the case-sensitivity of our freq count for toy = "train"

    Lets consider the quote "This train is so cool. The train makes choo choo sounds."
    "train" occurs twice but the freq count = 1, since we don't count the same toy within a single quote more than once.

    Well, we need a place to store our freq counts as we go along.
    */

    // Allocate an array of frequency table entries. Each entry stores the toy name and its frequency.
    FreqTable = calloc((size_t)numToys, sizeof(*FreqTable)); // calloc 0's the mem.
    if(FreqTable == NULL) {
        return NULL;
    }

    // Allocate an array of pointers to frequency table entries. This will be used to do the actual sorting.
    FreqTableSorted = calloc((size_t)numToys, sizeof(*FreqTableSorted));
    if(FreqTableSorted == NULL) {
        return NULL;
    }

    // Lower the _toys_ array of strings.
    LowerCaseStrArray(toysdup->arr, toysdup->size);

    // Lower the _quotes_ array of strings
    LowerCaseStrArray(quotesdup->arr, quotesdup->size);

    // For every toy name
    for (ToysIndex = 0; ToysIndex < numToys; ToysIndex++){
        FreqTable[ToysIndex].ToyName = toysdup->arr[ToysIndex]; // Current toy whose freq is being computed.
        // For every quote
        for(QuotesIndex = 0; QuotesIndex < numQuotes; QuotesIndex++) {
            FreqTable[ToysIndex].Freq += QuoteContainsToy (quotesdup->arr[QuotesIndex], FreqTable[ToysIndex].ToyName);
        }
        FreqTableSorted[ToysIndex] = &FreqTable[ToysIndex];
    }

    /*
    ************** Scratch work
    At this point FreqTable should store the freq count of each toy name
    Now we need to sort it by freq, then resolve ties by alphabetic order.
    */

    // Sort by frequency.
    qsort((void *)FreqTableSorted, (size_t)numToys, sizeof(*FreqTableSorted), FreqTableEntryCmp);

    /*
    ************** Scratch Work
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

    // Sort any ties in frequency alphabetically.
    AlphabeticallySortEqualFreq(numToys, FreqTableSorted);

    // Return result.

    Result = calloc((size_t)1, sizeof(*Result));

    if(Result == NULL) {
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