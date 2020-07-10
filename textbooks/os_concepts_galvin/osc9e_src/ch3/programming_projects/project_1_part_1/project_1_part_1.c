#include <stdio.h>
#include <string.h>

#define LINE_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int should_run = 1;
    char line[LINE_BUFFER_SIZE];
    char *l;

    while (should_run) {
        printf("darbinsshell> ");

        /* Get a line of input */
        line[0] = '\0';
        l = fgets(line, LINE_BUFFER_SIZE, stdin);

        /* Check if fgets encountered an error */
        if (l == NULL && ferror(stdin)) {
            fprintf(stderr, "fgets error. Bye.\n");
            return 1;
        }

        if (l == NULL && feof(stdin)) {
            fprintf(stderr, "fgets got eof. Bye.\n");
            return 3;
        }

        /* Check if the input line was too long */
        if (strlen(line) == LINE_BUFFER_SIZE - 1 && line[LINE_BUFFER_SIZE - 2] != '\n') {
            fprintf(stderr, "Input line was too long.\n");
            return 2;
        }

        printf("You entered: %s", line);

        /* Check is the user wants to exit */
        if(strcmp(line, "exit\n") == 0) {
            printf("Ok. Goodbye!\n");
            should_run = 0;
        }
    }

    return 0;
}