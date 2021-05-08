/*!
    @header memmove

*/
#include <assert.h>
#include <stdlib.h>

int main(void) {
    return 0;
}

typedef int word_t;

/*!

Important:

properly handle overlapping src+dst. Either use a temp. buffer, or, better,
if src < dst , copy backwards.

0   1  2  3  4
[ ][ ][ ]
      [ ][ ][ ]
else copy forwards (the usual way)

performance improvement. if src+dst are word aligned, copy words at a time
instead of bytes at a time.

*/
void *memmove(void *dst, const void *src, size_t len) {
    size_t i, rb;
    int is_wa;
    const char *cs;
    char *cd;
    // assuming size of a word == sizeof(int)
    const word_t *ws;
    word_t *wd;

    if (dst == NULL || src == NULL) {
        assert(0);
        return NULL;
    }

    if (len == 0)
        return dst;

    if (src == dst)
        return dst;

    is_wa = 0;

    cs = (const char *) src;
    cd = (char *) dst;

    if ((unsigned long)cs % sizeof(word_t) == 0 || (unsigned long)cd % sizeof(word_t) == 0) {
        is_wa = 1;
        ws = (const word_t *) src;
        wd = (word_t *) dst;
    }

    if (src < dst) {
        // copy backward
        if (is_wa) {
            // check if src+dst are word aligned, if so, copy words at a time.
            rb = len % sizeof(word_t);
            for (i = len - rb; i > 0; i--) {
                wd[i-1] = ws[i-1];
            }
            // len = 10, rb = 2, sizeof(word_t) == 4.
            // i = 10; i > 8, 10 9 8, // 9, 8
            // copy any remainder bytes.
            for (i = len; i > len - rb; i--) {
                cd[i-1] = cs[i-1];
            }
        } else {
            // not word aligned, copy bytes at a time.
            for (i = len; i > 0; i--) {
                cd[i-1] = cs[i-1];
            }
        }
    } else {
        // copy forward
        if (is_wa) {
            // check if src+dst are word aligned, if so, copy words at a time.
            rb = len % sizeof(word_t);
            for (i = 0; i < len - rb; i++) {
                wd[i] = ws[i];
            }
            // copy any remainder bytes.
            for (i = len - rb; i < len; i++) {
                cd[i] = cs[i];
            }
        } else {
            // not word aligned, copy bytes at a time.
            for (i = 0; i < len; i++) {
                cd[i] = cs[i];
            }
        }
    }

    return dst;
}