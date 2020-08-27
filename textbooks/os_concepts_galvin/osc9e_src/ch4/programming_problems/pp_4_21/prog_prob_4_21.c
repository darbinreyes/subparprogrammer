#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

long a[ARRAY_SIZE];

int main(int argc, char **argv) {

    int i;
    long *ap;

    if(argc <= 1) {
        printf("Usage: Provide up to 100 positive integers. \
            More than that will be ignored. Example./a.out 2 3 5 7.\n");
        return 1;
    }

    // for (i = 1; i < argc && i < ARRAY_SIZE+1; i++) {
    //     a[i-1] = strtol
    // }

    ap = &a;
    argv++;
    argc--;

    while(argc-- > 0) {
        *ap = strtol(*argv, NULL, 10);
        if (*ap == 0) {
            printf("Failed to convert %s to an integer. Aborted.\n", *argv);
            return -1;
        }
    }

    return 0;
}