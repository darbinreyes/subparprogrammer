#include <stdio.h>
#include <stdlib.h>

long get_rand_sleep_ns(void) {
    float frn;
    float frd;


    frn = (float) rand();
    frd = (float) RAND_MAX;


    frn = 10000000.0 * (frn/frd);

    return (long) frn;
}

int main(int arc, char **argv) {
    return 0;
}