// Sum the elements in an array.

#include <stdio.h>

int main(void) {
  int a[] = {2, 3, 5, 7, 11, 13}; // = 41.
  size_t c = sizeof(a)/sizeof(int);
  int i, s;

  s = 0;

  for (i = 0;  i < c; i++) {
    s += a[i];
    
    if(i < c - 1) {
      printf("%d + ", a[i]);
    } else {
      printf("%d = %d\n", a[i], s);
    }
  }

  return 0;
}