// test
// input - unsigned int, output input with
// 1010 -> 0101
// 1

unsigned int swap_adj_bits (unsigned int v) {

    int num_bits = sizeof(v) * 8;
    unsigned int t0, t1;
    int i;


    // 1010
    // 3210
    // 0101
    // 0x55555555
    t0 = v & 0xAAAAAAAA;
    t1 = v & 0x55555555;
    v = (t0 >> 1) | (t1 << 1);

    // for (i = 0; i < num_bits/2; i++) {
    //     t0 = v & (1 <<  i);
    //     t1 = v & (1 << (i + 1));

    //     v &=  ~(1 <<  i);
    //     v &= ~(1 << (i + 1));

    //     //if (t0)
    //       //  v |= (1 << (i + 1));
    //     v |= t0 << 1;
    //     //if (t1)
    //       //  v |= (1 <<  i);
    //     v |= t1 >> 1;

    // }

    return v;
}