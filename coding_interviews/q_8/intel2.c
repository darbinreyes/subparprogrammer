1.      Given this code, what should be the output of the
code when executed, or what are the errors encountered if any.

#include <stdio.h>

#include <stdio.h>

int* foo(int n)

{

int a, i;

for(i=0;i<n; i++) // problem : a = not init.

{

      a=a+i;

}

      return &a; // problem: returning the address of local variable, which doesn't after the function returns.

}

int main()

{

      int *result = foo(3); // foo() returns random

      int *arr = malloc(sizeof(int)*(*result)); // alloc int array



      for(int i =0; i<(*result);i++)

      {

            arr[i]=i; // suspicious.

            printf("%d\t",arr[i]); //

      }

      return 0;

}

// procress to understand and test and debug.
/*
1.
Code Question: Given an integer, swap consecutive b bits starting from given
position in binary. The bit to be swapped should not overlap with each other.

Example: n =15 (15 > binary : 00001111)

foooo() {
p =2, q =5 (3rd and 6th bit from right)

b = 2(No. of consecutive bits in each sequence)

output: = 99 (binary--> 01100011)

*/