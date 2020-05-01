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

// http://collabedit.com/hxyvf

// input
// lower = 14
// upper = 20
// output
// 2

//Hello

// testing 123

// Input (L = 14, U = 20)
//Output = 2
// 0-9, 10 - A, 11 - B, 12 - C, 13 - D, 14 - E, 15 - F, // 16 - F1, // oops.
// 16 - 0x10, 17 - 0x11,
// 0d-18-19-20-21-22-23-24-25-26-27-28-29-30-31-32
// 0x-12-13-14-15-16-17-18-19-1A-1B-1C-1D-1E-1F-20

// 0xFA = 0d254
// 0xFF = 0d255 = 2^8 - 1.
// 0x100 = 0d256

//


/*

16 / 16 = 1;
1 % 16 = 1;

17 / 16 = 1;
1 % 16 = 1;

32 / 16 = 2;
2 % 16 = 2;

255 / 16 = (2^8 - 1) / 2^4 = 2^4 - 1/(2^4) = 16 - 0 = 16 // WRONG!
16 + 16 = 32
16 + 16 = 32
64 = 16 * 4
128 = 16 * 8
200 + 40 + 16 = 256 = 16 * 16
240 = 16 * 15
therefore, 255 / 16 = 15
15 % 16 = 15 // = 0xF

therefore, division by 16 followed by modulus by 16,this should extract the hexits beyond the first hexit.



// for 0d0-0d15

rem = i % 10;

count = 0;

if(rem => 0 && rem <= 5) { // rem = 0, A, rem = 5 , F
  count++;
}

// for 0d26-0d28
26 % 10 == 6,
26 % 16 == 4 + 6 == 10 // 0xA == 0d10
31 % 16 == 4 + 10 + 1 == 15 // does 0x1F % 16 == 15? ANS: Yes.

// so maybe this works? - need to test if/how it works for e.g. 0xFF, probably want to divide by 16 then take modulus by 16.

r = i % 16;
count = 0;

if(i >= 10 && i <= 15) {
  count++;
}


*/

/*

14 = 0xE
15 = 0xF
16 = 0x10
17 = 0x11
18 = 0x12
19 = 0x13
20 = 0x14

*/
/**
int ex0(int lower, int upper) {
  int i, count;
  char str[100];


  count = 0;
  for(i = lower; i <= upper; i ++) {
    // c = count number of hex letters in i ????
    // sprintf("%x",i) then inspect string for letters A-F
    sprintf(str, "%X", i); // can't use this.
    // assuming str contains the hex. formated value of i
    // count the number hex digits. // test for chars A-F.
    // itoa() // integer to ascii. // modulus 16
    count += c;
  }

   return count;
}
**/

#include <stdio.h>
#include <assert.h>

// This should count the number of letters that appear in the first hexit.
// test cases: input 14,20 - output 2.
// test cases: input 14,26 - output 3.
int ex0_partial_sol(int lower, int upper) {
  int i, letter_count, r;
  letter_count = 0;

  for(i = lower; i <= upper; i++){
    r = i % 16;
    if(r >= 10 && r <= 15) {
      letter_count++;
    }
  }

  return letter_count;
}


// This should be the complete solution
// test cases: input 14,20 - output 2.
// test cases: input 14,26 - output 3.
// test cases: input 255,255 - output 2.
// test cases: input 254,256 - output 4.
int ex0_sol(int lower, int upper) {
  int i, letter_count, r, tmp;
  letter_count = 0;
  // assuming
  assert(lower >= 0 && upper >= lower);

  for(i = lower; i <= upper; i++) {
    tmp = i;
    // Handle case of > 1 hexits e.g. 0xFF.
    while(tmp > 0) {
      // case tmp = 0d255, r = 15, letter_count++;
      // tmp = 0d255/0d16 = 15, r = 15, letter_count++;
      // tmp = 0d15/0d16 = 0,
      // case tmp = 0d15, r = 15, letter_count++;
      // tmp = 0d15/0d16 = 0,
      r = tmp % 16;
      if(r >= 10 && r <= 15) {
        letter_count++;
      }
      tmp /= 16;
    }
  }

  return letter_count;
}

int main(void) {
  int lower, upper;
  lower = 14;
  upper = 20;
  printf("input %d, %d - output %d.\n", lower, upper, ex0_partial_sol(lower, upper));
  lower = 14;
  upper = 26;
  printf("input %d, %d - output %d.\n", lower, upper, ex0_partial_sol(lower, upper));

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
