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

#endif