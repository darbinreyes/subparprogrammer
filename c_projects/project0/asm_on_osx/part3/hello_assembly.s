# Simple assembly program.
# Main function that calls the write system call, i.e.:
#  ssize_t write(int fildes, const void *buf, size_t nbyte);

.section __TEXT,__text
.globl _main
_main:
  pushq %rbp
  movq %rsp, %rbp
  movl $0x2000004, %eax # system call $4 with $0x2000000 offset. See comments at bottom of this file.
  movl $1, %edi # set 1st argument to stdout fd.
  movq str@GOTPCREL(%rip), %rsi # set 2nd argument to string pointer. GOT = (Global Offset Table). https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/MachOTopics/1-Articles/x86_64_code.html
  movq $23, %rdx
  syscall # issue a system call.
  movl $7, %eax # Return 7 from exit.
  popq %rbp
  retq

.section __DATA,__data
str:
  .asciz "Hello Edsger Dijkstra.\n"

# System call numbers can be "found in /usr/include/sys/syscall.h".
# On my machine that file is elsewhere, it occurs in many places.
# Here's one: "/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/sys/syscall.h"
## define SYS_syscall        0
## define SYS_exit           1
## define SYS_fork           2
## define SYS_read           3
## define SYS_write          4
## define SYS_open           5
## define SYS_close          6
## define SYS_wait4          7