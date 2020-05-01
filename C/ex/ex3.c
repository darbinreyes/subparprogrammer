/**
 Bit manipulation and numeric representation exercises.

Exercise ideas:
Bit set
bit clear
bit toggle
using #define
using bit packed structure
hex to decimal
hex to binary
itoa but hex output , variations on this.

**/

#include <stdio.h>
#include <assert.h>

/**
  Set (to 1) the specified bit in the given integer.

  @param[in] InVal   The given integer.
  @param[in] BitIndex  The index of the bit to set.

  @return  InVal after setting the specified bit.

**/
unsigned int
SetBit(
  unsigned int InVal,
  size_t       BitIndex
  ) {
/*
The standard way of setting a bit is to use a bit wise OR operator.
0 = 0|0
1 = 0|1
1 = 1|0
1 = 1|1
*/
// determine the number of bits in InVal
#define NUM_BITS_UINT (sizeof(InVal) * 8)
#define MAX_BIT_INDEX_UINT ((NUM_BITS_UINT) - 1)
  assert(sizeof(unsigned int) == 4);

  if(BitIndex > MAX_BIT_INDEX_UINT) {
    // By specification, no bit is set if BitIndex is out of range.
    return InVal;
  }
  // To set BitIndex = 3 in 0b0000, take OR with 0b0001 << 3, hence left-shift == BitIndex.
  unsigned int TmpBit = 0x01;

  return (InVal | (TmpBit << BitIndex));
}

void
Test_SetBit(
  void
  ) {
  unsigned int InVal, Ret;
  size_t       BitIndex;

  printf("%s\n", __FUNCTION__);
  InVal = 0;
  BitIndex = 0;
  Ret = SetBit(InVal, BitIndex);
  assert(Ret == 1U);

  InVal = 0;
  BitIndex = 1;
  Ret = SetBit(InVal, BitIndex);
  assert(Ret == 2U);

  InVal = 0;
  BitIndex = 8;
  Ret = SetBit(InVal, BitIndex);
  assert(Ret == 256U);

  InVal = 0;
  BitIndex = MAX_BIT_INDEX_UINT;
  Ret = SetBit(InVal, BitIndex);
  assert(Ret == 2147483648U);

  InVal = 0;
  BitIndex = MAX_BIT_INDEX_UINT + 1;
  Ret = SetBit(InVal, BitIndex);
  assert(Ret == 0U);

  InVal = 0xDEADBEEF;
  BitIndex = 7;
  Ret = SetBit(InVal, BitIndex);
  assert(Ret == 0xDEADBEEFU);

  InVal = 0xDEADBEEF;
  BitIndex = 8;
  Ret = SetBit(InVal, BitIndex);
  assert(Ret == 0xDEADBFEFU);
  printf("%s Done\n", __FUNCTION__);
}
/**
Test cases:
InVal = 0, BitIndex = 0, returns 1.
InVal = 0, BitIndex = 1, returns 2.
InVal = 0, BitIndex = 8, returns 256.
InVal = 0, BitIndex = MAX, returns 2^MAX. // if sizeof(unsigned int) = 4 bytes, num_bits = 4 bytes * 8 bits/byte = 32 bits, MAX = num_bits - 1 = 32 - 1.
InVal = 0, BitIndex = > MAX , returns 0. // No bit is set by specification.
InVal = 0xDEADBEEF, BitIndex = 7, returns 0xDEADBEEF.
InVal = 0xDEADBEEF, BitIndex = 8, returns 0xDEADBFEF.

**************************************************
// What is 0xDEADBEEF in binary representation? //

0=0x0=0b0000 // 8 4 2 1
...
9=0x9  =0b1001
10=0xA =0b1010
11=0xB =0b1011
12=0xC =0b1100
13=0xD =0b1101
14=0xE =0b1110
15=0xF =0b1111
16=0x10=0b0001 0000

0xD =0b1101
0xE =0b1110
0xA =0b1010
0xD =0b1101
0xB =0b1011
0xE =0b1110
0xE =0b1110
0xF =0b1111

therefore, 0xDEADBEEF = 0b1101 1110 1010 1101 1011 1110 1110 1111

0xDEADBEEF after setting bit 8 = 0xDEADBFEF

**************************************************


**/

/**

  Same as above but implemented using a #define.

**/

/**
  Same as above but using bit packed structure.
**/

/**
  Same as above but clear (set to 0) the specified bit.
**/

/**
  Convert "0xDEADBEEF" to its decimal representation "0d____"
**/

int main(void) {

  Test_SetBit();

  return 0;
}