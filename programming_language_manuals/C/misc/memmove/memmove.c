/*!
    @header memmove

*/

int main(void) {
    return 0;
}

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
    return NULL;
}