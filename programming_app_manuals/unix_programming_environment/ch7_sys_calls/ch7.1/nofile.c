/*
    Page 206.
    "There is a limit on the number of files that a program may have open
    simultaneously."
    "Look for NOFILE in <sys/param.h>"
*/

#include <stdio.h>
#include <sys/param.h>

int main(void) {

    printf("NOFILE = %d.\n", NOFILE);
    /* OUTPUT:
    NOFILE = 256.
    */
    return 0;
}