# Simple assembly program.
# Main function that calls the write system call, i.e.:
#  ssize_t write(int fildes, const void *buf, size_t nbyte);
.section __TEXT,__text
.globl _main

_main:

  movl $0x2000004, %eax # system call $4 with $0x2000000 offset. See comments at bottom of this file.
  movl $7, %edi # set the exit code to be $7.
  syscall # issue a system call.

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