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

int min_height_stack (int *mh) {
    int min_stack_i, min_height;

    min_stack_i = 0;
    min_height = stacks[0].height;

    for (int i = 1; i < NUM_STACKS; i++) {
        if (stacks[i].height < min_height) {
            min_stack_i = i;
            min_height = stacks[i].height;
        }
    }

    *mh = min_height;

    return min_stack_i;
}

#define LINE_SIZE 500000

int main(void) {
    int n1, n2, n3, i, done, mh, mhi;
    long t;
    char line[LINE_SIZE];
    char *endptr;

    scanf("%d %d %d\n", &n1, &n2, &n3);

    fgets(line, LINE_SIZE, stdin);

    endptr = line;

    for (i = 0; i < n1; i++) {
        t = strtol(endptr, &endptr, 10);
        push(&stacks[0], t);
    }

    fgets(line, LINE_SIZE, stdin);

    endptr = line;

    for (i = 0; i < n2; i++) {
        t = strtol(endptr, &endptr, 10);
        push(&stacks[1], t);
    }

    fgets(line, LINE_SIZE, stdin);

    endptr = line;

    for (i = 0; i < n3; i++) {
        t = strtol(endptr, &endptr, 10);
        push(&stacks[2], t);
    }

    for (i = 0; i < NUM_STACKS; i++) {
        printf("height = %d\n", stacks[i].height);
    }

    done = 0;
    mh = -1;

    while (!done) {
        mhi = min_height_stack (&mh);

        if (mh == 0) {
            break;
        }

        for (i = 0; i < NUM_STACKS; i++) {

            if (i == mhi)
                continue;

            if (stacks[i].height > mh) {
                pop(&stacks[i]);
            }
        }

        for (i = 0; i < NUM_STACKS; i++) {
            if (stacks[i].height != mh) {
                break;
            }
        }

        if (i == NUM_STACKS)
            break;

    }

    if (mh == 0)
        printf("0\n");
    else
        printf("%d\n", mh);

    return 0;
}