/** @file
  C programs corresponding to propositions from Euclid's Elements.

  Coding style: following EDK2 coding standards since I am already familiar with it.

**/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "euclid.h"


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

  @retval -1  a or b was NULL.
  @retval 0   Swap successful.

**/
int
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
    return -1;
  }

  unsigned int t;

  t = *a;
  *a = *b;
  *b = t;

  return 0;
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

  See Euclid.VII.1.md.

  Determines if the given numbers are prime to one another,
  a.k.a. the numbers have no common measure greater than 1.

  @param  a The first number.
  @param  b The second number.

  @retval -1 If !(a > 1 && b > 1).This is considered invalid input.
  @retval -2 If (a == b).This is considered invalid input.
  @retval -3 Unexpected error.
  @retval RELATIVELY_PRIME  If the numbers are prime to one another.
  @retval NOT_RELATIVELY_PRIME  If the numbers have a common measure greater than 1.

**/
int
VII_1_relatively_prime (
  unsigned int a,
  unsigned int b
  )
{
  if (!( a > 1 && b > 1)) {
    // VII.Def.2. By definition, a number means a "whole positive numbers greater than 1"
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
    if (b > a) {
      if (swap(&a, &b) != 0) {
        return -3;
      }
    }

    a = a - b;
  }

  if (a == 1) {
    return RELATIVELY_PRIME;
  } else if (a == 0){
    return NOT_RELATIVELY_PRIME;
  } else {
    // Something is wrong. The loop should have terminated with a == 0 or a == 1.
    assert(0);
    return -3;
  }
}

/**
  "To find the greatest common measure of two given numbers not relatively
  prime."

  Corollary:
  From this it is clear that, if a number measures two numbers, then it also
  measures their greatest common measure.

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII2.html

  See Euclid.VII.2.md.

  Given two numbers not prime to one another, determines their greatest
  common measure (gcm, a.k.a greatest common divisor).

  @param  a The first number.
  @param  b The second number.

  @retval -1 if !(a > 1 && b > 1). This is considered invalid input.
  @retval -2 If (a == b).This is considered invalid input.
  @retval -3 Unexpected error.
  @retval -4 If a or b is greater than INT_MAX.
  @retval RELATIVELY_PRIME if a and b are prime to one another.
  @retval > 1 The greatest common measure of a and b.

**/
int
VII_2_gcm (
  unsigned int a,
  unsigned int b
  )
{
  int rp;

  rp = VII_1_relatively_prime (a, b); // The proposition begins with the assertion that a, b are NOT relatively prime.

  if (rp < 0) {
    return -3;
  }

  if (rp == RELATIVELY_PRIME) {
    return RELATIVELY_PRIME;
  }

  if (rp != NOT_RELATIVELY_PRIME) {
    assert(0);
    return -3;
  }

  // Prevent a possible overflow of the return value.
  // Limit the inputs to max INT_MAX.
  if (!(a <= ((unsigned int)INT_MAX) && b <= ((unsigned int)INT_MAX))) {
    assert(0);
    return -4;
  }

  // Antenaresis.
  while (a > 1 && b > 1) {
    if (b > a) {
      if (swap(&a, &b) != 0) {
        return -3;
      }
    }

    a = a - b;
  }

  if (a == 0) {
    return b;
  } else {
    // Should never execute since we have already checked that a and b are NOT
    // prime to one another.
    assert(0);
    return -3;
  }
}

#define MEASURES 0
#define NOT_MEASURES 1

/**
  Determines if the lesser number measures the greater number.
  Based on VII.2, a number measures itself,
  i.e. if the given numbers are equal, this function considers that b measures a.

  @param  b The lesser number.
  @param  a The greater number.

  @retval -1 if !(a > 1 && b > 1). This is considered invalid input.
  @retval -2  If !(b <= a). This is considered invalid input.
  @retval MEASURES  If b|a. Including b == a.
  @retval NOT_MEASURES  If !(b|a).
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

  /*
    At the moment I don't think it is worthwhile to place the assert before
    the subsequent "if" because I would then need to maintain the negated and
    unnegated expression.
  */
  // assert((b <= a));
  if(!(b <= a)) {
    assert(0);
    return -2;
  }

  while (a >= b) {
    a = a - b;
  }

  if (a == 0) {
    return MEASURES; // b|a
  }

  return NOT_MEASURES; // !(b|a)
}

/**
  "To find the greatest common measure of three given numbers not relatively prime."

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII3.html

  See Euclid.VII.3.md.

  Given three numbers not prime to one another, returns their greatest common
  measure.

  @param  a The first number.
  @param  b The second number.
  @param  c The third number.

  @retval -1 if !(a > 1 && b > 1 && c > 1). This is considered invalid input.
  @retval -2 If (a == b || a == c || b  == c).This is considered invalid input.
  @retval -3 If a, b, or c are greater than INT_MAX.
  @retval -4 Unexpected error.
  @retval 1 if any pair of a,b,c are prime to one another.
  @retval > 1 The greatest common measure of a, b, c.

**/
int
VII_3_gcm (
  unsigned int a,
  unsigned int b,
  unsigned int c
  )
{

  if (!( a > 1 && b > 1 && c > 1)) { // Valid arguments means integers > 1.
    assert(0);
    return -1;
  }

  // Prevent a possible overflow of the return value.
  // Limit the inputs to max INT_MAX.
  if (!(a <= ((unsigned int)INT_MAX) && b <= ((unsigned int)INT_MAX)) && c <= ((unsigned int)INT_MAX)) {
    assert(0);
    return -3;
  }

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

  if (d < 0 || e < 0 || f < 0) {
    assert(0);
    return -4;
  }

  if (d == RELATIVELY_PRIME || e == RELATIVELY_PRIME || f == RELATIVELY_PRIME) {
    // One or more of the pairs is prime to one another.
    return RELATIVELY_PRIME;
  }

  int t;

  if (d <= c) {
    t = measures_v0 (d, c);

    if (t < 0) {
      assert(0);
      return -4;
    }

    if (t == MEASURES) { // This reflects the structure of Euclid's proof.
      return d;
    }
  }

  e = VII_2_gcm (d, c);

  if (e < 0 || e == RELATIVELY_PRIME) {
    assert(0);
    return -4;
  }

  if (!(e > 1)) {
    assert(0);
    return -4;
  }

  return e;
}

/**
  "Any number is either a part or parts of any number, the less of the greater."

  https://mathcs.clarku.edu/~djoyce/java/elements/bookVII/propVII4.html

  See Euclid.VII.4.md.

  Determines if the lesser number is part or parts of the greater number.

  @param  b The lesser number.
  @param  a The greater number.

  @retval -1 if !(a > 1 && b >= 1). This is considered invalid input.
  @retval -2  If !(b < a). This is considered invalid input.
  @retval -3  Unexpected error.
  @retval 0  If b is part of a.
  @retval 1  If b is parts of a.

**/
int
VII_4_part_or_parts (
  unsigned int b,
  unsigned int a
  )
{

  if (!(a > 1 && b >= 1)) {
    assert(0);
    return -1;
  }

  if(!(b < a)) {
    assert(0);
    return -2;
  }

  if(b == 1) { // an unit measures any number, therefore an unit is a part of any number
    return 0;
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

  See measures_v0 (). This is an alternate implementation of measures_v0 ().
  Determines how many times b measures a.

  @param  b The lesser number.
  @param  a The greater number.

  @retval -1 if !(a > 1 && b >= 1). This is considered invalid input.
  @retval -2  If !(b <= a). This is considered invalid input.
  @retval 0    If !(b|a).
  @retval > 0  If b|a. The return value = the number of times that b measures a, i.e. a/b.

**/
int
measures_v1 (
  unsigned int b,
  unsigned int a
  )
{
  if (!(a > 1 && b >= 1)) {
    assert(0);
    return -1;
  }

  if(!(b <= a)) {
    assert(0);
    return -2;
  }

  int d;

  d = 0;

  while (a >= b) {
    a = a - b;
    d = d + 1;
  }

  if (a == 0) { // See EWD implementation in Euclid.VII.4.md.
    ;
  } else {
    d = 0;
  }

  return d;
}

/**
  See VII_4_part_or_parts (). This is an alternate implementation of VII_4_part_or_parts ().

  Determines if the lesser number is part or parts of the greater number.
  Also computes how many if what part, in least numbers, i.e., the least numbers
  m and n such that a = (m/n)∙b.

  @param  b The lesser number.
  @param  a The greater number.

  @retval -1 if !(a > 1 && b >= 1). This is considered invalid input.
  @retval -2  If !(b < a). This is considered invalid input.
  @retval -3 (m == NULL || n == NULL).
  @retval -4  Unexpected error.
  @retval 0  If b is part of a.
  @retval 1  If b is parts of a.

**/
int
VII_4_part_or_parts_v1 (
  unsigned int b,
  unsigned int a,
  int         *m,
  int         *n
  )
{

  if (!(a > 1 && b >= 1)) {
    assert(0);
    return -1;
  }

  if (!(b < a)) {
    assert(0);
    return -2;
  }

  if (m == NULL || n == NULL) {
    assert(0);
    return -3;
  }

  if(b == 1) { // an unit measures any number, therefore an unit is a part of any number
    *m = 1;
    *n = a;
    return 0;
  }

  int rp;

  rp = VII_1_relatively_prime (b, a);

  if (rp < 0) {
    assert(0);
    return -4;
  }

  *n = measures_v1 (b, a);

  if (*n < 0) {
    assert(0);
    return -4;
  }

  int p;

  if (rp) {
    p = 1;
    *m = (int) b;
    *n = (int) a;
  } else if (!rp && *n > 0) {
    p = 0;
    *m = 1;
  } else if (!rp && !(*n > 0)) {
    p = 1;
    int d;
    d = VII_2_gcm (b, a);
    if (d < 0) {
      assert(0);
      return -4;
    }
    *m = measures_v1 (d, b);
    if (*m < 0) {
      assert(0);
      return -4;
    }
    *n = measures_v1 (d, a);
    if (*n < 0) {
      assert(0);
      return -4;
    }
  } else {
    assert(0);
    return -4;
  }

  return p;
}

/**

  Given two pairs, returns wether or not the sum of the pairs is the same part
  as each given pair.

  @param p0 The first pair.
  @param p1 The second pair.

  @retval < 0 Error.
  @retval 1 The sum of the pairs is the same part as the given pairs.
  @retval 0 The given pairs were not the same part. Or the sum of the pairs was
            not the same part as the given pairs (which should be impossible).
**/
int
VII_5_sum_same_part (
  PAIR p0,
  PAIR p1
  )
{
  if (!(p0.a >= 1 && p0.b > 1 && p1.a >= 1 && p1.b > 1)) {
    return -1;
  }
  // excluding the INT_MAX check.

  int n0, n1, n2;
  PAIR sum;

  n0 = measures_v1(p0.a, p0.b);
  n1 = measures_v1(p1.a, p1.b);

  if (n0 > 0 && n1 > 0 && n0 == n1) {
    sum.a = p0.a + p1.a;
    sum.b = p0.b + p1.b;
    n2 = measures_v1(sum.a, sum.b);

    if(n0 == n2) {
      return 1;
    } else {
      assert(0); // impossible
    }
  }

  return 0;
}

/**

  Given two pairs, each representing parts (a.k.a. non-unit fractions), returns
  whether or not the sum of the pairs is the same parts as each given pair.

  @param[in]  p0   The first pair.
  @param[in]  p1   The second pair.
  @param[out] pout If 1 is returned, the sum of the given pairs upon return.

  @retval < 0 Error.
  @retval 1   The sum of the pairs is the same parts as the given pairs.
  @retval 0   The given pairs were not the same part. Or the sum of the pairs was not the same part as the given pairs (which should be impossible).

**/
int
VII_6_sum_same_parts (
  PAIR p0,
  PAIR p1,
  PAIR *pout
  )
{
  return -1;
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