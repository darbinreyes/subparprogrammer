/*

    https://www.hackerrank.com/challenges/simple-text-editor/problem

*/

#include <assert.h>
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
#define CHAR_BUF_SIZE (CHAR_BUF_LEN + 1) /* +1 for null terminator. */
/* +2 for initial operator character and a single space character  +1 for
   possible new line character. */
#define LINE_BUF_SIZE (2 + CHAR_BUF_SIZE + 1)

static char cbuf[CHAR_BUF_SIZE]; // Stores characters currently in the editor.
static int clen = 0; // The number of characters current in cbuf.
static char *cend = cbuf; // Points to the next free spot in cbuf.

/*

    Structure that stores information necessary to undo an append(W) or
    delete(k) operation.

    To undo an append(W) operation, we can execute a delete(W.length).

    To undo a delete(k) operation, we can execute a append(W) operation with
    W = k characters that where deleted.

*/

typedef
struct _undo_op {
    char append_or_delete; // 0 = append, 1 = delete.
} undo_op;

static undo_op undo_stack[CHAR_BUF_LEN];
static int undo_stack_top = 0;


/* Append the given characters. */
void append(char *w) {
    assert(w != NULL);
    assert(clen < CHAR_BUF_SIZE);

    /* We test for a '\n' because fgets() retains new lines in the input. */
    while (*w != '\n' && *w != '\0') {
        *cend = *w;
        w++;
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

void undo(void) {
    // TODO.
    return;
}

int main() {
    static char line[LINE_BUF_SIZE];
    int Q = 0, op = 0, n = 0;
    char *s = NULL;

#define APPEND_OP '1'
#define DELETE_OP '2'
#define PRINT_OP  '3'
#define UNDO_OP   '4'

    /*

        Read inputs. First line = Q, then read Q lines, each indicating an
        operation between 1-4.

    */

    n = scanf("%d\n", &Q);

    if (n != 1)  { /* Invalid input. Terminate.*/
        assert(0);
        return 1;
    }

    while (Q-- > 0) { // [x] Q == 0 is handled correctly.

        /*

            FYI MAN: "The newline, if any, is retained." "If any characters are
            read and there is no error, a `\0' character is appended to end the
            string."

            TODO: Full error checking for fgets().

            FYI MAN: "do not distinguish between end-of-file and error, and
            callers must use feof(3) and ferror(3) to determine which occurred."

        */
        s = fgets(line, LINE_BUF_SIZE, stdin); /* Read a line. */

        /* Since we know to read exactly Q lines this should not occur. Error.
           Terminate. */
        if (s == NULL) {
            return 3;
        }

        if (line[0] == APPEND_OP) {
            append(&line[2]);
        } else if (line[0] == DELETE_OP) {
            n = atoi(&line[2]); // TODO: Error check n.
            delete(n);
        } else if (line[0] == PRINT_OP) {
            n = atoi(&line[2]);
            print(n - 1); /*  -1, IMPORTANT: in "print(k)", k is a 1 based index. */
        } else if (line[0] == UNDO_OP) {
            undo(); // TODO:
        } else {
            return 2;  /* Invalid input. Terminate.*/
        }
    }


    return 0;
}
