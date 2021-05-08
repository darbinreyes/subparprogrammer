/* July 21, 2020 */

/* Replace instances of match with replace in str

   str - NUL terminated string to do inplace replacement in. (Assume it is large enough to fit new string
   match - NUL terminated string to match for replacement
   replace - NUL terminated string to replace instances of match with

   Return value - number of replacements made.
*/

//int stringreplace (char *str, char *match, char *replace)

//str - "the fox is over there."
//match - "the"
//replace - "many"

//After function

//str - "many fox is over manyre."
//Return value 2

// str - "hello lower"
// match - "lo"
// replace - "hello"

/************ My changes start here. ************/

#include <string.h> // strlen() // strcmp() for test cases.
#include <assert.h> // for test cases.
#include <stdio.h> //  for test cases.

// Returns 1 if there is a match. Returns 0 otherwise.
int is_match(char const *str, char const *match) {
    int ls, lm;

    ls = strlen(str);
    lm = strlen(match);

    if (ls < lm)
        return 0;

    // assert ls >= lm

    while (*match != '\0') {
        if (*str != *match)
            return 0;
        str++;
        match++;
    }

    return 1;
}

// Returns the first occurrence of match in str. Returns NULL if match is not found.
char *str_match(char const *str, char const *match) {
    char const *s;
    int ls, lm;

    ls = strlen(str);
    lm = strlen(match);

    if (ls < lm)
        return NULL;

    // assert ls >= lm

    s = str;

    while (*s != '\0') {
        if(is_match(s, match)) {
            return (char *)s;
        }
        s++;
    }

    return NULL;
}

// Copies all chars in r to s, __excluding__ the null terminator.
void str_insert(char *s, char const *r) {
    while (*r != '\0') {
        *s = *r;
        s++;
        r++;
    }
}

/*

    Starting from the __end__ of s, until s+lm, copies each char in s to s + d,
    including the null terminator.

*/
void str_cpy_up(char *s, int const d, int const lm) {
    char *t;
    int ls;

    ls = strlen(s);
    t = s + ls; // Point t to null terminator of s.
    s += lm; // Move past the match string.

    while (s < t) {
        /* Starting from the end of s, copy each char from its current index to current index + d */
        *(t + d) = *t;
        t--;
    }

    // assert s == t

    *(t + d) = *t; // Copy the last char.

}

// Copies all chars starting at s + lm to position s + lr.
void str_cpy_down(char *s, int const lm, int const lr) {
    char *t;

    t = s + lm; // Move past the match string.
    s = s + lr; // lr = replacement string length.

    while (*t != '\0') {
        *s = *t;
        t++;
        s++;
    }

    *s = '\0';
}

int stringreplace (char *str, char *match, char *replace) {
    int ls, lm, lr;
    int d;
    char *t;
    int rcount;

    if (str == NULL || match == NULL || replace == NULL) {
        return 0;
    }

    // assuming none of the string lengths will overflow an int.

    ls = strlen(str);
    lm = strlen(match);
    lr = strlen(replace);

    if (ls == 0 || lm == 0 || ls < lm) // A match is impossible.
        return 0;

    // assert ls != 0 && lm != 0 && ls >= lm

    // FYI: lr == 0 means delete occurrences of match.

    d = lr - lm;
    t = str;
    rcount = 0;

    if (d == 0) {
        // match and replace are equal in length.
        while ( (t = str_match(t, match)) != NULL ) {
            str_insert(t, replace);
            t += lr; // Move past the part of the string we already matched.
            rcount++;
        }
    } else if ( d > 0) {
        // length of match < replace, we need to make space in str.
        while ( (t = str_match(t, match)) != NULL ) {
            str_cpy_up(t, d, lm);
            str_insert(t, replace);
            t += lr;
            rcount++;
        }
    } else { // d < 0
        // length of match > replace, we need to remove space in str.
        while ( (t = str_match(t, match)) != NULL ) {
            str_cpy_down(t, lm, lr);
            str_insert(t, replace);
            t += lr;
            rcount++;
        }
    }

    return rcount;
}

int main(void) {
    char buf[1024];
    char *str;
    char *match;
    char *replace;
    char *str_correct;
    int r, r_correct;

/* ******* Test cases: length of match string is less, equal, or greater than the replace string  ******* */

/* ******* Test case ******* */
//str - "the fox is over there."
//match - "the"
//replace - "many"

    str = "the fox is over there.";
    match = "the";
    replace = "many";
    str_correct = "many fox is over manyre.";
    r_correct = 2;

    strcpy(buf, str);

    r = stringreplace (buf, match, replace);

    assert(r == r_correct);

    assert(strcmp(buf, str_correct) == 0);

/* ******* Test case ******* */
// str - "hello lower"
// match - "lo"
// replace - "hello"

    str = "hello lower";
    match = "lo";
    replace = "hello";
    str_correct = "helhello hellower";
    r_correct = 2;

    strcpy(buf, str);

    r = stringreplace (buf, match, replace);

    assert(r == r_correct);

    assert(strcmp(buf, str_correct) == 0);

/* ******* Test case ******* */
// str - "hello hellower"
// match - "hello"
// replace - "lo"

    str = "hello hellower";
    match = "hello";
    replace = "lo";
    str_correct = "lo lower";
    r_correct = 2;

    strcpy(buf, str);

    r = stringreplace (buf, match, replace);

    assert(r == r_correct);

    assert(strcmp(buf, str_correct) == 0);

/* ******* Test case ******* */
// str - "hello hellower"
// match - "hello"
// replace - "jello"

    str = "hello hellower";
    match = "hello";
    replace = "jello";
    str_correct = "jello jellower";
    r_correct = 2;

    strcpy(buf, str);

    r = stringreplace (buf, match, replace);

    assert(r == r_correct);

    assert(strcmp(buf, str_correct) == 0);

/* ******* Test case ******* */
// str - "hello hellower"
// match - "hello"
// replace - ""

    str = "hello hellower";
    match = "hello";
    replace = "";
    str_correct = " wer";
    r_correct = 2;

    strcpy(buf, str);

    r = stringreplace (buf, match, replace);

    assert(r == r_correct);

    assert(strcmp(buf, str_correct) == 0);

    printf("Done.\n");

    return 0;
}


/* ******* Scratch Work (ignore) *******

for each match in str
    insert replace

insert replace cases

* len match = len replace. Easy.

===

* len match < len replace

// str - "hello lower"
// match -   "lo"
// replace - "hello"

make space, len_match - len_replace = 2 - 5 = -3
"hello lower"
      ^  ^
       ^  ^
        ^  ^
         ^  ^
// Start at first matching char + len_match, stop swapping up when c == '\0'
"hello--- lower"

insert "hello"
"hello--- lower"
"helhello lower"

make space
"helhello lo---wer"
"helhello hellower"

Return 2.

Done.

===

* len match > len replace

// str - "hello lower"
// match - "hello"
// replace - "lo"

remove space, len_match - len_replace = 5 - 2 = 3 = d.
"hello lower" // c = Starting at first char of match + len_replace, swap(c << c + d)
   ^  ^
"he lo lower"
    ^  ^
"he lo lower"
     ^  ^
"he lo lower"
      ^  ^
"he lowlower"
       ^  ^
// Stop when c + d == '\0'
"he<<< lower"
"lo lower"

Return 1.


************** */