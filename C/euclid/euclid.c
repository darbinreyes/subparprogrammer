/** @file
  C programs corresponding to propositions from Euclid's Elements.

  Coding style: following EDK2 coding standards since I am already familiar with it.

  Testing: Hopefully I can get "seatest" working for testing functions in this file.
**/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/**
  Swaps the values of the given integers.

  The arguments are invalid if either one is NULL, in this case nothing is done
  and the function returns immediately. Otherwise the swap is performed.

  asserts if either argument is NULL.

  @param  a Pointer to the first integer.
  @param  b Pointer to the second integer.


**/
void
swap (
  unsigned int *a,
  unsigned int *b
  )
{
  if (a == NULL || b == NULL) {
    /**
      As a general rule, I will use asserts but it's important to handle such
      errors gracefully in case asserts are disabled. i.e. the code should do
      something reasonable if the assert is removed.
    **/
    assert(0);
    return;
  }

  unsigned int t;

  t = *a;
  *a = *b;
  *b = t;

  return;
}

int
main (void)
{
  printf("Hello, Euclid.\n");

  return 0;
}