#include <stdio.h>
/**

  5.9 Pointers vs. Multi-dimensional Arrays

" For b, however, the definition only allocates 10 pointers and does not
initialize them; initialization must be done explicitly, either statically or
with code. "

Is this saying that an automatic array of integers IS initialized to 0 while an
automatic array of pointers to integers is not initialized to 0?

ANS:
No, it works just as with automatic scalars. Automatic arrays are not
initialized to 0, whether they are its an array of integers or an array of
pointers to integers.

**/
int main(void) {
  int a[10][20];
  int *b[10];

  int i, j;

  for (i = 0; i < 10; i++) {
    printf("b[%d] = %p.\n", i, b[i]);
    printf("a[%d][0-19] = ", i);
    for (j = 0; j < 20; j++) {
      printf(" %d", a[i][j]);
    }
    printf(".\n");
  }

  return 0;
}