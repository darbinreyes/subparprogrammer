// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <stdlib.h> // malloc / qsort
#include <string.h> // strstr
#include <ctype.h> // tolower etc.
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
    if(strstr(Quote, Toy) != NULL) {
        return 1;
    } else {
        return 0;
    }
}
boundedStringArray* popularNToys(int numToys, int topToys,
                                    boundedStringArray* toys,
                                    int numQuotes,
                                    boundedStringArray* quotes)
{
    // WRITE YOUR CODE HERE
    boundedStringArray *Result;
    char **FreqTable_ToyNameStr;
    int  *FreqTable_ToyFreqCount;
    char *CurrentToy, CurrentQuote;
    int QuotesIndex, ToysIndex, FreqTable_Index;

    // TODO: Handle invalid args like toys == NULL

    /*
    *** Scratch work.

    Consider the case of a single toy "train". Let use determine
    the freq count of "train" in quotes.

    First, lower case the toys array and the quotes array. I assume touching the input arrays is OK but I could copy them if not.
    Helper function - void LowerCaseStrArray(char **StrArray...); // Coverts all alphabetic chars in StrArray to lower case.

    // Great, now don't need to worry about the case-sensitivity of our freq count for toy = "train"

    Lets consider the quote "This train is so cool. The train makes choo choo sounds."
    "train" occurs twice but the freq count = 1, since we don't count the same toy within a single quote more than onces.

    Well, we need a place to store our freq counts as we go along.
    */

    FreqTable_ToyNameStr = calloc((size_t)topToys, sizeof(char *)); // calloc 0's out mem.

    if(FreqTable_ToyNameStr == NULL) {
        // calloc error.
        return NULL;
    }

    FreqTable_ToyFreqCount = calloc((size_t)topToys, sizeof(int)); // calloc 0's out mem.

    if(FreqTable_ToyFreqCount == NULL) {
        return NULL;
    }

    // Lower the _toys_ array of strings.

    LowerCaseStrArray(toys->arr, toys->size);

    // Lower the _quotes_ array of strings
    LowerCaseStrArray(quotes->arr, quotes->size);

    for (FreqTable_Index = 0; FreqTable_Index < topToys; FreqTable_Index++){
        CurrentToy = toys->arr[FreqTable_Index]; // Current toy whose freq is being computed.
        FreqTable_ToyNameStr[FreqTable_Index] = CurrentToy;

        for(QuoteIndex = 0; QuoteIndex < numQuotes; QuoteIndex++) {
            CurrentQuote = quotes->arr[QuoteIndex];
            FreqTable_ToyFreqCount += QuoteContainsToy (CurrentQuote, CurrentToy);
        }
    }
    /*
      At this point FreqTable_ToyNameStr and FreqTable_ToyFreqCount should store the freq count of each toy name
      Now we need to sort it by freq, then resolve ties by alpha.
      // qsort returns the sorted array in accending order. we need the reverse.
    */

    // call qsort, reverse list,
    // call qsort again, handle ties.
    // return result.

    // out of time, I want to at least look at the next question.

}
// FUNCTION SIGNATURE ENDS