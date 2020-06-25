#include <stdlib.h>

char *str = "Hello Edsger Dijkstra.";
int len = 7;
short si = 3;
char c = 5;

int main(int argc, char **argv) {
  int a = 5, b = 7, s = 0;
  int *heap_data;
  int *heap_data2;

  s = a + b;

  heap_data = malloc(sizeof(int) * 4); // Space for 4 integers.
  heap_data[0] = 2; // Fill with recognizable data.
  heap_data[1] = 3;
  heap_data[2] = 5;
  heap_data[3] = 7;

  heap_data2 = malloc(sizeof(int) * 4); // Second malloc() call.
  heap_data2[0] = 0xA;
  heap_data2[1] = 0xB;
  heap_data2[2] = 0xC;
  heap_data2[3] = 0xD;

  return 0;
}