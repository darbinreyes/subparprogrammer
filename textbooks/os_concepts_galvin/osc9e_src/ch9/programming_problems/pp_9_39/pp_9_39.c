#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int i;
    int ref_str_len = 100;
    int num_page_frames = 3;
    int *ref_str;

    //for(i = 0)

    ref_str = calloc(ref_str_len, sizeof(int));

    if(ref_str == NULL) {
        printf("calloc() returned NULL! Bye!\n");
        return 1;
    }

    sranddev();

    for(i = 0; i < ref_str_len; i++) {
        ref_str[i] = rand()/(RAND_MAX/10 + 1);
    }

    printf("reference string length = %d. number of page frames = %d.\n", ref_str_len, num_page_frames);
    printf("random reference string =\n");

    for(i = 0; i < ref_str_len; i++) {
        printf("%d ", ref_str[i]);
    }

    printf("\n");
}