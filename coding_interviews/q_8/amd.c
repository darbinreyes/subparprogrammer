/*
initial bring up
not uefi work
power management
server systems

--- core server team ---
arm proc.
boots - sys. management unit
arm proc -
io die
--- fw.

--- baskar - dx/io
*/




/*

// count the number of set bits https://cs-fundamentals.com/tech-interview/c/c-program-to-count-number-of-ones-in-unsigned-integer

The key bit of magic is n = n & (n - 1)

this expression clears all the lower order bits that have already been counted
while leaving any high order bits that are set untouched.
*/

/*

input = 0101b , output = 2

c = 0, n = 0101b

n != 0
c++, c = 1

n = n & (n - 1) = 0101b & (0100b) = 0100b

n != 0

c++, c = 2

n = 0100b & (0011b) = 0000b

done.

############################

input = 1101b , output = 3

c++, c = 1

n = 1101b & 1100b = 1100b

c++, c = 2

n = 1100b & 1011b = 1000b

c++, c = 3

n = 1000b & 0111b = 0000b

done.


*/

/*

lookup table method

i = 0 -> 255
t = [0, 0, ...]
t[i] = (i & 1) + t[i/2]
t[0] = 0 & 1 + t[0/2] = 0 + 0 = 0
t[1] = 1 & 1 + t[1/2] = 1 + 0 = 1
t[2] = 2 & 1 + t[2/2] = 0 + t[1] = 0 + 1 = 1


*/

// clear the lower n bits of given value. https://www.geeksforgeeks.org/bit-tricks-competitive-programming/
/*

They key bit magic involved in this questions is knowing that a power of two
minus 1 results a bit pattern with all 0's followed by all 1's. In particular,
if the power of two is n, then 2^n - 1 = "1's in the n least significant bits."
After that, bit wise not'ing the result gives you the desired mask for clearing
the lower bits.

For the same operation on the bits from MSB down to bit m,

//////

76543210
 ^
 m

1 << 6 == 01000000
01000000 - 1 = 00111111

mask = (1 << m) - 1

v &= mask;


*/

/*

input v = 0111, n = 3 = 0011b, output = v = 0000b // desired mask 1000b
input v = 0111, n = 2 = 0010b, output = v = 0100b // desired mask 1100b
input v = 0111, n = 1 = 0001b, output = v = 0110b // desired mask 1110b


mask = ~((1 << i+1) - 1 ) = ~((1 << n-1+1) - 1)
= ~((1 << 3) - 1) = ~((1000b) - 1) = ~(0111b) = 1000b

*/

/*

clearing from 7th to 6th bit in a byte

76543210

7-i + 1 = 7 - 6 + 1 = 2
int t = 0;
t = ~t;
t = t >> 1;
for (int i = 0; i < 2; i++) {
  v = v & ~(0x80 >> i)
}

*/
// mem. regions and registers. // recompile. // elf disassembly //
// same



uint32_t a;
uint32_t b;

Summary : input pointers to these variables
Depending on the 28th bit in variable a we invert 16 th and 23rd bit of varibale

// xor
// 0 0 = 0
// 0 1 = 1 <<
// 1 0 = 1
// 1 1 = 0 <<

#define CONDITION_BIT (1 << 28)
#define INVERT_BIT0 (1 << 16)
#define INVERT_BIT1 (1 << 23)


void invert(uint32_t *a, uint32_t *b) {
// if 28th is set invert of a, else do not invert.

  if (*a & CONDITION_BIT) {
      // invert - use xor
    *b = *b ^ (INVERT_BIT0 | INVERT_BIT1);

    //*b = *b ^ INVERT_BIT1;
  }
}







int is_little_endian(void) {
    unsigned int v = 1;
  unsigned char *p;

  p = &v;

  if (*p == 1)
      return 1; // is little endian.

  return 0; // big endian.




}

/*

upper case to lower case ASCII

c |= ' '; // c |= 0x20 = 0010 0000b

so the difference between 'A'=0x41=0100 0001 and 'a'=0x61=0110 0001 is that the 5th bit is set in 'A' vs. 'a'.

which is equivalent to adding 2^5 = 32 = 0x20 to 'A'.
/////
[0-1]*2^1 + [0-1]*2^0
////
[0-15]*16^1 + [0-15]*16^0

*/


