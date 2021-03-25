/* zap: interactive process killer */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

char *progname; /* program name for error message */
char *ps = "ps -a"; /* system dependent */

char ttyin(void);
int strindex(char *s, char *t);

int main (int argc, char **argv) {
    FILE *fin;
    char buf[BUFSIZ];
    int pid;

    progname = argv[0];

    if ((fin = popen(ps, "r")) == NULL) {
        fprintf(stderr, "%s: can't run %s\n", progname, ps);
        exit(1);
    }

    fgets(buf, sizeof buf, fin); /* get header line  */
    fprintf(stderr, "%s", buf);

    while (fgets(buf, sizeof buf, fin) != NULL)
        if (argc == 1 || strindex(buf, argv[1]) >= 0) {
            buf[strlen(buf) - 1] = '\0'; /*suppress \n */
            fprintf(stderr, "%s? ", buf);
            if (ttyin() == 'y') {
                sscanf(buf, "%d", &pid);
                kill(pid, SIGKILL);
            }
        }

    exit(0);
}

FILE *efopen(char *file, char *mode) {
    FILE *fp;

    if ( (fp = fopen(file, mode)) != NULL )
        return fp;
    fprintf(stderr, "%s: can't open file %s mode %s\n", progname, file, mode);
    exit(1);
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

int strindex(char *s, char *t) {
    int i, n;

    n = strlen(t);

    for (i = 0; s[i] != '\0'; i++)
        if (strncmp(s+i, t, n) == 0)
            return i;

    return -1;
}