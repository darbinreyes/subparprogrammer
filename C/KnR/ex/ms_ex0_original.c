/**

Microsoft Interview Question: April 29, 2020.
Position: "UEFI/BIOS Firmware Engineer with Microsoft in Redmond, WA."
Alloted solution time: 50 min.

**/
/**

 This is the state of the editor when the interview was terminated 32 minutes
 into the call.

**/
//Hello

// testing 123

// Input (L = 14, U = 20)
//Output = 2
// 0-9, 10 - A, 11 - B, 12 - C, 13 - D, 14 - E, 15 - F, 16 - F1,

/*
14 = 0xE
15 = 0xF
16 = 0x10
17 = 0x11
18 = 0x12
19 = 0x13
20 = 0x14

*/

int ex0(int lower, int upper) {
  int i, count;
  char str[100];


  count = 0;
  for(i = lower; i <= upper; i ++) {
    // c = count number of hex letters in i ????
    // sprintf("%x",i) then inspect string for letters A-F
    sprintf(str, "%X", i);
    // assuming str contains the hex. formated value of i
    // count the number hex digits. // test for chars A-F.
    // itoa() // integer to ascii. // modulus 16
    count += c;
  }

   return count;
}