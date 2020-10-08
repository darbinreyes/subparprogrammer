// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
#include "../drivers/ps_2_ctlr.h"
#include "../drivers/keyboard.h"
#include "../mylibc/mylibc.h"

int main(void) {
    int r;
    unsigned char stat;
    unsigned char b;
    unsigned char sc;
    unsigned char sc2[2];
    char c;
    ps_2_ctrl_stat_t stat2;

    clear_screen();
    print_at("Edsger Dijkstra!\n", 0, 0);

    r = get_ctlr_stat(&stat); // Read status register

    if (r != 0) {
        print("Error 0.\n");
        return 1;
    }

    print_byteb (stat);
    print("\n");

    print("bit packed struct. controller status register.\n");

    while (1) {
    r = get_ctlr_stat((unsigned char *)&stat2); // Read status register

        print("0b");

        if (stat2.par_err)
            print("1");
        else
            print("0");

        if (stat2.rcv_timeout)
            print("1");
        else
            print("0");

        if (stat2.tx_timeout)
            print("1");
        else
            print("0");

        if (stat2.dev_inhibited)
            print("1");
        else
            print("0");

        if (stat2.data_or_cmd)
            print("1");
        else
            print("0");

        if (stat2.sys_flg)
            print("1");
        else
            print("0");

        if (stat2.ibuf_full)
            print("1");
        else
            print("0");

        if (stat2.obuf_full)
            print("1\n");
        else
            print("0\n");
    }

    // while(1) {
    //     r = get_scan_code2(sc2);

    //     if (r != 0) {
    //         print("Error 2.\n");
    //         return 1;
    //     }

    //     if (sc2[1] != 0x00) {
    //         print(" 2 byte sc.");
    //         print("[");
    //         print_byteh(sc2[0]);
    //         print("]");
    //         print("[");
    //         print_byteh(sc2[1]);
    //         print("]");
    //     } else {
    //         print(" 1 byte sc.\n");
    //         print("[");
    //         print_byteh(sc2[0]);
    //         print("]");
    //     }
    // }
    return 0;
}