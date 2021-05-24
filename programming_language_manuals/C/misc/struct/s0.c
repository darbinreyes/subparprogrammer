/*
    The MIPS r3000 manual makes claims about struct sizes, this checks if that is
    true.
    Does the size match the manual, 8 bytes? ANS: Yes
    If not, is it because my host is x64 not MIPS? ANS: The MIPS manual is
    correct.
    I didn't know "long long" was a valid type in C, since long is 8 bytes, is
    it 16 bytes? ANS: sizeof(long long) = 8 bytes, not 16.
    Is long double 16 bytes? ANS: Yes. This was unexpected, but clearly the C
    rules permit it, it is what it is.

@remark Apparently I have misunderstood how the compiler stores structures in
memory. I thought that every member is given a word or a multiple of a word, in
the example, I expected a size of 3 * 4 = 12. The correct/actual size is 8 bytes.
In general, the correct size is arrived at by remembering that each structure
member takes up a number of bytes equal to its size, and each member must reside
at an address that is aligned according to its size (shorts to 2 bytes, ints to
4 bytes, etc.). It is easy to determine where padding bytes will occur by taking
the first member to be at address/offset 0, if the next free byte resides at an
address which is not a multiple of the next member's size, add padding bytes
until it is.

The are only a small number of sizes to consider when determining where padding
bytes will be inserted into a structure for alignment enforcement, the size of
the primitive types: 1, 2, 4, 8, and we can ignore size 1.

A consequence of the above is that #pragma packing a structure to 1 byte may
result in unaligned memory accesses.

One possible cause for my misunderstanding is the fact that if we pass a char as
an argument, it will be expanded to occupy 4 bytes on the stack. In contrast, a
char sized structure member may occupy less than 4 bytes depending on the
byte padding required to ensure members aligned according to their size, as
in the example below.

@TODO
Verify my host is little endian by inspecting the values in the structure.

*/

#include <stdio.h>

int main(void) {
    struct thing {
        char l;
        short c;
        int v;
    } s = {'z', 46, 100000};

    printf("thing has size %lu, long long size = %lu, long double size = %lu\n", sizeof(s), sizeof(long long), sizeof(long double));

    return 0;
}