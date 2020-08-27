#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

long a[ARRAY_SIZE];
int as;

long avg, min, max;

void *avg_thread(void *param){

    avg = 0;

    for(int i = 0; i < as; i++) {
        avg += a[i]; // FYI: Not checking for overflow.
    }

    avg /= as;

    return NULL;
}

void *min_thread(void *param){
    long t;

    t = a[0];
    for(int i = 1; i < as; i++) {
        if (a[i] < t)
            t = a[i];
    }

    min = t;

    return NULL;
}

void *max_thread(void *param){

    long t;

    t = a[0];
    for(int i = 1; i < as; i++) {
        if (a[i] > t)
            t = a[i];
    }

    max = t;

    return NULL;
}

int main(int argc, char **argv) {

    int i;

    if(argc <= 1) {
        printf("Usage: Provide up to %d positive integers. "
               "More than that will be ignored. Example ./a.out 2 3 5 7.\n", ARRAY_SIZE);
        return 1;
    }

    for (i = 0; i < ARRAY_SIZE && i < argc - 1; i++) {
        a[i] = strtol(argv[i+1], NULL, 10);
        if (a[i] == 0) {
            printf("Failed to convert \"%s\" to an integer. Aborted.\n", argv[i+1]);
            return -1;
        }
    }

    as = i;

    printf("%d inputs: ", as);

    for(i = 0; i < as; i++) {
        printf("%ld ", a[i]);
    }

    printf("\n");

    avg_thread(NULL);
    min_thread(NULL);
    max_thread(NULL);

    printf("avg. %ld\nmin. %ld\nmax. %ld\n", avg, min, max);

    return 0;
}