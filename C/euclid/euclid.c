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

/**

  Determines if the given numbers are prime to one another,
  a.k.a. the numbers have no common measure greater than 1.
  For Euclid, the unit, 1, is not a number.
  a.k.a. the numbers have no common divisor greater than 1.
  a.k.a. the numbers are relatively prime.

  @param  a The first number.
  @param  b The second number.

  @retval -1 If !(a > 1 && b > 1).This is considered invalid input.
  @retval 1  If the numbers are prime to one another.
  @retval 0  If the numbers have a common measure greater than 1.

**/
int
VII_1_relatively_prime (
  unsigned int a,
  unsigned int b
  )
{
  if (!( a > 1 && b > 1)){
    assert(0);
    return -1;
  }

  /**
    Euclid's algorithm. This is called an "anteneresis process".

    Continually subtract the smaller from the greater until an unit is left.
    The basis of this algorithm depends on the observation that if a number
    measures two given numbers, it also measures their difference.

  **/

  while (a > 1 && b > 1) {
    if (b > a)
      swap(&a, &b);

    a = a - b;
  }

  return a;
}

/**

  The main function.

**/
int
main (void)
{
  printf("Hello, Euclid.\n");

  unsigned int a, b;
  a = 12;
  b = 4;
  printf ("a = %u, b = %u. rp = %d. expect rp = 0.\n", a, b, VII_1_relatively_prime(a, b));

  a = 13;
  b = 4;
  printf ("a = %u, b = %u. rp = %d. expect rp = 1.\n", a, b, VII_1_relatively_prime(a, b));

  a = 54;
  b = 85;
  printf ("a = %u, b = %u. rp = %d. expect rp = 1.\n", a, b, VII_1_relatively_prime(a, b));

  return 0;
}