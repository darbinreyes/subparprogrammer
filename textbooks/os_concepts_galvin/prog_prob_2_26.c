/*

A program that copies the contents of one file to a destination file.

Using the POSIX API.

Include all necessary error checking, including that the source file exists.

Use the dtrace command to trace system calls.

*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h> // read, write
#include <fcntl.h> // open, O_RDONLY

#include <sys/errno.h> //  [ENOENT] O_CREAT is not set and the named file does not exist.

// ssize_t read(int fildes, void *buf, size_t nbyte);

// ssize_t write(int fildes, const void *buf, size_t nbyte);

// int open(const char *path, int oflag, ...);

int main(void) {

  /*

    KNR pg. 138.

    "three files are open, with file descriptors 0, 1, and 2, called the standard
    input, the standard output, and the standard error

  */

#define INPUT_BUFFER_SIZE 256

  char str[] = "Hello, Dijkstra.\n";
  size_t str_nbytes = sizeof(str);
  ssize_t w_nbytes;
  char str_in[INPUT_BUFFER_SIZE];
  ssize_t r_nbytes;

  int src_file_fd;
  char src_file_path[INPUT_BUFFER_SIZE];

  int dest_file_fd;
  char dest_file_path[INPUT_BUFFER_SIZE];

#define STD_IN_FD  0
#define STD_OUT_FD 1
#define STD_ERR_FD 2

  w_nbytes = write(STD_OUT_FD, str, str_nbytes); // TODO error checking.

//  r_nbytes = read(STD_IN_FD, str_in, INPUT_BUFFER_SIZE);

  // Assume r_nbytes is < INPUT_BUFFER_SIZE and r_nbytes >= 0
  //str_in[r_nbytes] = '\0';

//  w_nbytes = write(STD_OUT_FD, str_in, r_nbytes);

  /*
    Acquire input file name.
      Write prompt to screen.
      Accept input.
  */
  #define SRC_FILE_PROMPT "Enter the source path: "
  w_nbytes = write(STD_OUT_FD, SRC_FILE_PROMPT, sizeof(SRC_FILE_PROMPT));

  r_nbytes = read(STD_IN_FD, src_file_path, INPUT_BUFFER_SIZE);

  src_file_fd = open(src_file_path, O_RDONLY);

  if (src_file_fd == -1) {
    // Error
    #define OPEN_ERR_MSG "open() error. bye."
    w_nbytes = write(STD_OUT_FD, OPEN_ERR_MSG, sizeof(OPEN_ERR_MSG));
    return -1;
  }

  /*

    Acquire output file name.
      Write prompt to screen
      Accept input
  */
  #define DEST_FILE_PROMPT "Enter the destination path: "
  w_nbytes = write(STD_OUT_FD, DEST_FILE_PROMPT, sizeof(DEST_FILE_PROMPT));

  r_nbytes = read(STD_IN_FD, dest_file_path, INPUT_BUFFER_SIZE);

  /*

  Open destination file for write only, create it if it doesn't exist, throw error if the file already exists.

  */
  dest_file_fd = open(src_file_path, O_WRONLY|O_CREAT|O_EXCL);

  if (dest_file_fd == -1) {
    // Error
    w_nbytes = write(STD_OUT_FD, OPEN_ERR_MSG, sizeof(OPEN_ERR_MSG));
    return -1;
  }

  return 0;
}