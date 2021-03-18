/*
    "We used BUFSIZ, which is defined in <stdio.h>, as the size of the input
    buffer."

```
MacBook-Air:ch6.4 darbinreyes$ a.out
BUFSIZ = 1024
```
*/

#include <stdio.h>

int main(void) {
    printf("BUFSIZ = %u\n", BUFSIZ);
    return 0;
}