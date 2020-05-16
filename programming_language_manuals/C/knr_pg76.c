#include <stdio.h>

// A string argument for a macro is OK right? ANS: YES.
#define docatstr(s) s "caca"

int
main(void){
  printf("%s doodle doo.\n", docatstr("The rooster goes "));
  return 0;
}