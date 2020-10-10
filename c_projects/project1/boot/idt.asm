; Our interrupt descriptor table (IDT).
; This configures ...

; - - - - - - - Intel SDM Vol.1.Ch.6.5.1 - - - - - -
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
