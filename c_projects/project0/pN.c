/*

  A simple C program whose memory space will be inspected.

*/
#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <string.h> // strlen

int sum(int a, int b) {
  int t;

  t = a + b;

  return t;
}

int main(int argc, char **argv) {
  char *str = "Hello Dijkstra."; // Should appear in the data section.
  char *str1 = "Dijkstra is my demigod.";
  char *str2 = NULL;
  int s = 0, a = 5, b = 7;

  printf("%s\n", str);

  s = sum(a, b);

  printf("%s\n", str1);

  str2 = calloc(strlen(str) + strlen(str1) + 1 + 1024, sizeof(*str2)); // Should appear on the heap.

  if(str2 == NULL) { // calloc() error.
    return 1;
  }

  strcat(str2, str);
  strcat(str2, str1);

  free(str2);

  return 0;
}