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

// Returns 1 if all three stacks currently have equal heights. 0 Otherwise.
int stack_heights_equal (void) {
    int i;
    int ec, h;

    ec = 0; // Equal count.
    h = stacks[0].height;

    for (i = 0; i < NUM_STACKS; i++) { // TODO: If necessary we can optimize this later.
        if (stacks[i].height == h)
            ec++;
    }

    return (ec == NUM_STACKS);
}

// Returns a pointer to the first stack having the minimum height.
my_stack_t *min_height_stack(void) {
    int i, h, mi;

    mi = 0;
    h = stacks[0].height;

    for (i = 0; i < NUM_STACKS; i++) { // TODO: If necessary we can optimize this later.
        if (stacks[i].height < h) {
            mi = i;
            h = stacks[i].height;
        }
    }

    return &stacks[mi];
}

// Pops a single value off any stack whose height is greater than h.
void pop_greater_than(int h) {
    int i;

    for (i = 0; i < NUM_STACKS; i++) { // // TODO: If necessary we can optimize this later.
        if (stacks[i].height > h) {
            pop(&stacks[i]);
        }
    }
}

int main(void) {
    int n[NUM_STACKS];
    int i;
    my_stack_t *min_h_stack;

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

    /* To begin with we will definitely need a function for testing if the
    stacks are currently of equal height. */

    /*


        Next, we need to pop values off the stacks in such a way that we can
        determine the "the maximum height at which all stacks will be of equal
        height."

        0. Since all values are positive (between [1,100]), popping a value off
        the a stack can only decrease its height. This suggests that we should
        start with the stack having the smallest height. Let us call this
        stack `sh_stack` (smallest height stack).

        The two remaining stacks must then have a height equal to or greater
        than the height of `sh_stack`. We can now identify 3 possibilities to
        deal with respect to the height of the two remaining stacks:

        1. Both of the remaining two stacks have heights equal to the height of
        `sh_stack`. We are done, we can print the height of any stack and
        terminate.

        2. One of the two remaining stacks has a height greater than the height
        of `sh_stack`. In this case we can pop a single value off the stack with
        the greater height. After that we can test if the heights have become
        equal, if so, print the height of any one of the stacks and we are done,
        otherwise determine the new smallest stack and repeat ("0." above).

        3. Both of the two remaining stacks has a height greater than the height
        of `sh_stack`. In this case we pop a single value off of both remaining
        stacks. After that, we test for equal heights, and if they are of equal
        height we are done. Otherwise determine the new smallest stack and
        repeat ("0." above).

    */

    while (!stack_heights_equal()) {
        min_h_stack = min_height_stack();
        pop_greater_than(min_h_stack->height);
    }

    printf("%d\n", stacks[0].height);

    return 0;
}