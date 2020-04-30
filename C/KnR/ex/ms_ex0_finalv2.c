/**

Microsoft Interview Question: April 29, 2020.
Position: "UEFI/BIOS Firmware Engineer with Microsoft in Redmond, WA."
Alloted solution time: 50 min.

**/

/**

Count the number of letters that occur in the hexadecimal representation of the
numbers in the given range. No standard C library functions allowed. No calculator
allowed, i.e. if necessary, you should must do any conversion between decimal
and hex by hand.

// Sudhakar's Example (Where L = Lower Bound, U = Upper Bound):

"
// Input (L = 14, U = 20)
// Output = 2
"

My Output Explanation ("0d" means decimal notation, "0x" means hexadecimal):
0d14 = 0xE (letter count = 1)
0d15 = 0xF (letter count = 2)
0d16 = 0x10 (letter count = 2)
0d17 = 0x11 (letter count = 2)
0d18 = 0x12 (letter count = 2)
0d19 = 0x13 (letter count = 2)
0d20 = 0x14 (letter count = 2)

letter count = 2, since the only hexadecimal letters that occur in the range are
"E" and "F", hence, output = 2

**/

/**

  My alternate solution inspired by Paige's solution.

**/

#include <stdio.h>
#include <assert.h>

// test cases: input 14,20 - output 2.
// test cases: input 14,26 - output 3.
// test cases: input 255,255 - output 2.
// test cases: input 254,256 - output 4.
// test cases: input 253,256 - output 6.
int ex0_sol(int lower, int upper) {
  int i, letter_count, r, tmp;
  letter_count = 0;

  // Pre-condition: The lower and upper limit are non-negative, and the upper
  // limit is at least the lower limit.
  assert(lower >= 0 && upper >= lower);

  for(i = lower; i <= upper; i++) { // for each number in the range.
    tmp = i;
    while(tmp > 0) { // consider the hexadecimal representation of i ( == tmp).
      r = tmp % 16; // Extract the right most hexadecimal digit.
      if(r >= 10 && r <= 15) { // if the hexadecimal digit is between 0xA (== 0d10) and 0xF (== 0d15), it is a letter.
        letter_count++; // Increment the letter count.
      }
      tmp /= 16; // Move on to the next hexadecimal digit.
    }
  }

  return letter_count;
}

// 0d0 0d1 0d2 0d3 0d4 0d5 0d6 0d7 0d8 0d9 0d10 0d11 0d12 0d13 0d14 0d15 0d16 0d17 0d18 0d19 0d20 0d21 0d22 0d23 0d24 0d25 0d26
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xA  0xB  0xC  0xD  0xE  0xF  0x10 0x11 0x12 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1A

// 0d253 0d254 0d255 0x256
// 0xFD  0xFE  0xFF  0x100
int ex0_solv2(int lower, int upper) {
  int i, letter_count, r, tmp;
  letter_count = 0;

  // Pre-condition: The lower and upper limit are non-negative, and the upper
  // limit is at least the lower limit.
  assert(lower >= 0 && upper >= lower);

  for(i = lower; i <= upper; i++) { // for each number in the range.
    tmp = i;
    // Test the right-most nibble.
    while(tmp > 0) {
      if((tmp & 0x0F) >= 0x0A && (tmp & 0x0F) <= 0x0F) {
        letter_count++;
      }
      tmp = tmp >> 4; // Get the next nibble. // FYI this is equivalent to division by 16.
    }
    /*
    while(tmp > 0) { // consider the hexadecimal representation of i ( == tmp).
      r = tmp % 16; // Extract the right most hexadecimal digit.
      if(r >= 10 && r <= 15) { // if the hexadecimal digit is between 0xA (== 0d10) and 0xF (== 0d15), it is a letter.
        letter_count++; // Increment the letter count.
      }
      tmp /= 16; // Move on to the next hexadecimal digit.
    }
    */
  }

  return letter_count;
}

int main(void) {
  int lower, upper;

  lower = 14;
  upper = 20;
  printf("v2. input %d, %d - output %d.\n", lower, upper, ex0_solv2(lower, upper));
  lower = 14;
  upper = 26;
  printf("v2. input %d, %d - output %d.\n", lower, upper, ex0_solv2(lower, upper));
  lower = 255;
  upper = 255;
  printf("v2. input %d, %d - output %d.\n", lower, upper, ex0_solv2(lower, upper));
  lower = 254;
  upper = 256;
  printf("v2. input %d, %d - output %d.\n", lower, upper, ex0_solv2(lower, upper));
  return 0;
}
