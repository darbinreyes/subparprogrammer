# Simple assembly program.
# Main function demontrates System V calling convention for x64.
.section __TEXT,__text
.globl _main

_main:

  pushq %rbp # System V calling convention for x64
  movq %rsp, %rbp
  subq $4, %rsp # Adjust stack for 32 bit local variable.
  movl $2, -4(%rbp) # By convention, we initialize local variables via frame pointer.
  addq $4, %rsp # %rsp is callee saved, restore its value.
  movl $3, %eax # Return %3
  popq %rbp
  retq
