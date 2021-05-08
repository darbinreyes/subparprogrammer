/*
Remarks
* sizeof operator does not require parens.
* The book uses an older version of the C standard which differs greatly from C99.
* Explicitly reading from /dev/tty works around cases in which standard input has been redirected.
*/
/* pick: offer choice of each argument */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *progname;/* program name for error message */

void pick(char *s);
char ttyin(void);
FILE *efopen(char *file, char *mode);

int main(int argc, char **argv) {
    int i;
    char buf[BUFSIZ];

    progname = argv[0];
    if (argc == 2 && strcmp(argv[1], "-") == 0) /* pick - */
        while(fgets(buf, sizeof buf, stdin) != NULL) {
            buf[strlen(buf) - 1] = '\0'; /* drop newline */
            pick(buf);
        }
    else
        for (i = 1; i < argc; i++)
            pick(argv[i]);
    exit(0);
}


void pick(char *s) {
    fprintf(stderr, "%s?", s);
    if (ttyin() == 'y')
        printf("%s\n", s);
}

char ttyin(void) { /* process response from /dev/tty (version 1) */
    char buf[BUFSIZ];
    FILE *efopen();
    static FILE *tty = NULL;

    if (tty == NULL)
        tty = efopen("/dev/tty", "r");
    if (fgets(buf, BUFSIZ, tty) == NULL || buf[0] == 'q')
        exit(0);
    else
        return buf[0];
}

FILE *efopen(char *file, char *mode) {
    FILE *fp;

    if ( (fp = fopen(file, mode)) != NULL )
        return fp;
    fprintf(stderr, "%s: can't open file %s mode %s\n", progname, file, mode);
    exit(1);
}