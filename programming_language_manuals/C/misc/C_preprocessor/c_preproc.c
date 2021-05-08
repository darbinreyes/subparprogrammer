/* Source: https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm */
#include <stdio.h>

#define ADD_NUMBERS(a,b) (a+b)


// Breaking up a macro
#define ADD_NUMBERS_2(a,b) \
                            (a+b)

// Stringize
// Turning a macro argument into a string.
// Only works with macros that take arguments.
#define YO_MAMA_JK(a,b,c) #a #b #c

// Token pasting
// One usage is to refer to variable names indirectly.
#define VAR_NAME(varnum) var##varnum
#define VAR_NAME_STR(vn) #vn


int main(void) {
    int s;
    int var2;

    printf("Hello Dijkstra.\n");

    s = ADD_NUMBERS(2,3);

    printf("s = %d.\n", s);

    s = ADD_NUMBERS_2(3,5);

    printf("s = %d.\n", s);

    printf(YO_MAMA_JK(yo, mama, sofat));

    printf(YO_MAMA_JK(yo, mama, so fat)); // Works
    printf(YO_MAMA_JK(yo, mama, sofat) "\n");

    var2 = 7;

    printf("%s = %d\n", VAR_NAME_STR(var2), VAR_NAME(2));

    return 0;
}