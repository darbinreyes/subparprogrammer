/*

  Programming problem 3.22.

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

    if (WEXITSTATUS(stat_loc) > 0 && WEXITSTATUS(stat_loc) < 8) {
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
    if (WEXITSTATUS(stat_loc) == 8) {
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

int child_p(int argc, char **argv) {
  unsigned long int n;
  int shm_fd;
  void *shm_ptr;

  printf("This is the child process.\n");
  /*

    Get the command line argument. It should be a single positive integer >=
    1.

  */
  if (argc != 2 || argv[1][0] == '-') {
    printf("Usage: Supply one integer argument greater than 0, e.g. \"a.out 8\". The argument is converted to unsigned long using strtoul().\n");
    return 1;
  }

  errno = 0; // strtoul() sets errno.

  n = strtoul(argv[1], NULL, 10);
  if (n == ULONG_MAX && errno == ERANGE) {
    printf("Failed to convert argument \'%s\' to unsigned long. Overflow.\n", argv[1]);
    perror("Fuck");
    return 2;
  }

  if(n == 0 && errno == EINVAL) {
    printf("Failed to convert argument \'%s\' to unsigned long. No conversion.\n", argv[1]);
    perror("Fuck");
    return 3;
  }

  if(n == 0) {
    printf("Argument must be greater than 0.\n");
    return 4;
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
    return 8;
  }

  return 0;
}

// Since the point of this is to learn about OS concepts and not C programming:
// FYI: I will not check for overflow.
// FYI: The command line parameter validation will be very basic.
// FYI: I will assume the Collatz conjecture is in fact true. If it is false, then there will exist values of n for which this program will never terminate.
int print_collatz(unsigned long int n, char *shm_ptr, int bw) {
  char tmp_str[128];
  assert(n > 0);

  // TODO: Check that we aren't writing more than the size of the shared mem.
  // object.
  if (n == 1) {
    // Done.
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