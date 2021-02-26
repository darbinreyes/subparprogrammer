// input 32-bit value, return number of bits set.

int num_bits_set(/*unsigned*/ int v) {
    int c = 0;

    assert(sizeof(v) == 4); // 8-bit microcontroller - word size 2 . AVR microcontroller.

    int num_bits = sizeof(v) * 8; // 4 * 8 = 32-bits

    // v = 16 = 0001_0000B
    //
    // v - 1 == 0000_1111B
    // v = v & (v - 1)
    // v = 0001_0000B & 0000_1111B
    //   c++; // c = 1;
    // v = 0
    // neg. num. -> rep. in 2-twos complement -> high order bit is the sign bit.
    //
    //
    // -6 ->  1111_1111_xxxx_1010B // 4*8 =32 // 28 - 1's + 2 == // returns 30
    // -6-1 -> 1111_1111_xxxx_1001B = -8+1 = -7
    // 1010B &
    // 1001B
    // 1000B
    // v = -7 = 1111_1111_xxxx_1001B
    // v - 1 = = 1111_1111_xxxx_1000B
    // xxxx_1001B & 1111_1111_xxxx_1000B ==
    // xxxx_1000B = -8
    // v = 0000_ ; // 1


/*

With neg. numbers, in two's complement, to convert to decimal., truncate
all except the last sign bit, then do the usual sum of powers of 2.

e.g. -6 = (signed 8-bit value) 1111_1010B = -1*2**7 + 1*2**6 + 1*2**5 + 1*2**4 + 1*2**3 + 0*2**2 + 1*2**1 + 0*2**0 =
-1*2**7 + 1*2**6 + 1*2**5 + 1*2**4 + 1*2**3 + 1*2**1 = (-1*2**6 + 1*2**5 + 1*2**4 + 1*2**3 + 1*2**2 + 1) * 2**1 =
(-64 + 32 + 16 + 8 + 4 + 1) * 2 = (-32+16+8+4+1) * 2 = (-32+16+13) * 2 = (-32+29) * 2 = (-32+29) * 2 = -3 * 2 = -6.

=? 1010B. ANS: Yes.

1010B = -1*2**3 + 0*2**2 + 1*2**1 + 0*2**0 = -8 + 0 + 2 + 0 = -6.


you can just count the left most sign b


*/
    for (int i = 0; i < num_bits; i++) { // I can do better. This 32-bits -> 32 iter. // But you can do it in less.
    // Little bit fiddling magic -> do in # iter. == number of set bits.
    // v &= (v - 1) ; // That the magic - This will clear each set bit after it has been counted.

        if(v & (1 << i))
            c++;
    }
    // Better imple.
    for (c = 0; v; v &= v - 1) { //
        c++;
    }

    return c;
}

/*

Core OS components -> kernel

Mem. management
Process management
Process scheduling // Thread management
PRocess synchronization services - IPC = interprocess
I/O - device driver management

read to writing to devices -> every device has HW controller
--> device

e.g. PS/2 keyboard controller -> the keyboard's config. e.g. scan code set
status registers -> whether or not a byte has been received
-> interrupts associated with dev. -> interrupt when a key is pressed -> if you have configured interrupts correctly (x86 - IDT)
kb. interrupt occurs -> calls some C function which you have pointed to in the IDT





*/