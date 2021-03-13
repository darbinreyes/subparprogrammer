/*!
    @discussion While reading this:
    https://blog.regehr.org/archives/28
    and
    mainly, this:
    http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2016.html

    I encountered "sigatomic_t", which I could not find in the man pages using
    my usual searching approach. Then I saw this example code, which works fine
    on my Mac:
    https://en.cppreference.com/w/c/program/sig_atomic_t

    This program is for the test on my Mac.
*/

/*!
    @discussion Count the number of set bits.
*/
#include <signal.h>
#include <stdio.h>

sig_atomic_t gTest = 0;

int main(void) {
    gTest = 7;
    printf("gTest = %d\n", gTest);
    return 0;
}