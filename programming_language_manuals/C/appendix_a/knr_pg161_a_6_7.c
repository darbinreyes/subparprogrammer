/*

A.6.7 Void.

Can you declare a variable of type void? ANS: No.

Can you cast a non-void function return value to type void ? ANS: Yes.

*/

#include <stdio.h>

int doo(void) {
  return 1;
}

int main(void) {
  // void v; // Compiler error.

  printf("Dijkstra.\n");

  (void) doo(); // No compiler error.

  return 0;
}