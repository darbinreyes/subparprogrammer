#include <stdio.h>

#define FIB_ARRAY_SIZE 1024

static int fib_a[FIB_ARRAY_SIZE];

void *fib(void *param) {
    int n;

    fib_a[0] = 0; /* The first two numbers are given constants. */
    fib_a[1] = 1;

    for (int i = 2; i < 7; i++) {
        fib_a[i] = fib_a[i - 1] + fib_a[i - 2];
    }

    return NULL;
}

int main(int argc, char **argv) {
    /*

        TODO:
        Finish fib().
        Get arg.
        Add thread.
        Test.

    */
    fib(NULL);

    for(int i = 0; i < 7; i++) {
        printf("%d, ", fib_a[i]);
    }

    printf("\n");

    return 0;
}