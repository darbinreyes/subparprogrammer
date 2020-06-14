  .section  __TEXT,__text,regular,pure_instructions
  .build_version macos, 10, 15  sdk_version 10, 15, 4
  .globl  _main                   ## -- Begin function main
  .p2align  4, 0x90
_main:                                  ## @main
  .cfi_startproc
## %bb.0:
  pushq %rbp # push register RBP to the stack. lldb Check value of RBP before and after this. After should be -8 bytes.
  .cfi_def_cfa_offset 16 # ??? - this might be allocating space on the stack for local variables. In .c I declared 3 ints = 3 * 32 bits = 3 * 4 bytes = 12 bytes + 4 bytes of padding to ensure 16 byte alignment of the stack.
  .cfi_offset %rbp, -16 # ???
  movq  %rsp, %rbp # move value in register RSP (top of the callers frame) to register RBP (base address of current frame). lldb Check value of RSP before this instruction and check value of RBP after this instruction.
  .cfi_def_cfa_register %rbp
  xorl  %eax, %eax # Set to 0 the lower 32 bits of the RAX register a.k.a register EAX.
  movl  $0, -4(%rbp) # 32 bit move imm. value 0 into frame.
  movl  %edi, -8(%rbp) # 32 bit move value in register EDI[?] into frame.
  movq  %rsi, -16(%rbp) # 32 bit move value in register RSI[?] into frame.
  movl  $5, -20(%rbp) # move 32 bit imm. value 5 into frame. This clearly corresponds to the C code local variable initialization.
  movl  $7, -24(%rbp) # move 32 bit imm. value 7 into frame. This clearly corresponds to the C code local variable initialization.
  movl  $0, -28(%rbp) # move 32 bit imm. value 0 into frame. This clearly corresponds to the C code local variable initialization.
  movl  -20(%rbp), %ecx # move 32 bit value from frame (containing value = 5) into register 32 bit register ECX
  addl  -24(%rbp), %ecx # 32 bit add, value from frame (containing value = 7), with value in register ECX (which should be 5), hence the result stored in register ECX = 12.
  movl  %ecx, -28(%rbp) # move value in ECX (= 12) into frame
  popq  %rbp # pop 64 bit value off the stack into register RBP, since the top of the stack is in register RSP, and we have not touched RSP, RSP  still points to the RBP value placed there by the first instruction "pushq"
  retq # The ret instruction pops the return address off the stack and jumps to it.
  .cfi_endproc
                                        ## -- End function

.subsections_via_symbols
