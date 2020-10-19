#include <stdio.h>
#include <assert.h>

#define IN_ARRAY_LEN (10)

int in_a[IN_ARRAY_LEN] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};
const int in_len = IN_ARRAY_LEN;

int out_a[IN_ARRAY_LEN];

void sort(int a[], unsigned int len);

int main(int argc, char **argv) {

    sort(in_a, in_len);

    for (int i = 0; i < in_len; i++) {
        printf("%d ", in_a[i]);
    }

    printf("\n");

    return 0;
}

// Returns the index of the minimum element in a[]. Returns -1 on error.
int get_min_index(int a[], unsigned int len) {
    unsigned int min, min_index, i;

    if (a == NULL || len == 0) {
        assert(0);
        return -1;
    }

    min_index = 0;
    min = a[min_index];

    for (i = 1; i < len; i++) {
        if (a[i] < min) {
            min_index = i;
            min = a[i];
        }
    }

    return min_index;
}

// Returns 0 if successful. Returns 1 on error.
int swap(int a[], unsigned int i, unsigned int j, unsigned int len) {
    int t;

    if (a == NULL || i >= len || j >= len) {
        assert(0);
        return 1;
    }

    t = a[i];
    a[i] = a[j];
    a[j] = t;

    return 0;
}

void sort(int a[], unsigned int len) {
    int m, r, i;

    for (i = 0; i < len - 1; i++) {
        m = get_min_index(&a[i + 1], len - i - 1); // Find the index of the min. element in the unsorted subset of the array.
        assert(m != -1);
        m += i + 1;
        if (a[i] > a[m]) {
            r = swap (a, i, m, len);
            assert(r == 0);
        }
    }
}