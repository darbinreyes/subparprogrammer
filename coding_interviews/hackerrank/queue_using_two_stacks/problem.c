/*

  https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

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
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  ns = scanf("%d\n", &nq);
  printf("%d\n", nq);
  while ( nq-- > 0 ) {
    ns = scanf("%s\n", line);

    printf("ns = %d, s = %s.\n", ns, line);
  }
  printf("Done.\n");
  return 0;
}
