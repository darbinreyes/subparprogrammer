#include <stdlib.h>

char *str = "Hello Edsgar Dijkstra.";

int main(int argc, char **argv) {
  int *heap_data;
  int a = 5, b = 7, s = 0;

  s = a + b;

  heap_data = malloc(sizeof(int) * 4); // Space for 4 integers.

  heap_data[0] = 2; // Fill with primes.
  heap_data[1] = 3;
  heap_data[2] = 5;
  heap_data[3] = 7;

  return 0;
}