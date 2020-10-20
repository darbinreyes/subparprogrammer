#include <stdio.h>
#include <assert.h>
#include "sort.h"

static int in_a[] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};

#define IN_ARRAY_LEN (sizeof(in_a)/sizeof(in_a[0]))

static const int in_len = IN_ARRAY_LEN;

static int out_a[IN_ARRAY_LEN];

int main(int argc, char **argv) {
    int *am, *a0, *a1;
    int am_len, a0_len, a1_len;

    // TODO: handle len == 1
    assert(in_len > 1);

    am = out_a;
    am_len = in_len;

    a0 = in_a;
    a0_len = in_len/2;

    a1 = in_a + in_len/2;
    a1_len = in_len - in_len/2;

    sort(a0, a0_len);
    sort(a1, a1_len);

    print_a(a0, a0_len);
    print_a(a1, a1_len);

    merge(am, am_len, \
           a0, a0_len, \
           a1, a1_len);

    print_a(am, am_len);
    return 0;
}

