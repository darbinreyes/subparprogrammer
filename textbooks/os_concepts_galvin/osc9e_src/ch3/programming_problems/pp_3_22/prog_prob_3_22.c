/*!
    @header Programming problem 3.22.
    @discussion See README.md.
*/

#include <unistd.h> // fork()
#include <stdio.h> // printf()
#include <assert.h>
#include <stdlib.h> // strtoul()
#include <limits.h> // ULONG_MAX
#include <errno.h> // For errors from strtoul().

/* Share memory includes */
#include <sys/mman.h> // shm_open()
#include <fcntl.h>

const char * const shm_name = "collatz";
#define SHM_SIZE 4096
#define SHM_MODE 0666

/*!
    @defined MAX_SEQUENCE_STR_SIZE
    @discussion -1 to account for the terminating '\0'.
*/
#define MAX_SEQUENCE_STR_SIZE (SHM_SIZE - 1)

/*!
    @defined ERROR_SEQUENCE_TRUNCATED
    @discussion The Collatz sequence (as a string) had to be truncated because
    the size of the string exceeded the size of the shared memory region. See
    MAX_SEQUENCE_STR_SIZE.

*/
#define ERROR_SEQUENCE_TRUNCATED 8

int child_p(int argc, char **argv);

int main(int argc, char **argv) {
  pid_t pid, cpid;
  int stat_loc;

  int shm_fd; // Shared memory related.
  void *shm_ptr;

  printf("Parent process is about to fork().\n");

  pid = fork();

  if (pid < 0) {
    printf("fork() failed.\n");
  } else if (pid == 0) { // Child
    return child_p(argc, argv);
  } else { // Parent
    printf("Parent process is about to wait().\n");
    cpid = wait(&stat_loc);
    printf("Parent process returned from wait().\n");
    assert(pid == cpid); // Check that wait() returns the child's PID.

    if (!WIFEXITED(stat_loc)) {
      printf("Child process terminated abnormally.\n");
      // Assume the collatz sequence was not written to the shared mem. object.
      return 5;
    }

    if (WEXITSTATUS(stat_loc) > 0 && WEXITSTATUS(stat_loc) < ERROR_SEQUENCE_TRUNCATED) {
      printf("Child process terminated with ERROR status value = %d.\n", WEXITSTATUS(stat_loc));
      return 4;
    }

    /*

      Shared mem. consumer. Output the collatz sequence from shared mem. object
      deallocate it, and return.

    */

    /* create shared mem. object */
    shm_fd = shm_open(shm_name, O_RDONLY, SHM_MODE);

    if(shm_fd == -1) { // Error.
      return 1;
    }
    /* Mem. map the shared mem. object. */
    /* void *mmap(void *addr, size_t len, int prot, int flags, int fd,
       off_t offset); */
    shm_ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    if (shm_ptr == MAP_FAILED) { // Error.
     return 2;
    }

    /* Read from the shared mem. object. */
    if (WEXITSTATUS(stat_loc) == ERROR_SEQUENCE_TRUNCATED) {
      printf("Sequence was truncated.\n");
      printf("%s\n", (char *) shm_ptr);
    } else {
      printf("%s", (char *) shm_ptr);
    }

    /* Remove the shared mem. object. */
    if (shm_unlink(shm_name) == -1) { // Error.
      return 3;
    }
  }
  printf("Parent process: successful.\n");
  return 0; // Success.
}

int print_collatz(unsigned long int n, char *shm_ptr, int bw);

/*!
    @defined USAGE_STR
    @discussion The string to print when invalid input is given.
*/
#define USAGE_STR "Usage: Supply one integer argument greater than 0,"\
                  " e.g. \"a.out 8\".\n"

/*!
    @function child_p
    @discussion Function that does the work specified for child process:
    generates the Collatz sequence. The sequence is written to the shared memory
    object.
    @param argc The usual arg to main()
    @param argv The usual arg to main()
    @result 0 if successful.
*/
int child_p(int argc, char **argv) {
  long n;
  char *endptr;
  int shm_fd;
  void *shm_ptr;

  printf("This is the child process.\n");
  /* Get the command line argument. It should be a single positive integer >= 1.
     */

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

  n = strtol(argv[1], &endptr, 10);

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

  if(n <= 0) {
    printf("Argument must be greater than 0.\n");
    printf("%s", USAGE_STR);
    return 1;
  }

  /*

    This is the producer process.
    Open a shared memory region for read/write. Write the collatz sequence to
    this region. Return.

  */

  /* create shared mem. object */
  shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, SHM_MODE);

  if(shm_fd == -1) { // Error.
    return 5;
  }

  /* Set size of shared mem. object. */
  if (ftruncate(shm_fd, SHM_SIZE) == -1) { // Error.
    return 6;
  }

  /* Mem. map the shared mem. object. */
  /* void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset); */
  shm_ptr = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  if (shm_ptr == MAP_FAILED) {
    return 7;
  }

  /* Write to the share mem. object. */
  if(print_collatz(n, shm_ptr, 0) != 0) {
    //return 8;
    return ERROR_SEQUENCE_TRUNCATED;
  }

  return 0;
}

// Since the point of this is to learn about OS concepts and not C programming:
// FYI: I will not check for overflow.
// FYI: The command line parameter validation will be very basic.
// FYI: I will assume the Collatz conjecture is in fact true. If it is false, then there will exist values of n for which this program will never terminate.
/*!

    @discussion This is a recursive implementation for printing the sequence
    corresponding to the Collatz conjecture.

    @param n  The starting value for computing the next number in the Collatz
              sequence.
    @param shm_ptr  Pointer to the shared memory region.
    @param bw Number of bytes written to the shared memory region so far.

*/
int print_collatz(unsigned long int n, char *shm_ptr, int bw) {
  /*!
    @discussion A unsigned long int converted to a decimal string will always
    take (much) fewer characters than 128. The value 128 is an arbitrary upper
    bound. */
  char tmp_str[128];
  assert(n > 0);

  // TODO: Check that we aren't writing more than the size of the shared mem.
  // object.
  if (n == 1) { // n == 1 is the base case.
    // Done.
    /*! @discussion `man sprintf` These functions return the number of characters printed (not including
     the trailing `\0' used to end output to strings) */
    bw += sprintf(tmp_str, "1.\n");
    if (bw < SHM_SIZE) {
      shm_ptr += sprintf(shm_ptr, "1.\n");
      return 0;
    } else {
      return 1; // Sequence truncated.
    }

  } else {
    bw += sprintf(tmp_str, "%lu, ", n);

    if (bw < SHM_SIZE) {
      shm_ptr += sprintf(shm_ptr, "%lu, ", n);
    } else {
      return 1; // Sequence truncated.
    }
  }

  if ((n & 0x01) == 0) {
    // n is even
    n >>= 1; // n = n/2
  } else {
    // n is od
    n = 3*n + 1;
  }

  return print_collatz(n, shm_ptr, bw);

}