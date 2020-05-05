/**

  Experimentation with bit fields.

**/

#include <stdio.h>
#include <assert.h>

/**
  Set (to 1) the specified bit in the given integer.

  @param[in] InVal   The given integer.
  @param[in] BitIndex  The index of the bit to set.

  @return  InVal after setting the specified bit.

**/
void
TestBitFields(
  void
  ) {
  /**
  KNR notes on bit-fields.
  * bit-field - adjacent bits in an implementation defined storage unit called a word.
  * should use unsigned explicitly.
  * almost everything about them is implementation dependent.
  * whether a field overlaps a word boundary is implementation defined.
  * unnamed bit fields can be used for padding.
  * special width of 0 can be used to force alignment to the next word boundary.
  * it is machine dependent whether bit fields are filled from left to right or vice versa.
  * only type int is allowed
  **/
struct _BitPacked {
  unsigned int Bit0:1;
  unsigned int Bit1:1;
  unsigned int Bit2:1;
  unsigned int Bit3:1;
  unsigned int Bit4:1;
  unsigned int Bit5:1;
  unsigned int Bit6:1;
  unsigned int Bit7:1;
  unsigned int :0;
  } TmpBitPacked = {0,1,0,1,0,1,0,1}; // If you provide more initializers than there are bit fields you get a compiler warning. warning: excess elements in struct initializer.

  struct _BitPacked TmpBitPacked2; // The compiler does NOT initialize the bit-fields to 0. Same as the usual automatic variables, you must initialize explicitly.
  TmpBitPacked2.Bit7 = 1;
  // TmpBitPacked = {0,1}; // This doesn't work. error: expected expression. You must initialize at declaration if using curly braces.

  // Can I assign an int to a bit packed struct? ANS: No, even with a cast.
  // TmpBitPacked = (struct _BitPacked) 0x0FU;
  // TmpBitPacked = (struct _BitPacked) InVal;

  // How about the other way around? ANS: No.
  // InVal = (unsigned int) TmpBitPacked;

  printf("%u %u %u %u %u %u %u %u\n", TmpBitPacked.Bit0, TmpBitPacked.Bit1, TmpBitPacked.Bit2, TmpBitPacked.Bit3, TmpBitPacked.Bit4, TmpBitPacked.Bit5, TmpBitPacked.Bit6, TmpBitPacked.Bit7);
  printf("%u %u %u %u %u %u %u %u\n", TmpBitPacked2.Bit0, TmpBitPacked2.Bit1, TmpBitPacked2.Bit2, TmpBitPacked2.Bit3, TmpBitPacked2.Bit4, TmpBitPacked2.Bit5, TmpBitPacked2.Bit6, TmpBitPacked2.Bit7);
  /*
  if(TmpBitPacked != TmpBitPacked2) { //  error: invalid operands to binary expression
    printf("You CAN'T compare structures containing bit fields.\n");
  }
  */

  struct _NormalStruct {
    int member;
  } TmpStruct, TmpStruct2;
  TmpStruct.member = 2;
  TmpStruct2.member = 3;
  /*
  if(TmpStruct != TmpStruct2) { //  error: invalid operands to binary expression
    printf("You CAN'T compare normal structures either.\n");
  }
  */

  TmpStruct2 = TmpStruct;
  printf("You CAN assign structs. %d.\n", TmpStruct2.member);
  TmpBitPacked2 = TmpBitPacked;
  printf("You CAN assign structs, even if they contain bit-fields.\n");
  printf("%u %u %u %u %u %u %u %u\n", TmpBitPacked2.Bit0, TmpBitPacked2.Bit1, TmpBitPacked2.Bit2, TmpBitPacked2.Bit3, TmpBitPacked2.Bit4, TmpBitPacked2.Bit5, TmpBitPacked2.Bit6, TmpBitPacked2.Bit7);

  // Does the size of a bit packed structure equal the sum of its member sizes?
  assert(sizeof(struct _BitPacked) == sizeof(unsigned int)); // Pass
  assert(sizeof(struct _NormalStruct) == sizeof(int));

  struct _NormalStruct2 {
    int member;
    char member2;
  }; // Does sizeof(struct _NormalStruct2) = sizeof(int) + sizeof(char)? ANS: No. // unless you use #pragma pack(1)
  printf("%lu vs. %lu.\n", sizeof(struct _NormalStruct2), sizeof(int)+sizeof(char)); // Prints "8 vs. 5." // FYI: format specifier %lu == %zu

}

int main(void) {
  TestBitFields();
  return 0;
}