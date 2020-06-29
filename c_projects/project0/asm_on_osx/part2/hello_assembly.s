# Simple assembly program.
# Main function that calls the exit system call using callq instruction instead
# of syscall instruction.
.section __TEXT,__text
.globl _main

_main:

  pushq %rbp # System V calling convention for x64
  movq %rsp, %rbp
  movl $3, %edi # First argument
  callq _exit
