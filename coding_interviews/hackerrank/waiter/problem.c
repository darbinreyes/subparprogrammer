/*

  https://www.hackerrank.com/challenges/waiter/problem

  Success Rate: %82.79

*/

/* ******* Scratch work.

Start with stack of integers. A_0.

Perform Q operations on it. i = 1 -> Q.

Iteration, i = 1.

Stack operated on = A_i-1 = A_1-1 = A_0.

while A_0 not empty:

  t = A_0.pop()
  p = prime_i = prime_1 = 2.
  d = t % prime_1 = t % 2.
  if d == 0
    Stack B_i = B_1
    B_1.push(t)
  else
    Stack A_i = A_1
    A_1.push(t)


Upon termination, after Q iterations we have

Q+1 distinct stacks: B_1 -> B_Q , and A_Q.
In this order: B_1 -> B_Q , and A_Q.
Pop all values off the stacks and return as int array.

*******

Plan:

Implement single iteration.
Confirm correctness with sample input.
Generalize to more iterations.

*/

/* ******* Sample input 0 walk through.

******* Input
5 1 // means N = 5, Q = 1
3 4 7 6 5 // means A_0 = [3, 4, 7, 6, 5]<-TOP
*******

for i = 1, to i = Q = 1



t = A_0.pop() = 5. // A_0 = [3, 4, 7, 6]<-TOP
p = prime_i = prime_1 = 2.

if t % p == 0 // 5 % 2 == 0 // 1 == 0 // false
  // B_i = B_1 = []<-TOP
  B_i.push(t)
else
  // A_i = A_1 = []<-TOP
  A_i.push(t) = A_1.push(5) // A_1 = [5]<-TOP

*******
t = A_0.pop() = 6. // A_0 = [3, 4, 7]<-TOP
6 % 2 == 0
// B_1 = []<-TOP
B_1.push(6)
// B_1 = [6]<-TOP
*******
t = A_0.pop() = 7. // A_0 = [3, 4]<-TOP
7 % 2 == 0 // 1 == 0 // false
// A_1 = [5]<-TOP
A_1.push(7)
// A_1 = [5, 7]<-TOP
*******
t = A_0.pop() = 4. // A_0 = [3]<-TOP
4 % 2 == 0
// B_1 = [6]<-TOP
B_1.push(4)
// B_1 = [6, 4]<-TOP
*******
t = A_0.pop() = 3. // A_0 = []<-TOP
3 % 2 == 0 // 1 == 0 // false
// A_1 = [5, 7]<-TOP
A_1.push(3)
// A_1 = [5, 7, 3]<-TOP
******* Iterations complete.
A_0 = []<-TOP
B_1 = [6, 4]<-TOP
A_1 = [5, 7, 3]<-TOP
******* Printing the result
4 = B_1.pop()
6 = B_1.pop()
3 = A_1.pop()
7 = A_1.pop()
5 = A_1.pop()
*******

Notice that the number of integers we start with = # end with.

*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

#define STACK_SIZE 50000

typedef struct {
  int stack[STACK_SIZE];
  int stack_top; // Points to the next free spot on the stack. == 0 means stack is empty. == STACK_SIZE means stack is full.
} istack_t;

// Returns a pointer to a new stack if successful, NULL otherwise.
istack_t *alloc_stack(void) {
  istack_t *s;

  s = calloc(1, sizeof(istack_t));

  return s;
}

// Frees memory allocated for the given stack.
void free_stack(istack_t *s) {
  if (s != NULL)
    free(s);
}

// Returns 1 if stack is empty, 0 otherwise.
int stack_is_empty(istack_t *s) {
  if (s->stack_top == 0)
    return 1;

  return 0;
}

// Returns 1 if the stack is full, 0 otherwise.
int stack_is_full(istack_t *s) {
  if (s->stack_top == STACK_SIZE)
    return 1;

  return 0;
}

// Returns 0 if successful, 1 otherwise.
int stack_push(istack_t *s, int v) {
  if(stack_is_full(s))
    return 1;

  s->stack[s->stack_top] = v;
  s->stack_top++;
  return 0;
}

// Returns 0 if successful, 1 otherwise.
int stack_pop(istack_t *s, int *v) {
  if(stack_is_empty(s))
    return 1;

  s->stack_top--;
  *v = s->stack[s->stack_top];

  return 0;
}

/*
 * Complete the waiter function below.
 */

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */
int* waiter(int number_count, int* number, int q, int* result_count) {
  /*
  * Write your code here.
  */
  return NULL;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nq = split_string(readline());

    char* n_endptr;
    char* n_str = nq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nq[1];
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    char** number_temp = split_string(readline());

    int number[n];

    for (int number_itr = 0; number_itr < n; number_itr++) {
        char* number_item_endptr;
        char* number_item_str = number_temp[number_itr];
        int number_item = strtol(number_item_str, &number_item_endptr, 10);

        if (number_item_endptr == number_item_str || *number_item_endptr != '\0') { exit(EXIT_FAILURE); }

        number[number_itr] = number_item;
    }

    int result_count;
    int* result = waiter(number_count, number, q, &result_count); // DER: Given code has this compilation error. number_count undeclared. Looks like n is the correct variable name.

    for (int result_itr = 0; result_itr < result_count; result_itr++) {
        fprintf(fptr, "%d", result[result_itr]);

        if (result_itr != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
