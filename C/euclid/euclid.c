/** @file
  C programs corresponding to propositions from Euclid's Elements.

  Coding style: following EDK2 coding standards since I am already familiar with it.

  Testing: Hopefully I can get "seatest" working for testing functions in this file.
**/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
/**
  Notes on VII.Definitions

  Def.1-2.

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/defVII1.html

  "all three books VII through IX on number theory."
  "Books VII through IX are whole positive numbers"
  "two kinds" of numbers
  1. "numbers as objects of a theory". Def.2 = multitude of units. object language.
  2. "numbers in the metalanguage". "not multiples of the unit"
  "a, b, and c will be used for the formal numbers". "u will denote the unit".
  Remark on conflation between formal and informal numbers.
  "let n be the number of units u". "summarize definition 2 by the equation a = nu"
  "every formal number a = nu is shadowed by the unnamed informal number n"
  "definition 2 are meant to be whole positive numbers greater than 1"
  "Euclid treats the unit, 1, separately from numbers, 2, 3"
  "definition 2 are meant to be whole positive numbers greater than 1"
  "Euclid exhibits his formal numbers as lines"
  "unit line A is meant to be indivisible"
  "Euclid never calls them lines"
**/

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
      errors gracefully, in case asserts are disabled. i.e. the code should do
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

  Function header format.

  If a function corresponds to a proposition the format is:

  The proposition.

  Link to proposition.

  Proof summary.

  A description of the function.

  Parameters.

  Return values.

  The naming convention for functions corresponding to propositions will be
  "book number"_"proposition number"_"descriptive name"
  Functions which do not follow the above format are helper functions e.g. swap().
**/

/**
  "When two unequal numbers are set out, and the less is continually subtracted
  in turn from the greater, if the number which is left never measures the one
  before it until a unit is left, then the original numbers are relatively prime."

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII1.html

  Proof Summary:
  Reductio ad absurdum.
  Let the two given numbers produce a final remainder of 1 under antenaresis.
  Then they are prime to one another. For if not, then some number will measure
  them. Following the antenaresis process for 3 remainders, the last of which is
  1, leads to the conclusion that the hypothesized common measure also measures
  1, which is impossible.

  Determines if the given numbers are prime to one another,
  a.k.a. the numbers have no common measure greater than 1.
  For Euclid, the unit, 1, is not a number.
  a.k.a. the numbers have no common divisor greater than 1.
  a.k.a. the numbers are relatively prime.

  @param  a The first number.
  @param  b The second number.

  @retval -1 If !(a > 1 && b > 1).This is considered invalid input.
  @retval -2 If (a == b).This is considered invalid input.
  @retval 1  If the numbers are prime to one another.
  @retval 0  If the numbers have a common measure greater than 1.

**/
int
VII_1_relatively_prime (
  unsigned int a,
  unsigned int b
  )
{
  if (!( a > 1 && b > 1)) {
    // Def.2. By definition, a number means a "whole positive numbers greater than 1"
    assert(0);
    return -1;
  }

  if (a == b) { // The proposition specifies "two unequal numbers".
    assert(0);
    return -2;
  }

  /**
    Euclid's algorithm. This is called an "antenaresis process".

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
  "To find the greatest common measure of two given numbers not relatively
  prime."

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII2.html

  Proof summary:
  TODO.

  Given two numbers not prime to one another, determines their greatest
  common measure (gcm).
  a.k.a greatest common divisor.

  @param  a The first number.
  @param  b The second number.

  @retval -1 if !(a > 1 && b > 1). This is considered invalid input.
  @retval -2 If (a == b).This is considered invalid input.
  @retval 1 if a and b are prime to one another.
  @retval returns the greatest common measure of a and b which is always > 1.

**/
int // Be careful, since arguments are unsigned it may be possible that the return value overflows a signed int. I am using negative numbers to indicate errors.
VII_2_gcm (
  unsigned int a,
  unsigned int b
  ) {
  if (!( a > 1 && b > 1)) {
    assert(0);
    return -1;
  }

  if (a == b) {
    // Proposition VII.1 specifies "two unequal numbers" so I'll enforce that here too.
    assert(0);
    return -2;
  }

  // Antenaresis.
  while (a > 1 && b > 1) {
    if (b > a)
      swap(&a, &b);

    a = a - b;
  }

  if(a == 0) // The lesser has measured the greater, b == gcm(a, b).
    return b;
  else { // a and b are prime to one another.
    assert(a == 1);
    return 1;
  }
}

/**
  "To find the greatest common measure of three given numbers not relatively prime."

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII3.html

  Proof summary.
  TODO.

  Given three numbers not prime to one another, returns their greatest common measure.

  @param  a The first number.
  @param  b The second number.
  @param  c The third number.

  @retval -1 if !(a > 1 && b > 1 && c > 1). This is considered invalid input.
  @retval -2 If (a == b).This is considered invalid input. // FIX
  @retval 1 if any pair of a,b,c are prime to one another.
  @retval returns the greatest common measure of a, b, c which is always > 1.

**/
int // Be careful, since arguments are unsigned it may be possible that the return value overflows a signed int. I am using negative numbers to indicate errors.
VII_3_gcm (
  unsigned int a,
  unsigned int b,
  unsigned int c
  ) {

  if (!( a > 1 && b > 1 && c > 1)) {
    assert(0);
    return -1;
  }

  unsigned int d, e; // FIX.

  d = VII_2_gcm (a, b); // FIX.

  if(!(d > 1)) {
    assert(d == 1);
    return 1;
  }

  e = VII_2_gcm (d, c);

  if(!(e > 1)) {
    assert(e == 1);
    return 1;
  }

  return e;
}

/**

  The main function.

**/
/**
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
**/