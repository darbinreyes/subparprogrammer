/*

    https://www.hackerrank.com/challenges/simple-text-editor/problem

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Operation types.

    1. append(W)
    2. delete(k)
    3. print(kth character)
    4. undo() last 1 or 2 operation

*/

/* Constraints.

*    1 <= Q <= 10^6
    =>
     an int is big enough to store Q.

*    1 <= k <= |S|
    =>
     k is a 1 based index. k will always be within the bounds of the current editor buffer string.

*    sum(all W) <= 10^6
    =>
     The length of the character/editor buffer should be 10^6 chars.

*    sum(all k in delete(k)) <= 2*10^6
    =>
     2*10^6 is the upper bound on the total number of characters deleted.

*    all input characters are lower case English letters
    =
     for all c in S, c in [a-z]

    it is guaranteed that the sequence of ops "is possible to perform"

*/

/* Scratch Work

    The main difficulty in this problem is the implementation of the undo()
    operation.

    We can use a stack to store the information necessary to undo each #1 and
    #2 operation. When an undo() is requested, can pop the stack and use its
    contents to undo the operation. A struct to represent each stack item seems
    appropriate. Since we must store the characters deleted by a delete()
    operation to undo() it, which can be as many as 10^6 character, we can use
    malloc() to allocate memory for those characters. Note that to undo() a
    append(W) operation, we can perform a delete(W.length) operation. Similarly,
    to undo() a delete(k) operation, we can perform an append(W) operation where
    W = stack_item.chrs.

*/

#include <assert.h>

#define CHAR_BUF_LEN 1000000
#define CHAR_BUF_SIZE (CHAR_BUF_LEN+1)

static char cbuf[CHAR_BUF_SIZE]; // Stores characters currently in the editor.
static int clen = 0; // The number of characters current in cbuf.
static char *cend = cbuf; // Points to the next free spot in cbuf.


/* Append the given characters. */
void append(char *w) {
    assert(w != NULL);
    assert(clen < CHAR_BUF_SIZE);

    while (*w != '\0') {
        *cend = *w;
        cend++;
        clen++;
    }
}

/* Delete k characters. */
void delete(int k) {

/*

[A][]
   ^cend

clen = 1.

# after delete(1)

[A][]
^cend

clen = 0.



*/
    assert(k >= 0);

    if (k == 0) // No-op.
        return;

/* If k is greater than or equal the number of characters in the buffer we just
reset to the initial empty state. */

    if (k >= clen) {
        cend = cbuf;
        clen = 0;
        return;
    }

    while (clen > 0) {
        cend--;
        clen--;
    }
}

/* Print the k-th character. */
void print (int k) {
    assert(k >= 0);

/*

[A][B][]...
      ^cbuf
clen = 2.

print(0)

# prints A

print(1)

# prints B

print(2)

# out of bounds.

*/

    if (k < clen) {
        putchar(cbuf[k]);
        putchar('\n');
    } // else // k is out of bounds, treat is as a NO-OP.
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    /* IMPORTANT: k is a 1 based index. */


    return 0;
}
