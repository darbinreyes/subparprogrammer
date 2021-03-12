/*!
    @header Programming problem 9.40.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

int get_arg(int argc, char **argv, long *n);

int main(int argc, char **argv) {
  long n;

  if (get_arg(argc, argv, &n)) {
      return 1;
  }

  return 0;
}


/*!
    @defined USAGE_STR
    @discussion The string to print when invalid input is given.
*/
#define USAGE_STR "Usage: Supply one integer argument greater than 0,"\
                  " e.g. \"a.out 8\".\n"

/*!
    @function get_arg
    @discussion Gets the one and only command line argument to the program, the
    starting number for the Collatz sequence.

    @param argc The usual arg to main()
    @param argv The usual arg to main()
    @param n If successful, a validated argument from the command line.
    Untouched otherwise.

    @result 0 if successful.
*/
int get_arg(int argc, char **argv, long *n) {
  long t;
  char *endptr;

  /* Get the command line argument. It should be a single positive integer >= 1.
     */

  assert(argc > 0 && argv != NULL && n != NULL);

  if (argc != 2) {
    printf("%s", USAGE_STR);
    return 1;
  }

  if(argv[1][0] == '\0') {
    printf("Empty string.\n");
    printf("%s", USAGE_STR);
    return 1;
  }

  errno = 0; // strtol() sets errno.

  t = strtol(argv[1], &endptr, 10);

  if (endptr == argv[1]) {
    printf("No digits at all.\n");
    printf("%s", USAGE_STR);
    return 1;
  }

  if (errno != 0) {
    printf("Failed to convert argument \'%s\' to long.\n", argv[1]);
    perror("FYI");
    return 1;
  }

  if(t <= 0) {
    printf("Argument must be greater than 0.\n");
    printf("%s", USAGE_STR);
    return 1;
  }

  *n = t;

  return 0;
}