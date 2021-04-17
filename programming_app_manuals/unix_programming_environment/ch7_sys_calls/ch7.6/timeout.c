/*
    I've never seen an initialization and a declaration on a single line.
    Will the compiler will complain?
    ANS: No.
    Remark: The compiler also doesn't complain that onalarm () is undefined,
            unless you try to call it.
*/

#include <stdio.h>

/* timeout: set time limit on a process */
int main(int argc, char **argv) {
    int sec = 10, status, onalarm();
    onalarm();
    return 0;
}

int onalarm(void) {
    printf("Ring\n");
    return 0;
}