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

/** Function header format.

  If a function corresponds to a proposition the format is:

  The proposition.

  Link to proposition.

  See *.md.

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

  See Euclid.VII.1.md

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

  Proof summary: (See evernote for details)
  Anternaresis to derive a common measure. Reduction ad absurdum to show it is
  the greatest common measure.




  TODO: What about the corollary? a|b ∧ a|c => a|gcd(b,c). // "the notation a | b is typically used to indicate that a divides b.""

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
  int rp;

  rp = VII_1_relatively_prime (a, b); // The proposition begins with the assertion that a, b are not relatively prime.

  if (rp != 0)
    return rp;

  assert (rp == 0); // a, b are not relatively prime.

  // Antenaresis.
  while (a > 1 && b > 1) {
    if (b > a)
      swap(&a, &b);

    a = a - b;
  }

  assert(a == 0); // The lesser has measured the greater, b == gcm(a, b).

  if (a == 0)
    return b;
  else {
    // Should never execute. There is an error in VII_1_relatively_prime ().
    // a and b are prime to one another.
    assert(0);
    return 1;
  }
}

/**
  "To find the greatest common measure of three given numbers not relatively prime."

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII3.html

  Proof summary: (See evernote for details)
  A, B, C are not relatively prime. Take D=gcd.(A,B).
  Case D|C.
  Derive D|A,B,C. Reductio add absurdum leads to conclusion D=gcd.(A,B,C).
  Case ¬(D|C).
  Derive that D, C are not relatively prime. Take E=gcd.(D,C).
  Derive that E|A,B,C. Reduction ad absurdum leads to conclusion E=gcd.(A,B,C).



  Given three numbers not prime to one another, returns their greatest common
  measure.

  @param  a The first number.
  @param  b The second number.
  @param  c The third number.

  @retval -1 if !(a > 1 && b > 1 && c > 1). This is considered invalid input.
  @retval -2 If (a == b || a == c || b  == c).This is considered invalid input.
  @retval 1 if any pair of a,b,c are prime to one another.
  @retval returns the greatest common measure of a, b, c which is always > 1.

**/
int // Be careful, since arguments are unsigned it may be possible that the return value overflows a signed int. I am using negative numbers to indicate errors.
VII_3_gcm (
  unsigned int a,
  unsigned int b,
  unsigned int c
  ) {

  if (!( a > 1 && b > 1 && c > 1)) { // Valid arguments means integers > 1.
    assert(0);
    return -1;
  }

  assert(a > 1 && b > 1 && c > 1);

  /**
    Verify that the numbers are distinct and that the three numbers are not
    relatively prime. The possible pairings are:
    a,b
    a,c
    b,a // Since gcd.(a,b) == gcd.(b,a) this is a duplicate of the first pair.
    b,c
    c,a // dup.
    c,b // dup.
  **/

  if (a == b || a == c || b  == c) {
    assert(0);
    return -2;
  }

  int d, e, f;

  d = VII_2_gcm (a, b);
  e = VII_2_gcm (a, c);
  f = VII_2_gcm (b, c);

  if (d == 1 || e == 1 || f == 1) {
    // One or more of the pairs is prime to one another.
    return 1;
  }

  // Now we know a common measure exists. Compute it.

  e = VII_2_gcm (d, c);

  if (!(e > 1)) {
    // Error. d and c should have a common measure. Euclid proved that.
    assert(0);
    return 1;
  }

  return e;
}

/**
  Determines if the lesser number measures the greater number.
  Based on VII.2, a number measures itself,
  i.e. if the given numbers are equal, this function considers that the one
  number measures the other.

  @param  b The lesser number.
  @param  a The greater number.

  @retval -1 if !(a > 1 && b > 1). This is considered invalid input.
  @retval -2  If !(b <= a). This is considered invalid input.
  @retval 0  If b|a. Including b == a.
  @retval 1  If !(b|a).
**/
int
measures_v0 (
  unsigned int b,
  unsigned int a
  )
{
  if (!(a > 1 && b > 1)) {
    assert(0);
    return -1;
  }

  if(!(b <= a)) {
    assert(0);
    return -2;
  }

  while (a >= b) {
    a = a - b;
  }

  if (a == 0) {
    return 0; // b|a
  }

  return 1; // !(b|a)
}

/**
  "Any number is either a part or parts of any number, the less of the greater."

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII4.html

  See Euclid.VII.4.md.

  Determines if the lesser number is part or parts of the greater number.

  @param  b The lesser number.
  @param  a The greater number.

  @retval -1 if !(a > 1 && b > 1). This is considered invalid input.
  @retval -2  If !(b < a). This is considered invalid input.
  @retval -3  Unexpected error.
  @retval 0  If b is part of a.
  @retval 1  If b is parts of a.

**/
int
VII_4_part_or_parts (
  unsigned int b,
  unsigned int a
  ) {

  if (!(a > 1 && b > 1)) {
    assert(0);
    return -1;
  }

  if(!(b < a)) {
    assert(0);
    return -2;
  }

  int rp;

  rp = VII_1_relatively_prime (b, a);

  if (rp < 0) {
    assert(0);
    return -3;
  }

  if (rp == 1) {
    return 1; // a is parts of b.
  }

  int mrs;

  if (rp == 0) {
    mrs = measures_v0 (b, a);

    if (mrs < 0) {
      return -3;
    }

    if (mrs == 0) {
      return 0; // a is part of b.
    }

    if (mrs == 1) {
      return 1; // a is parts of b.
    }

    assert(0); // mrs should have been == 0 or == 1.

    return -3;
  }

  assert(0); // rp should have been == 0 or == 1.

  return -3;
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