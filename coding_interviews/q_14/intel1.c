/*
A. Write C code
Check for UINT32 Counter variable in range of [256, 1024)
*/

if (counter >= 256 || counter < 1024)


/*
B. How to find number of elements in Array below
Function1 (INT* Array) {}
*/

Function1 (INT* Array, unsigned long length) {}


/*
C. Please read below declaration. What does it achieve?
typedef STATUS (*EFI_DISK_CANCEL_EX) (struct EFI_DISK_IO *This);
*/

typedef STATUS (*EFI_DISK_CANCEL_EX) (struct EFI_DISK_IO *This);

// typedef for at pointer to a function with return type STATUS, and 1 argument of type struct EFI_DISK_IO*

/////////////////////////////////////////////////////////////////////////////////



D. What is right below? What is wrong? if wrong, how to correct it?

typedef int apple; // OK // typedef normally used to provide alias for an existing type.

unsigned apple x; // OK


E. Is this code snippet valid? If not, how to correct it? What would be the Output?
A = 10; // Can I assume typeof(A) is int? Yes. // Missing type
B = 20;
printf ("Output %d %d \n", A, B); // "Output 10 20"
printf ("Output %d %d \n", A); // Incorrect because, compiler will probably complain, warn missing argument for second format specifier %d.

F. Define compiler result. if success then define run output.
int P = 10;
unsigned int Q = 20;

 i. do {
printf ("P becomes %d \n", P); // 10
} while (P-- > Q); // 10 > 20 // False

// Only thing printed is 10

ii. do {
printf ("P becomes %d \n", P); // "P becomes 10"
if (P >= Q) break; // 10 >= 20 // False
} while (1); // while forever

// break never occurs

// Prints "P becomes 10" forever

 iii. what would happen if condition was changed to if (-1) break; in example above

// Prints "P becomes 10" once
// if(-1) // In C any non-zero value is TRUE. So break occurs.


/*// SKIP G
G. Find output of below
int Test = 10;
for (Test = 10; Test > 10; Test++)
printf ("Test was %d \n",Test);
*/

int Test = 10;
for (Test = 10; Test > 10; Test++)
printf ("Test was %d \n",Test); // Does not print anything because Test > 10 is false. 10 > 10 == FALSE.

// H. Construct highest number possible with number 9, 9 and 9. What would be 2nd and 3rd highest number?

// Construct ?

// NOT SURE :(







