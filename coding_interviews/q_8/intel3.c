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