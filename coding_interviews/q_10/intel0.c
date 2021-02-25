/*!
    @discussion Swap the specified bits in the given value.

```
1.
Code Question: Given an integer, swap consecutive b bits starting from given
position in binary. The bit to be swapped should not overlap with each other.

Example: n =15 (15 > binary : 00001111)

foo() {
p =2, q =5 (3rd and 6th bit from right)

b = 2(No. of consecutive bits in each sequence)

output: = 99 (binary--> 01100011)
// process to understand and test and debug.
```

*/

int swap_bits(int *v, int n, int m) {
    int nbits = sizeof(*v) * 8;
    int b0, b1;

    if (n >= nbits || m >= nbits || n < 0 || m < 0)
        return 1;

    if (n == m) // no-op
        return 0;

    b0 = *v & (1 << n);
    b1 = *v & (1 << m);

/*
if bits are same, no need to swap
else - bits differ, just toggle each
xor
0 0 - 0
0 1 - 1 <
1 0 - 1
1 1 - 0 <
*/

    if ((!b0) == (!b1)) // bits equal - no-op
        return 0;

    *v ^= (1 << n);
    *v ^= (1 << m);

    return 0;
}


int swap_bits_v2(int *v, int n, int m) {
    int nbits = sizeof(*v) * 8;
    int b0, b1;

    if (n >= nbits || m >= nbits || n < 0 || m < 0)
        return 1;

    if (n == m) // no-op
        return 0;

    b0 = (*v >> n) & 1;
    b1 = (*v >> m) & 1;

    if (b0 == b1) // bits equal - no-op
        return 0;

    *v ^= (1 << n);
    *v ^= (1 << m);

    return 0;
}

int main(void) {
    int v = 0xA; // 1010B -> swap_bits(&v, 0, 3) -> 0011B = 0x3

    swap_bits(&v, 0, 3);

    assert(v == 0x3);

    v = 0xAD; // 1010_1101B -> swap_bits_v2(&v, 1, 7) -> 0010_1111B = 0x2F

    swap_bits_v2(&v, 1, 7);

    assert(v == 0x2F);

    printf("All good.\n");
    return 0;
}