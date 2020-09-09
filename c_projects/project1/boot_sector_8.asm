;
; Question 5. Implementation print_hex.
;

[org 0x7c00] ; Tell assembler where we will be loaded into memory.

mov dx, 0x1fb6 ; store the value to print in dx
call print_hex ; call the function


jmp $ ; Infinite loop.

; prints the value of DX as hex.
print_hex:
    ; TODO : manipulate chars at HEX_OUT to reflect DX

mov bx, HEX_OUT ; print the string pointed to
call print_string ; by BX
ret

%include "print_string.asm"

; global variables
HEX_OUT: db '0x0000', 0

; 0 padding and magic number.

times 510-($-$$) db 0
dw 0xaa55