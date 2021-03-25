/* idiff: interactive diff */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

char *progname;
#define HUGE 10000 /* large number of lines */

FILE *efopen(char *file, char *mode);

int main(int argc, char **argv) {
    FILE *fin, *fout, *f1, *f2;
    char buf[BUFSIZ];
    char diffout[] = "idiff.XXXXXX";

    progname = argv[0];

    if (argc != 3) {
        fprintf(stderr, "Usage: idiff file1 file2\n");
        exit(1);
    }

    f1 = efopen(argv[1], "r");
    f2 = efopen(argv[2], "r");
    fout = efopen("idiff.out", "w");
    mktemp(diffout);
    sprintf(buf, "diff %s %s >%s", argv[1], argv[2], diffout);
    system(buf);
    fin = efopen(diffout,"r");
    idiff(f1, f2, fin, fout);
    unlink(diffout);
    printf("%s output in file idiff.out\n", progname);
    exit(0);
}

FILE *efopen(char *file, char *mode) {
    FILE *fp;

    if ( (fp = fopen(file, mode)) != NULL )
        return fp;
    fprintf(stderr, "%s: can't open file %s mode %s\n", progname, file, mode);
    exit(1);
}

void idiff(FILE *f1, FILE *f2, FILE *fin, FILE *fout) { /* process diffs */

}