/*

  A.7.1 Pointer Conversion

*/

#include <stdio.h>

int doo(int x) {
  printf("Dijkstra.\n");
  return x;
}


int main(void) {
  int arr[] = {0,1,4,5};
  int **a;
  int *a2;
  int (*poo)(int);


  //a = &arr; // expect type error. incompatible pointer types assigning to 'int **' from 'int (*)[4]'
  //a = arr;  // warning: incompatible pointer types assigning to 'int **' from 'int [4]'

  //a2 = arr++; // expect error. error: cannot increment value of type 'int [4]'
  //a2 = ++arr; // expect error. error: cannot increment value of type 'int [4]'

  //sizeof(arr); // I already know this returns the size in bytes of arr.

  //arr = 0; // expect error. error: array type 'int [4]' is not assignable

  //poo = doo; // Should work. It does.
  //poo(1);
  poo = &doo; // Expect error. WRONG. It works. But does it actually call doo? ANS: It does.
  poo(2);

  return 0;
}