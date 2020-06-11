/*

  B.5 Utility Functions: <stdlib.h>

*/

// testing getenv()
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  printf("HAY relax guy.\n");

  printf("PATH=%s\n", getenv("PATH"));
  return 0;
}