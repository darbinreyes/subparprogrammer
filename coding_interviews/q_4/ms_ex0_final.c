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

  My solution is the function, ex0_sol() below. The main() function runs 4 test
  cases.

**/

#include <stdio.h>
#include <assert.h>

// test cases: input 14,20 - output 2.
// test cases: input 14,26 - output 3.
// test cases: input 255,255 - output 2.
// test cases: input 254,256 - output 4.
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

int main(void) {
  int lower, upper;

  lower = 14;
  upper = 20;
  printf("input %d, %d - output %d.\n", lower, upper, ex0_sol(lower, upper));
  lower = 14;
  upper = 26;
  printf("input %d, %d - output %d.\n", lower, upper, ex0_sol(lower, upper));
  lower = 255;
  upper = 255;
  printf("input %d, %d - output %d.\n", lower, upper, ex0_sol(lower, upper));
  lower = 254;
  upper = 256;
  printf("input %d, %d - output %d.\n", lower, upper, ex0_sol(lower, upper));
  return 0;
}
