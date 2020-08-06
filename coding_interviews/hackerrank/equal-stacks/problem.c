/*


    https://www.hackerrank.com/challenges/equal-stacks/problem

    Success Rate: 78.11%

*/

/* Scratch work

Since the problem says "An empty stack is still a stack" then we should
properly handle the possibility that the input may contain a 0 size stack,
in which case the only possible solution is that the maximum stack size is 0.

Since popping a value off a stack can only decrease its height, therefore, as
part of the process of finding the maximum equal stack size, we should begin by
determining which stack has the minimum height. Next, if the height of either of
the two remaining stacks is greater, we pop a value off that stack. If after this
all stacks have the same height, we print that height and we are done. If at any
point any of the stacks has 0 height, we print 0 and we are done.

*/

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100000

typedef struct _stack_t {
    int stack[STACK_SIZE];
    int num_entries;
    int height;
} my_stack_t;

#define NUM_STACKS 3

static my_stack_t stacks[NUM_STACKS];

int push(my_stack_t *s, int v) {
    if (s->num_entries >= STACK_SIZE) { // Stack is full.
        return -1;
    }
    s->height += v;
    s->stack[s->num_entries] = v;
    s->num_entries++;
    return 0;
}

int pop(my_stack_t *s) {
    int v;
    if (s->num_entries <= 0) { // Stack is empty.
        return -1;
    }

    s->num_entries--;
    v = s->stack[s->num_entries];
    s->height -= v;
    return v;
}

/*

    The max value is "100", 3 characters.
    For n values, on a single line, n*3 characters + (n-1) single character spaces + 1 new line character + 1 null terminator
    The max number of stack values is 100000.
    Thus the max line size = 100000*3+(100000-1)+1+1 = 400001.

*/
#define LINE_SIZE 500000

static char line[LINE_SIZE];
static my_stack_t input_stack;

void init_stack(int n, my_stack_t *s) {
    int i;
    long t;
    char *endptr;

    /*

       Get the values to place in the stack. The first number is the **top** of
       the stack.

    */
    fgets(line, LINE_SIZE, stdin);

    endptr = line;

    for (i = 0; i < n; i++) {
        t = strtol(endptr, &endptr, 10);
        push(&input_stack, t);
    }

    /*

        Since the first number in the input line is the **top** of the stack we
        want the values in reverse order from how they are currently ordered in
        `input_stack`, the following loop places the values in the stack in the
        desired order.

    */

    for (i = 0; i < n; i++) {
        t = pop(&input_stack);
        push(s, t);
    }
}

int main(void) {
    int n[NUM_STACKS];
    int i;

    /* Get the first line of input. The size of 3 stacks. */
    scanf("%d %d %d\n", &n[0], &n[1], &n[2]);

    /* Initialize the 3 stacks. */
    for (i = 0; i < NUM_STACKS; i++) {
        init_stack(n[i], &stacks[i]);
    }

    for (i = 0; i < NUM_STACKS; i++) {
        printf("height = %d\n", stacks[i].height);
    }

    /* Output: Print a single integer denoting the maximum height at which all
       stacks will be of equal height. */


    return 0;
}