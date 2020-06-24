# Comments after reading more about x86-64 and System V calling conventions.
  .section  __TEXT,__text,regular,pure_instructions
  .build_version macos, 10, 15  sdk_version 10, 15, 4
  .globl  _main                   ## -- Begin function main
  .p2align  4, 0x90
_main:                                  ## @main
  .cfi_startproc
## %bb.0:
  pushq %rbp # At this point the top of the stack points to the return address.
  # Since %rbp is callee saved by convention, this pushes the register on the stack.
  .cfi_def_cfa_offset 16
  .cfi_offset %rbp, -16
  movq  %rsp, %rbp # By convention, the stack pointer always points to the value most recently pushed on the stack.
  # Therefore the stack currently points to the caller's %rbp value saved on the stack.
  # By convention, the frame pointer of the current function points to the place where the caller's %rbp was saved.
  # By convention, after the saved %rbp value begin local variables.
  .cfi_def_cfa_register %rbp
  xorl  %eax, %eax # Zero out the return register. main() returns 0.
  movl  $0, -4(%rbp) # ?
  movl  %edi, -8(%rbp) # Initialize local variable argc. First argument.
  movq  %rsi, -16(%rbp) # Initialize local variable argv. Second argument.
  movl  $5, -20(%rbp) # Initialize local variable a.
  movl  $7, -24(%rbp) # Initialize local variable b.
  movl  $0, -28(%rbp) # Initialize local variable s.
  movl  -20(%rbp), %ecx # Move value of local variable a to %ecx.
  addl  -24(%rbp), %ecx # Add value of local variable b to %ecx.
  movl  %ecx, -28(%rbp) # Move value in %ecx to local variable s.
  popq  %rbp # Restore caller's %rbp value.
  retq # Return to caller.
  .cfi_endproc
                                        ## -- End function

.subsections_via_symbols
