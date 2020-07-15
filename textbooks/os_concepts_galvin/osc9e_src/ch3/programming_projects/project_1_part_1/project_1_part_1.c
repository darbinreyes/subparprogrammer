#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define LINE_BUFFER_SIZE 80


int parse_input(char *line, char **args, int max, int *no_wait);
pid_t run_cmd(char **args, int no_wait);

int main(int argc, char **argv) {
    char *args[LINE_BUFFER_SIZE/2+1];
    int should_run = 1;
    char line[LINE_BUFFER_SIZE];
    char *l;
    int no_wait;
    pid_t pid;

    while (should_run) {
        printf("darbinsshell> ");
        //fflush(stdout); // The use of this function might be evident after adding fork()+exec() call.

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

        //printf("You entered: %s", line);
        if (parse_input(line, args, sizeof(args)/sizeof(args[0]), &no_wait)) {
            fprintf(stderr, "Input line had too many tokens.\n");
            return 1;
        }

        /* Check is the user wants to exit */
        if (args[0] != NULL && strcmp(args[0], "exit") == 0) {
            printf("Ok. Goodbye!\n");
            should_run = 0;
        }

        if (args[0] != NULL) {
            pid = run_cmd(args, no_wait);
            if (pid <= 0) {
                fprintf(stderr, "Command error. Bye.\n");
                return 1;
            }
        }
    }

    return 0;
}

// Returns 0 if successful. At most max - 1 tokens are returned. Returns 1 if there were more than max - 1 tokens in line.
// Parses line into space separated tokens, returns tokens in args.
// The last token in args is indicated by a subsequent NULL pointer.
int parse_input(char *line, char **args, int max, int *no_wait) {
    int i = 0;
    char *s;

    *no_wait = 0;

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


    if (i > 0 && args[i - 1][0] == '&') {
        *no_wait = 1;
        args[i - 1] = NULL; // This prevents the '&' from being interpreted as an argument.
    }

    return 0;
}

/*

    Creates a child process using fork(). The child calls execvp() and the
    parent waits for the child to terminate before returning. If no_wait != 0
    the parent does not wait and instead returns immediately.

*/
pid_t run_cmd(char **args, int no_wait) {
    pid_t pid;
    int stat_loc;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork() error.\n");
    } else if (pid > 0) {
        /* Parent process */
        if(no_wait)
            ;//fprintf(stderr, "Parent not waiting.\n");
        else {
            wait(&stat_loc);
            fprintf(stderr, "Parent returned from wait.\n");
        }

    } else {
        /* Child process */
        execvp(args[0], args); // Only returns upon error.
        fprintf(stderr, "\nexec() error.\n");
        exit(1);
    }

    return pid;
}