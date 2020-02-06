/**
 Will the compiler detect a mismatching declaration across source files?
 ANS: No!

 man man // see sections list here.
 man printf // man page for the bsd command.
 man 3 printf // man page for the C library function
**/

#include <stdio.h>

/**
 No declaration of poo() generates a warning
**/
/**
double
poo (
  double a,
  double b
  ); // No problem.
**/

/**
int
poo (
  double a,
  double b
  ); // No compiler error or warning! Prints garbage!
**/

int
main (
  void
  ) {
  double result;

  result = poo (5.0, 3.0);

  printf("%f\n", result);

  return 0;
}