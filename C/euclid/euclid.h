#ifndef __EUCLID_H__
#define __EUCLID_H__

#define RELATIVELY_PRIME 1
#define NOT_RELATIVELY_PRIME 0

int
VII_1_relatively_prime (
  unsigned int a,
  unsigned int b
  );

int
VII_2_gcm (
  unsigned int a,
  unsigned int b
  );

int
VII_3_gcm (
  unsigned int a,
  unsigned int b,
  unsigned int c
  );

int
VII_4_part_or_parts (
  unsigned int b,
  unsigned int a
  );

int
VII_4_part_or_parts_v1 (
  unsigned int b,
  unsigned int a,
  int         *m,
  int         *n
  );

typedef struct _PAIR {
  unsigned int a;
  unsigned int b;
} PAIR;

/**

  Given two pairs, returns wether or not the sum of the pairs is the same part
  as each given pair.

  @param p0 The first pair.
  @param p1 The second pair.

  @retval < 0 Error.
  @retval 1 The sum of the pairs is the same part as the given pairs.
  @retval 0 The given pairs were not the same part, or the sum of the pairs was
            not the same part as the given pairs (which should be impossible).
**/
int
VII_5_sum_same_part (
  PAIR p0,
  PAIR p1
  );
#endif