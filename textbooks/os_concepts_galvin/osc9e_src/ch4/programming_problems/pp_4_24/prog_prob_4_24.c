#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


long is_prime(long p) {
    // TODO:
    return 1;
}

void *runner(void *param) {
    long upper_bound;
    upper_bound = *((long *) param);

    /* Print all primes <= upper_bound*/


    return NULL;
}

int main(int argc, char **argv) {
    long upper_bound;
    char *endp;

#define USAGE_STR "Usage: Provide a single integer > 0. The integer must fit in a long type. Example: ./a.out 78.\n"

    if (argc < 2) {
        printf(USAGE_STR);
        return 1;
    }

    if (argc > 2) {
        printf(USAGE_STR);
        return 1;
    }

    // assert argc == 2.

    upper_bound = strtol(argv[1], &endp, 10);

    /*  Enforce that the last character of the integer command line argument is
    also the last character of the entire command. Also, enforce that the integer
    is > 0. */
    if (*endp != '\0' || upper_bound <= 0) {
        printf(USAGE_STR);
        return 1;
    }

    // Input validated. Compute.

    // TODO: Create thread, join thread.


    return 0;
}


