/*


    https://www.hackerrank.com/challenges/maximum-element/problem

    Success Rate: 70.71%

    Solved. Required speeding up the code.

*/

/*

Constraints:

1 <= N <= 100000 // Thus the size of the stack must be at least 100000.
1 <= x <= 1000000000 // Thus an int type is sufficient.

Inputs:

1 x // Push x
2 // Delete top
3 // Print max

*/

#include <stdio.h>

#define STACK_SIZE 100000
static int stack[STACK_SIZE];
static int num_entries = 0;
static int cmax = -1;

// Returns 0 if successful.
int push(int v) {
    if (num_entries >= STACK_SIZE) { // Stack is full
        return -1;
    }

    stack[num_entries] = v;
    num_entries++;
    return 0;
}

// Returns > -1 if successful.
int pop(void) {
    if (num_entries <= 0) { // Stack is empty
        return -1;
    }
    num_entries--;
    return stack[num_entries];
}

int stack_max(void) {
    int max;

    if (num_entries <= 0) { // Stack is empty.
        return -1;
    }

    max = stack[0];

    for (int i = 0; i < num_entries; i++) {
        if (stack[i] > max) {
            max = stack[i];
        }
    }

    return max;
}

#define LINE_SIZE 64

int main(void) {
    char line[LINE_SIZE];
    int N, q, x, t;

    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        fgets(line, LINE_SIZE, stdin);
        if (line[0] == '1') {
            sscanf(line, "%d %d\n", &q, &x);
            push(x);
            if (x > cmax) // Value just pushed is greater than current max value. Update current max value.
                cmax = x;
        } else if (line[0] == '2') {
            t = pop();
            if (t == cmax) // Value just popped was == to current max value.
                cmax = stack_max();
        } else if (line[0] == '3') {
            printf("%d\n", cmax);
        }
    }

    return 0;
}