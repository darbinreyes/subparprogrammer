;
; Section 3.6.1 Extended Memory Access Using Segments.
; A boot sector program that demonstrates how to use the segment registers to
; access an address space larger than that implied by 16 bit addresses.
; 16 bit address space size = 2^16 = 64 KB.
; Segmented address space size = (max segmented address) + 1
; = (0xffff*16 + 0xffff) + 1
; = (0xffff0 + 0xffff) + 1 = (0x10ffef) + 1 = 0x10fff0.
;