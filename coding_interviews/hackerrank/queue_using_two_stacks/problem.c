/*

  https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

  Success Rate: 87.89%
*/


/*
******* Constraints

1 <= q <= 100000.  // Q_SIZE = 100000.

1 <= type <= 3. // Use #defines.

1 <= abs(x) <= 1000000000. // <= 2**31-1. int is sufficient.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define Q_SIZE (100000 + 1)
#define IS_EN_Q 1
#define IS_DE_Q 2
#define IS_PRINT_Q_FRONT 3

static int queue[Q_SIZE];
static int front_index = 0;
static int back_index = 0;

// Returns 1 if the queue is full. Returns 0 otherwise.
int is_full(void) {
  if ( ((back_index + 1) % Q_SIZE) == front_index ) {
    return 1;
  }

  return 0;
}

// Returns 1 if the queue is empty. Returns 0 otherwise.
int is_empty(void) {
  if (back_index == front_index) {
    return 1;
  }

  return 0;
}

/*
  Add an entry to the back of the queue.
*/
int enqueu(int v) {
  // if not full.
  // append v to back of the queue.
  // update back index.
  // return 0 for success.
  // else queue is full.
  // return 1 for failure.

  if (is_full()) {
    return 1;
  }

  queue[back_index] = v;
  back_index = (back_index + 1) % Q_SIZE;
  return 0;
}

/*
  Remove an entry from the front of the queue.
*/
int dequeue(int *v) {
  // if not empty.
  // set *v to the entry at the front of the queue.
  // update front index.
  // return 0 for success.
  // else queue is empty.
  // return 1 for failure.
  if (is_empty()) {
    return 1;
  }

  *v = queue[front_index];
  front_index = (front_index + 1) % Q_SIZE;
  return 0;
}

/*
  Peek at the front entry.
*/
int peek(int *v) {
  if (is_empty()) {
    return 1;
  }

  *v = queue[front_index];
  return 0;
}

int main() {
  int ns;
  int cmd, val, nq;
  char line[128];
  char *s;
  char c;
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  ns = scanf("%d\n", &nq); // First line contains a single integer. Equals number of subsequent lines.
  //printf("%d\n", nq);
  while ( nq-- > 0 ) {
    /*

      Plan:
      Get the whole line using gets().
      Test the first character for equality with `1`, `2`, `3`.
      Use sscanf() to obtain data from line.

      '1' means the line contains two integers e.g. "1 42". It means enqueue 42.
      '2' means dequeue front entry.
      '3' means print front entry.

    */
    s = gets(line);

    if (s == NULL) {
      // gets() error.
      return 1;
    }

    c = line[0];

    if (c == '1') {
      ns = sscanf(line, "%d %d\n", &cmd, &val);

      if (ns != 2) {
        // Expected number of input items assigned == 2.
        return 2;
      }

      if (enqueu(val)) {
        // Enqueue error
        return 3;
      }

    } else if (c == '2') {
      if (dequeue(&val)) {
        // Dequeue error.
        return 5;
      }
    } else if (c == '3') {
      if (peek(&val)) {
        // Peek error.
        return 6;
      }

      printf("%d\n", val);
    } else {
      return 4; // Invalid first character.
    }
  }

  return 0;
}
