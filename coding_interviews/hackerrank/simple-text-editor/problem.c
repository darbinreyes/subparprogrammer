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

    The sum of the lengths of all W in the input <= 10^6
    =>
    The length of the character buffer should be 10^6 chars.

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


#define CHAR_BUF_SIZE 1000000
static char cbuf[CHAR_BUF_SIZE]; // Stores characters currently in the editor.
static int clen; // The number of characters current in cbuf.
static char *cend; // Points to the next free spot in cbuf.


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */


    return 0;
}
