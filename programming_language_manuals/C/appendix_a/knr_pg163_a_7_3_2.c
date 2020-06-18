/*

  A.7.3.2 Function Calls.

*/

#include <stdio.h>

int doo(int x) {
  printf("Dijkstra.\n");
  return x;
}


int main(void) {
  int (*poo)(int);

  // A.7.3.2 Function Calls. "an explicit * operator was required to call through pointers to functions."
  poo = doo;
  // *poo(2); // Expect this works. WRONG. Compiler "error: indirection requires pointer operand('int' invalid)".
  (*poo)(20); // Expect same as line above. WRONG. It works. Since function call () operator binds tighter than "*". The line above attempt to dereference a type = int, which is not a pointer, hence the compiler error.
   return 0;
}