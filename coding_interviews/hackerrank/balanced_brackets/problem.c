/*

  https://www.hackerrank.com/challenges/balanced-brackets/problem

  Success Rate: 84%

*/


#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the isBalanced function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//

/*
******* Scratch work

Well, I already know the standard solution to this problem.

Most important: use a stack.

Working out the algorithm.

// v0
for each char in str
  if c is opening bracket
    push(c)
  else // c is a closing bracket
    if stack.top is opening bracket matching closing bracket c
      pop()
      discard c
    else // stack.top is an opening bracket of a different kind the closing bracket c.
      the string is not balanced, return

if stack is empty after scanning the whole string, then return "YES" (it is balanced). Otherwise return "NO".

// Does v0 work with "{[(])}"? ANS: Yes.

Manual code trace:

Step 0

  {[(])} // string char pointer
  ^

  stack = {}

Step 1

  push("{")

  stack = {"{"}

  {[(])}
   ^

Step 2

  push("[")

  stack = {"{", "["}

  {[(])}
    ^

Step 3

  push("(")

  stack = {"{", "[", "("}

  {[(])}
     ^

Step 4

  stack.top is "("
  c is "]"
  closing bracket kind differs from opening bracket kind on stack.top
  mismatched, return "NO"

*/
char* isBalanced(char* s) {


}

int main()
{
  FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

  char* t_endptr;
  char* t_str = readline();
  int t = strtol(t_str, &t_endptr, 10);

  if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

  for (int t_itr = 0; t_itr < t; t_itr++) {
    char* s = readline();

    char* result = isBalanced(s);

    fprintf(fptr, "%s\n", result);
  }

  fclose(fptr);

  return 0;
}

char* readline() {
  size_t alloc_length = 1024;
  size_t data_length = 0;
  char* data = malloc(alloc_length);

  while (true) {
    char* cursor = data + data_length;
    char* line = fgets(cursor, alloc_length - data_length, stdin);

    if (!line) { break; }

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

    size_t new_length = alloc_length << 1;
    data = realloc(data, new_length);

    if (!data) { break; }

    alloc_length = new_length;
  }

  if (data[data_length - 1] == '\n') {
    data[data_length - 1] = '\0';
  }

  data = realloc(data, data_length);

  return data;
}
