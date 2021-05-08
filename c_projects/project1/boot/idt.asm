; Our interrupt descriptor table (IDT).
; This configures ...

; - - - - - - - Table 6-1. Exceptions and Interrupts - Intel SDM Vol.1.Ch.6.5.1 - - - - - -
;
; Vector | Mnemonic | Description | Source |
; -------|----------|-------------|--------|
; 0        |  #DE     | Divide Error                               | DIV and IDIV instructions.
; 1        |  #DB     | Debug                                      | Any code or data reference.
; 2        |          | NMI Interrupt                              | Non-maskable external interrupt.
; 3        |  #BP     | Breakpoint                                 | INT3 instruction.
; 4        |  #OF     | Overflow                                   | INTO instruction.
; 5        |  #BR     | BOUND Range Exceeded                       | BOUND instruction.
; 6        |  #UD     | Invalid Opcode (Undefined Opcode)          | UD instruction or reserved opcode.
; 7        |  #NM     | Device Not Available (No Math Coprocessor) | Floating-point or WAIT/FWAIT instruction.
; 8        |  #DF     | Double Fault                               | Any instruction that can generate an exception, an NMI, or an INTR.
; 9        |  #MF     | CoProcessor Segment Overrun (reserved)     | Floating-point instruction.^1
; 10       |  #TS     | Invalid TSS                                | Task switch or TSS access.
; 11       |  #NP     | Segment Not Present                        | Loading segment registers or accessing system segments.
; 12       |  #SS     | Stack Segment Fault                        | Stack operations and SS register loads.
; 13       |  #GP     | General Protection                         | Any memory reference and other protection checks.
; 14       |  #PF     | Page Fault                                 | Any memory reference.
; 15       |          | Reserved                                   | ~ ~ ~
; 16       |  #MF     | Floating-Point Error (Math Fault)          | Floating-point or WAIT/FWAIT instruction.
; 17       |  #AC     | Alignment Check                            | Any data reference in memory.^2
; 18       |  #MC     | Machine Check                              | Error codes (if any) and source are model dependent.^3
; 19       |  #XM     | SIMD Floating-Point Exception              | SIMD Floating-Point Instruction^4
; 20       |  #VE     | Virtualization Exception                   | EPT violations^5
; 21       |  #CP     | Control Protection Exception               | The RET, IRET, RSTORSSP, and SETSSBSY instructions can generate this exception. When CET indirect branch tracking is enabled, this exception can be generated due to a missing ENDBRANCH instruction at the target of an indirect call or jump.
; 22 - 31  |          | Reserved                                   | ~ ~ ~
; 32 - 255 |          | Maskable Interrupts                        | External interrupt from INTR pin or INT n instruction.
;
; - - - - - - -
; NOTES:
; ^1. IA-32 processors after the Intel386 processor do not generate this exception.
; ^2. This exception was introduced in the Intel486 processor.
; ^3. This exception was introduced in the Pentium processor and enhanced in the P6 family processors.
; ^4. This exception was introduced in the Pentium III processor.
; ^5. This exception can occur only on processors that support the 1-setting of the “EPT-violation #VE” VM-execution control.
; "~ ~ ~" means no text given by Intel.
; - - - - - - -

idt_start:
; A trap gate descriptor without an exception handler procedure.
; - - - - - - -
; Offset   ; low order ; Offset to procedure entry point ; 0x00`00.
; Selector ; Segment Selector for destination code segment 0x00`08.
; Reserved ; 0b0`0000.
; constant ; 0b000.
; constant ; 0b111.
; D ; Size of gate ; 1 = 32-bits ;  0b1.
; constant ; 0b0.
; DPL ; Descriptor Privilege Level ; 0b00.
; P ; Segment Present Flag ; 0b0.
; Offset ; high order ; Offset to procedure entry point ; 0x00`00.
;- - - - - - -
; Reminder Intel CPUs are Little-Endian.
;- - - - - - - Default trap gate descriptor 0 - - - - - - -;
dw 0x0000     ; Offset low (15<-0)
dw 0x0008    ; Segment Selector (31<-16)
; 4-byte boundary.
db 00000000b ; constant (7<-5), Reserved (4<-0)
db 00001111b ; P (15)  DPL (14<-13) constant (12)  D (11) constant (10<-8)
dw 0x0000    ; Offset high (31<-16)
;- - - - - - - Default trap gate descriptor 1 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 2 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 3 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 4 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 5 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 6 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 7 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 8 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 9 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 10 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 11 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 12 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 13 - - - - - - -;
dw my_gp_int_handler;dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 14 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 15 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 16 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 17 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 18 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 19 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 20 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 21 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 22 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 23 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 24 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 25 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 26 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 27 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 28 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 29 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000;- - - - - - - Default trap gate descriptor 30 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - Default trap gate descriptor 31 - - - - - - -;
dw 0x0000
dw 0x0008
; 4-byte boundary.
db 00000000b
db 00001111b
dw 0x0000
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
idt_end:

; IDTR
idt_register: ; Holds both the 32-bit base address and 16-bit limit for the IDT

dw idt_end - idt_start - 1 ; The size of our GDT, ALWAYS LESS 1 OF THE TRUE SIZE. ; 16 bits
dd idt_start ; Starting address of our IDT.