/*!
    @discussion Count the number of set bits.
*/

#include <assert.h>

/* Scratch Work
v = 1010 , n = 2
v = 1000 , n = 1

// The magic bit manipulation is v = v & (v - 1)

v = 1000 , n = 1

v - 1 == 0111B

v = 1000B & 0111B == 0000B.

Done.

*/

int num_set_bits(int v) {
    int c;

    for (c = 0; v; v &= (v - 1))
        c++;

    return c;
}

int main(void) {
    int v = 0xA;
    assert(num_set_bits(v) == 2);

    v = 0x8;
    assert(num_set_bits(v) == 1);

    return 0;
}