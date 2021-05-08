/*

    * 1. Verify padding in a struct.
        * 4 byte aligned.

    * 2. Verify how to obtain a pointer to the containing struct given  a pointer
         to one of its members.

*/

#include <stddef.h>

struct my_struct { // 1 + 4 + 1 + 4 bytes = 10 bytes
    char c0;
    int i0;
    char c1;
    int i1;
};

typedef struct my_struct _my_struct;

int offset_of_c1(void) {
    struct my_struct s;
    int offset;

    offset = ((char *)&s.c1) - ((char *)&s);
    return offset;
}

#define offset_of(TYPE, MEMBER) ( (size_t) &((TYPE *)0)->MEMBER )

char *container_of(char *member_c1) {

    return member_c1 - offset_of(_my_struct, c1);
}

#define _container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offset_of(type,member) );}) // Apparently the value+type of this block is the value+type of the second statement.

int main(void) {
    struct my_struct s;
    struct my_struct *t;

    s.c0 = 3;
    s.i0 = 5;
    s.c1 = 7;
    s.i1 = 11;

    //t = (struct my_struct *)container_of((char *)&s.c1);

    t = _container_of(&s.c1, _my_struct, c1);

    return 0;
}