  .section  __TEXT,__text,regular,pure_instructions
  .build_version macos, 10, 15  sdk_version 10, 15, 4
  .globl  _main                   ## -- Begin function main
  .p2align  4, 0x90
_main:                                  ## @main
  .cfi_startproc
## %bb.0:
  pushq %rbp # push caller's rbp. rbp is callee saved.
  .cfi_def_cfa_offset 16
  .cfi_offset %rbp, -16
  movq  %rsp, %rbp # set rbp to top of stack.
  .cfi_def_cfa_register %rbp
  subq  $48, %rsp # subtract 48 from the top of stack. Makes space for local variables.
  movl  $0, -4(%rbp) # initialize local variable to 0 in the frame.
  movl  %edi, -8(%rbp) # save 32 bit first argument register to frame.
  movq  %rsi, -16(%rbp) # save second argument register to frame.
  movl  $5, -28(%rbp) # initialize local variable to 5.
  movl  $7, -32(%rbp) # initialize local variable to 7.
  movl  $0, -36(%rbp) # initialize local variable to 0.
  movl  -28(%rbp), %eax # move local variable value to 32 bit result register eax.
  addl  -32(%rbp), %eax # add local variable to other local variable, place result in 32 bit result register eax.
  movl  %eax, -36(%rbp) # place result of addition in local variable in frame.
  movl  $16, %edi # write value 16 to 32 bit first argument register edi. 16 = sizeof(int)*4= 4*4=16.
  callq _malloc # call malloc function with argument above, edi.
  xorl  %ecx, %ecx # zero out 32 bit 4th argument register ecx. ecx is also a 32 bit scratch register.
  movq  %rax, -24(%rbp) # place the value returned by malloc function in a local variable in the frame.
  movq  -24(%rbp), %rax # redundant instruction, recall optimizations were disabled. Places return value of malloc from the frame into register rax.
  movl  $2, (%rax) # write 32 bit value 2 at the memory address in rax, this is the heap.
  movq  -24(%rbp), %rax # same redundant instruction as above, recall optimizations were disabled. Places return value of malloc from the frame into register rax.
  movl  $3, 4(%rax) # write 32 bit value 3 at the memory address in rax+4(above previous value), this is the heap.
  movq  -24(%rbp), %rax # same redundant instruction as above, recall optimizations were disabled. Places return value of malloc from the frame into register rax.
  movl  $5, 8(%rax) # write 32 bit value 5 at the memory address in rax+8(above previous value), this is the heap.
  movq  -24(%rbp), %rax # same redundant instruction as above, recall optimizations were disabled. Places return value of malloc from the frame into register rax.
  movl  $7, 12(%rax) # write 32 bit value 7 at the memory address in rax+12(above previous value), this is the heap.
  movl  %ecx, %eax # 32 bit register ecx was zeroed above, so this zeros 32 bit result register eax
  addq  $48, %rsp # We are done, so pop all our local variables on the stack/frame. Complement of the subq above. This also sets up for the popq %rbp instruction that is next, so the caller's rbp value is restored.
  popq  %rbp # restore caller's rbp.
  retq # return from main().
  .cfi_endproc
                                        ## -- End function
  .section  __TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
  .asciz  "Hello Edsgar Dijkstra."

  .section  __DATA,__data
  .globl  _str                    ## @str
  .p2align  3
_str:
  .quad L_.str


.subsections_via_symbols
