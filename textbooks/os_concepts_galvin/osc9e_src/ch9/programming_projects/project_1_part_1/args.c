#include <assert.h>

int valid_args (int argc, const char * const * const argv) {
    if (argc < 1 || argv == NULL) {
        assert(0);
        return 1;
    }

    if (argc != 1 && argc != 2) {
        printf("Usage 1: ./a.out. The default input filename is "\
               "addresses.txt.\n");
        printf("Usage 2: ./a.out addresses.txt. addresses.txt can be any "\
                "filename.\n");
        return 1;
    }
}