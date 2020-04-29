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