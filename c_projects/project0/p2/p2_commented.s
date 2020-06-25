  .section  __TEXT,__text,regular,pure_instructions
  .build_version macos, 10, 15  sdk_version 10, 15, 4
  .globl  _main                   ## -- Begin function main
  .p2align  4, 0x90
_main:                                  ## @main
  .cfi_startproc
## %bb.0:
  pushq %rbp # By convention, before this instruction the stack points to the caller's return address.
  # By convention, the first thing a function does is push %rbp on the stack, because %rbp is callee saved.
  # The stack now points to the caller's saved %rbp.
  .cfi_def_cfa_offset 16
  .cfi_offset %rbp, -16
  movq  %rsp, %rbp # By convention, the frame pointer %rbp for the current function points to the place on the stack were we saved the caller's %rbp.
  .cfi_def_cfa_register %rbp
  subq  $48, %rsp # Decrement the stack pointer. Why ? Probably just the amount of space needed for local variables.
  movl  $0, -4(%rbp) # 0's first 4 bytes below frame. Why ?
  movl  %edi, -8(%rbp) # Initialize local variable argc. First argument.
  movq  %rsi, -16(%rbp) # Initialize local variable argv. Second argument.
  movl  $5, -20(%rbp) # Initialize local variable a.
  movl  $7, -24(%rbp) # Initialize local variable b.
  movl  $0, -28(%rbp) # Initialize local variable s.
  movl  -20(%rbp), %eax # s = a + b;
  addl  -24(%rbp), %eax
  movl  %eax, -28(%rbp)
  movl  $16, %edi # Call malloc() with first argument set to 16 = sizeof(int) * 4.
  callq _malloc
  movq  %rax, -40(%rbp) # Set local variable heap_data to value returned by malloc(). By convention, functions return values in %rax.
  movq  -40(%rbp), %rax # Initialize memory returned by malloc(). heap_data[0-3] = 2, 3, 5, 7.
  movl  $2, (%rax)
  movq  -40(%rbp), %rax
  movl  $3, 4(%rax)
  movq  -40(%rbp), %rax
  movl  $5, 8(%rax)
  movq  -40(%rbp), %rax
  movl  $7, 12(%rax)
  movl  $16, %edi # Call malloc() with first argument set to 16 = sizeof(int) * 4.
  callq _malloc
  xorl  %ecx, %ecx # 0's scratch register %ecx. This is also the 4th argument register.
  movq  %rax, -48(%rbp) # Initialize memory returned by malloc(). heap_data2[0-3] = 0xA, 0xB, 0xC, 0xD.
  movq  -48(%rbp), %rax
  movl  $10, (%rax)
  movq  -48(%rbp), %rax
  movl  $11, 4(%rax)
  movq  -48(%rbp), %rax
  movl  $12, 8(%rax)
  movq  -48(%rbp), %rax
  movl  $13, 12(%rax)
  movl  %ecx, %eax # 0's the return register %eax.
  addq  $48, %rsp # Complement of subq above. Ensures that the next instruction pops the caller's %rbp value off the stack.
  popq  %rbp # Pop caller's %rbp off the stack
  retq # Return
  .cfi_endproc
                                        ## -- End function
  .section  __TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
  .asciz  "Hello Edsger Dijkstra."

  .section  __DATA,__data # Beginning of the data section. Contains our global variables str, len, si, and c.
  .globl  _str                    ## @str
  .p2align  3 # See definition of .p2align assembler directive [here](https://developer.apple.com/library/archive/documentation/DeveloperTools/Reference/Assembler/040-Assembler_Directives/asm_directives.html#//apple_ref/doc/uid/TP30000823-TPXREF101). Also [here](https://stackoverflow.com/questions/21546946/what-does-p2align-do-in-asm-code).
  # Advances the the location counter to the next 2^3 = 8 byte boundary.
_str:
  .quad L_.str

  .globl  _len                    ## @len
  .p2align  2
  # Advances the the location counter to the next 2^2 = 4 byte boundary.
_len:
  .long 7                       ## 0x7

  .globl  _si                     ## @si
  .p2align  1
  # Advances the the location counter to the next 2^1 = 2 byte boundary.
_si:
  .short  3                       ## 0x3

  .globl  _c                      ## @c
_c:
  .byte 5                       ## 0x5


.subsections_via_symbols
