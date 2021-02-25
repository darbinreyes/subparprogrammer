/*!


```
Given:

struct data{

  int a:3; // bit fields 3 bits in size.

  int b:2; // 2

  int c:3; // 3

}; // assuming 32-bit ints -> ->4 bytes.

union {
    float f;
    int i;
}; // size == the greater of sizeof(f) and sizeof(i).
void main(){

  struct data d={2,-6,5}; // This ok if not bit fields // 4 bytes // the compiler may complain that you assigning to bit-fit fields.
  // can I assume this is equivalent to?
  d.a = 2;
  d.b = -6; // definitely legal - bit fields work like small integers 110B // Compiler might warn // otherwise truncate high order bit
  d.c = 5;
// if union  still 4 bytes
// struct vs. union // unions are used for storing different data types in shared store
  assert (sizeof(d) == 4);

  printf("%d %d %d",d.a, d.b, d.c);

} // virtual address?
// in a dem
//a.out >>

// int a[100];

// virtual address -> page number | page offset ->
// 1 page per process.
// if page_table[page number].valid // in memory
// TLB involved -just cache for address translation
// - just like a "normal" instr./data cache small very memory.
// TLB -> associative memory /// with hash table // more expensive!!!
// ->
// GPR -> regis. arithmetic/logical ops. In contrast , purpose specific registers e.g. segment
// -> EAX -> RAX.
// mem. leak ->
// multithreaded program -> recall whats shared vs. not between threads
// shared code section - global variables -> address space
// not shared -> stack
// synch. primitives shared data -> mutex semaphore
// performance -> lock/mutex. -> used prevent race cond. -> errors / bugs -> critical section problem!
// critical section - mutual exclusion.
// deadlock - no progress-> dining philosophers -> 5 philosophers 1 bowl rice

// Proc. mode registers CR0 etc.

// else page fault

// any kind of errors.

void main(){

 1  float pi=3.14; // assume - 4 bytes . // 0xDEADBEFF

 2 int i = 0;

 2 char *ptr; // c

   // sizeof(ptr) == 4 // x86 -> (size of address space) 32-bits -> 4 bytes. // x64 -> 64-bits

 3  ptr=(char *)&pi;  // a//Intel platform // address of pi -> stack // malloc()

 4  for(i=0;i<=7;i++) //

 5    printf("%d ", (*(ptr++)) ); // & = address , * = deref. , post-inc.
 // on increment, since this ptr. to a char , inc. by 1. // inacrementing by the size of the thing pointed to.
// since char * , and sizeof(char) == 1, inc. incre. 1.
 // Intel -> little-endian -> lower mem. addr. points to the low order bits
0xFF
0xBE
0xAD
0xDE
// then  since going betwen the 4-bytes - garbage -
// Intel CPUS - address space limits set by the OS -> GDT - global desc. table.
//
//

}

```
*/

#include <stdio.h>
#include <assert.h>

int main(void);

void test0 (void) {
    //float pi = 3.14;
    int pi = 0xDEADBEEF;

    int i = 0;

    unsigned char *ptr;

    ptr = (unsigned char *) &pi;

    assert(sizeof(void *) == 8);

    printf("%X\n", (unsigned int) &pi); // address of pi
    printf("%X\n", (unsigned int) &i);
    printf("%X\n", (unsigned int) &ptr);
    printf("%X\n", (unsigned int) main);

    for (i = 0; i <= 7; i++){
        printf("(%X)%X ", (unsigned int)ptr, (*(ptr)));
        ptr++;
    }

/* Scratch Work

===

// i = 0 , ptr
// i = 1 , ptr+1
// i = 2 , ptr+2
// i = 3 , ptr+3
// i = 4 , ptr+4, 0x0C = 0000_1100B = 12 + 4 = 16 = 0x10 // We will print value
of the byte at address (&(char*)pi)+4. // Since the stack grows toward lower
memory address, this byte will be the low order byte of whatever happens to be
in the stack above (towards bottom of the stack) our local variable pi. Usually
that is the value of EBP (frame pointer) or EIP (instruction pointer return
address).

===

Stack vars.
<< stack bottom
i   +4
pi  0
ptr
<< stack top

===

*/
    printf("\n");
}

struct data{

  int a:3; // bit fields 3 bits in size.

  int b:2; // 2

  int c:3; // 3

};

int main(void) {
    struct data s = {2, -6, 5};
    test0();

    //s = {2, -6, 5};  // compiler error
    //s.a = 2;  // 0010B
    //s.b = -6; // -6 = -8 + 2 = 1010B -> truncated to 10B = "-2"
    //s.c = 5;  // 0101B -> truncated to 101B = "-3"

    printf("%d %d %d\n", s.a, s.b, s.c); // 2, 2, 5
    /* correct: 2, -2, -3

    Remark:
    This was a little surprising. Bit-fields, if signed, are first truncated to
    the size of the bit fields and the remaining high order bit remains the sign
    bit.
    e.g. 5 = 0101B -> truncated to 3-bits -> 101B = -4 + 1 = -3.

    */

    /* Scratch Work.
      EF BE AD DE
      Assuming i is on the stack after pi: <value of low order byte of i = 0x4>,
      4 0 0 0 .
    */
    return 0;
}