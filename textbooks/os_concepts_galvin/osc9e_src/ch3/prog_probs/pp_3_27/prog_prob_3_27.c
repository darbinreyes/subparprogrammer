//#include <sys/types.h>
#include <stdio.h> // fprintf(), printf()
#include <string.h> // strlen()
#include <unistd.h> // pipe(), close(), write()
#include <errno.h> // errno

#define BUFFER_SIZE 256
#define READ_END 0
#define WRITE_END 1


int main(int argc, char **argv) {
  char write_msg[BUFFER_SIZE];
  char read_msg[BUFFER_SIZE];
  int p2c_fd[2]; // Pipe fd's. Parent writes, child reads.
  pid_t pid;
  char *src_name, *dest_name;
  FILE *src, *dest;
  int n, nw;

  /* Get the file names from the program arguments. */
  /* Usage: filecopy input.txt copy.txt */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s input.txt copy.txt\n", argv[0]);
    return 1;
  }

  src_name = argv[1]; // Source file name.
  dest_name = argv[2]; // Destination file name.

  /* create the pipe */
  if (pipe(p2c_fd) == -1) {
    fprintf(stderr, "Pipe failed.\n");
    return 2;
  }

  /* fork a child process */
  pid = fork();

  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork failed.\n");
    return 3;
  }

  if (pid > 0) { /* parent process */

    /* Read from the source file. */
    src = fopen(src_name, "r");

    if (src == NULL) {
      fprintf(stderr, "fopen failed for file name %s.\n", src_name);
      return 4;
    }

    n = fread(write_msg, sizeof(char), BUFFER_SIZE, src);

    /* man fread

      If an error occurs, or the end-of-file is reached, the return value is a
      short object count (or zero).

      The function fread() does not distinguish between end-of-file and error;
      callers must use feof(3) and ferror(3) to determine which occurred.

    */

    if (n < BUFFER_SIZE) { // Either we reached EOF or an error occurred.
      if (!feof(src)) {
        // We didn't reach EOF, therefore an error occurred.
        if (ferror(src)) {
          // File related error occurred.
          fprintf(stderr, "An error occurred for file name %s.\n", src_name);
          perror(src_name);
          return 5;
        } else {
          fprintf(stderr, "Unexpected. fread returned short object count but ferror returned 0. file name %s.\n", src_name);
          return 6;
        }
      }
    } else if (n == BUFFER_SIZE) {
      fprintf(stderr, "file name %s too large. Only copying %d bytes.\n", src_name, n);
    } else {
      fprintf(stderr, "fread returned more bytes than size of buffer. This should never happen. file name %s.\n", src_name);
      return 7;
    }

    if (fclose(src)) {
      // Failed to close the file, but we already the its contents so we can still continue.
      // Inform user.
      fprintf(stderr, "fclose failed for file name %s.\n", src_name);
    }

    /* Parent write to pipe. */
    /* close the unused end of the pipe */
    close(p2c_fd[READ_END]);

    /* write to the pipe */
    nw = write(p2c_fd[WRITE_END], write_msg, n); // Note: The textbook doesn't check for errors here. I leave it that way.
    printf("Parent wrote %d bytes.\n", nw);

    /* close the write end of the pipe */
    close(p2c_fd[WRITE_END]);
  } else { /* child process */

    /* Child read from pipe */
    /* close the unused end of the pipe */
    close(p2c_fd[WRITE_END]);

    /* read from the pipe */
    n = read(p2c_fd[READ_END], read_msg, BUFFER_SIZE);

    printf("Child read %d bytes.\n", n);

    /* close the read end of the pipe */
    close(p2c_fd[READ_END]);

    /* Write to the destination file. */
    dest = fopen(dest_name, "w");
    if (dest == NULL) {
      fprintf(stderr, "fopen failed for file name %s.\n", dest_name);
      return 4;
    }

    nw = fwrite(read_msg, sizeof(char), n, dest);
    /* man fwrite

      If an error occurs, or the end-of-file is reached, the return value is a
      short object count (or zero).

      The function fwrite() returns a value less than nitems only
      if a write error has occurred.

    */
    if (nw < n) {
      fprintf(stderr, "fwrite error for file name %s.\n", dest_name);
      if (ferror(dest)) {
        // File related error occurred.
        fprintf(stderr, "An error occurred for file name %s.\n", dest_name);
        perror(dest_name);
        //return 8;
      }
    }

    if (fclose(dest)) {
      fprintf(stderr, "fclose failed for file name %s.\n", dest_name);
      return 8;
    }
  }

  return 0;
}