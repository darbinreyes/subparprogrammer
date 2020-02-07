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
  ); // Correct. No problem.
**/

/**
int
poo (
  double a,
  double b
  ); // No compiler error or warning! Prints garbage!
**/
/**

 With no declaration of poo() at all, the compiler warns that poo() is
 implicitly. If you run it, it prints garbage too. Even though the source files
 we compiled together with:
 cc knr_pg63.c knr_pg63_func.c

 This error is easy to avoid since they compiler warns you.

**/

/**
 Can you ensure the compiler complains about poo() being declared differently
 from its definition by using a header file?
 ANS:
 Yes! So use this as a way to avoid hidden function declaration mismatch errors.

 The reason this sort of hidden error is possible is to allow old C programs
 to compile. Early C was not very strict with types.

**/

#include "knr_pg63_func.h"

int
main (
  void
  ) {
  double result;

  result = poo (5.0, 3.0);

  printf("%f\n", result);

  return 0;
}