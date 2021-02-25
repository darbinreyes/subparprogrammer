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