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
pusha ; save register values
and dx, 0x000f
cmp dx, 10
jl is_decimal

cmp dx, 16
jl is_hex

popa
ret ; Out of nibble range. Should not occur.

is_hex:
mov cx, dx
sub cx, 10
add cx, 'a' ; cx contains our character.
jmp update_str

is_decimal:
mov cx, dx
add cx, '0' ; cx contains our character.
jmp update_str

update_str:
mov bx, HEX_OUT
add bx, 5
mov dx, [bx]
mov dl, cl
mov [bx], dx

mov bx, HEX_OUT ; print the string pointed to
call print_string ; by BX

popa ; restore register values
ret

%include "print_string.asm"

; global variables
HEX_OUT: db '0x0000', 0

; 0 padding and magic number.

times 510-($-$$) db 0
dw 0xaa55