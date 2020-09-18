; A boot sector program that bootstraps kernel_0.c in 32 bit protected mode.

[org 0x7c00] ; Tell assembler where our boot sector will reside in memory.

KERNEL_OFFSET equ 0x1000 ; This is where we will load our kernel.

mov [BOOT_DRIVE], dl ; By convention, the BIOS sets dl to the boot drive #.
                     ; This drive is also where our kernel resides.

mov bp, 0x9000 ; Stack init.
mov sp, bp

mov bx, MSG_REAL_MODE ; Print.
call print_string

call load_kernel ; Load our kernel from disk to memory.

jmp $ ; Infinite loop.

%include "ch1-ch3/print_string.asm"

[bits 16] ; Some of the includes above contain the [bits 32] assembler directive.

load_kernel:

mov bx, MSG_LOAD_KERNEL ; Print.
call print_string

ret


; Global variables.
BOOT_DRIVE db 0
MSG_REAL_MODE db "Started in 16 bit real mode bruh.", 0xa, 0x0d, 0
MSG_PROT_MODE db "We are in 32 bit protected mode. Light weight!", 0
MSG_LOAD_KERNEL db "About to load the kernel into memory son.", 0

; Boot sector 0 padding and magic number.
times 510-($-$$) db 0
dw 0xaa55