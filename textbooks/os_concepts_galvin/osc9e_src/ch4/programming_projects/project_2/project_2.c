#include <stdio.h>
#include <assert.h>
#include "sort.h"

static int in_a[] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};

#define IN_ARRAY_LEN (sizeof(in_a)/sizeof(in_a[0]))

static const int in_len = IN_ARRAY_LEN;

static int out_a[IN_ARRAY_LEN];

int main(int argc, char **argv) {

    // TODO: handle len == 1
    sort(in_a, in_len/2);
    sort(in_a + in_len/2, in_len - in_len/2);

    print_a(in_a, in_len/2);
    print_a(in_a + in_len/2, in_len - in_len/2);

    return 0;
}

