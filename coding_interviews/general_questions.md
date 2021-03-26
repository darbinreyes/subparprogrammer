Questions that come up but are not strictly about writing code

* What is virtual memory?
    * Virtual memory is a memory management scheme that allows a program to execute without being completely in memory. A consequence of this is that programs can execute which are bigger the physical memory. The main idea is to use demand-paging, and extension of paging. Its implementation involves structures called a page table and TLB.


* What is volatile in C?


* What is a thread?
    * What is a process? A process is a program in execution. What is a thread? A thread is the part of a process that consists of a register set and stack. When a process has more than one register set and stack, the process is called multithreaded.