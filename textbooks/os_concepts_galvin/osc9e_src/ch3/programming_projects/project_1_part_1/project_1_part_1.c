#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LINE_BUFFER_SIZE 80


int parse_input(char *line, char **args, int max);


int main(int argc, char **argv) {
    char *args[LINE_BUFFER_SIZE/2+1];
    int should_run = 1;
    char line[LINE_BUFFER_SIZE];
    char *l;

    while (should_run) {
        printf("darbinsshell> ");
        // ? fflush(stdout) // The use of this function might be evident after adding fork()+exec() call.

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
        if(parse_input(line, args, sizeof(args)/sizeof(args[0]))) {
            fprintf(stderr, "Input line had too many tokens.\n");
            return 1;
        }

        /* Check is the user wants to exit */
        if(args[0] != NULL && strcmp(args[0], "exit") == 0) {
            printf("Ok. Goodbye!\n");
            should_run = 0;
        }
    }

    return 0;
}

// Returns 0 if successful. At most max - 1 tokens are returned. Returns 1 if there were more than max - 1 tokens in line.
// Parses line into space separated tokens, returns tokens in args.
// The last token in args is indicated by a subsequent NULL pointer.
int parse_input(char *line, char **args, int max) {
    int i = 0;
    char *s;
    s = strtok(line, " \n");

    while (s != NULL && i < max - 1) {
        args[i] = s;
        i++;
        s = strtok(NULL, " \n");
    }

    args[i] = NULL;

    if (s != NULL && i == max - 1) {
        return 1;
    }

    return 0;
}