/*!
    @header Programming problem 9.40. Consumer process.
*/

#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>

#define SHM_SIZE 4096

const char * const shm_name = "collatz";

int main(void) {
  int shm_fd;
  void *shm_ptr;

  /* "The consumer will then read and output the sequence of numbers from shared
     memory." */
  errno = 0;
  shm_fd = shm_open(shm_name, O_RDONLY);

  if(shm_fd == -1) { // Error.
    perror("FYI0");
    return 1;
  }


  errno = 0;
  shm_ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

  if (shm_ptr == MAP_FAILED) { // Error.
    perror("FYI1");
    return 1;
  }

  printf("%s\n", (char *) shm_ptr);

  /* Remove the shared mem. object. */
  if (shm_unlink(shm_name) == -1) { // Error.
    perror("shm_unlink error");
    //return 3;
  }


}