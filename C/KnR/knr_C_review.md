# /Users/darbinreyes/Documents/Docs/Books/Computing/Programming-Languages/C/The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie.pdf

## pg. 19

assignment “=“ has lower precedence than relational operators like “!=", hence need for parenthesis.

## 1.8 Arguments - Call by Value

## 1.9 Character Arrays

array arguments to a function are treated as pointers inside the function.
note the style of comments and pseudo code used by K&R.

## 1.10 External Variables and Scope

local variables in functions are called automatics variables. must be explicitly initialized.
vs.
chp4. static storage class. 
vs.
external to call functions. must be define ONLY ONCE. must be declared in any function that wants to use it. Use “extern” to do this explicitly, else it is implicit based on context. any variable outside of functions are considered external. 

extern declarations in functions can be omitted when the external variable definition occurs 
1- before the function that uses the external variable
and 
2- in the same source file
otherwise
if the definition is in one file and the function that uses it is in another file, extern declarations are required to connect the two. By convention, we put such external variables and function that use the in a header file and #include them.
external variable. definition vs declaration == storage allocated vs just type stated.
Don’t overuse external variables. They complicate inter function communication and lead to less reusable code.

# Chapter 2 - Types, Operators and Expressions.

variables vs constants
declarations = name + type + opt init.
operators manipulate variables+constants
expression = produce a new value
type = possible values+possible operators.

? "first 31 characters of an internal name are significant."

machine dependent: char is signed vs unsigned. but printable chars are guaranteed to be positive.

double is the default type for floating point constants. not float or long double.

character constant != char type. a character constant has type int by default. the decimal value of a char constant in single quotes is a property to the machine called its char set.

escape sequences for char and string constants

\0 always has value  = 0.

constant expression = only constants. evaluated at compile time. #define is a constant.

string constant aka string literal aka char array.
“” empty string. // size = 1 byte . for \0
strings constants are concat’ed at compile time if adjacent. // use for long string constants across lines.

enum constants. automatics or explicit values. value continuation. values need not be distinct. e.g. months.JAN. boolean.YES. 

You can declare variables of an enum type. but compilers are required to check your assignments to such variables. debuggers sometimes let you print enums symbolically. Alternative to #define.

declaration = type + name list.

if init is provided:
non automatics variables only init’ed once. must be a constant.
explicitly init’ed automatic variables are initialized on each call. init value does need to be a constant.

external and static variables are init to 0 by default. but automatics contain garbage unless explicitly initialized.

const qualifier for variables = will not be changed. works for arrays too.

// note up to this point a string is declared as char s[]. vs char*s.

function args can also be qualified as const. an attempt to change a const is C compiler implementation dependent.

## 2.5 Arithmetic Operators.

Beware of using % operator with negative operands. Machine dependent.

Precedence is the usual with unary +/- being highest.

## 2.6 Relational and Logical Operators

Precendence
equality < relational < arithmetic
when in doubt paren it out.
assignment < logical || < logical && < equality.

## 2.7 Type Conversions

This is only a concern when an operator has operands of different types.

Automatic conversions take place when there is no information loss . e.g. narrower to wider type. integer to float.

wider to narrower conversions are not illegal. They MAY generate a warning. e.g. long to short int.

chars are treated as small integers.

The ctype.h library provides tests and conversions independent of the machine’s character set.

When a char is converted to an int (narrower to wider), can it produce a negative number? Depends on the machine, the machine might sign extend the char or pad it with 0’s. The only thing C guarantees is that character set constants are always positive. 

Use explicit signed or unsigned qualifier when char type is used for non-printable character data/ arbitrary bit patterns. 

logical expressions have a value 1=true, 0=false, but in general any non-zero value=true. The test part of if/while is equivalent to if(non-zero) … etc.

In arithmetic expressions in which all values are signed e.g. involving +/* the general rule is that narrower types is promoted to the wider type.

When we have a mix of signed and unsigned types the rules are more complicated. The reason for the complication is that conversions between signed and unsigned values are machine dependent, more specifically, the result of a comparison depends on the size of integers on a given machine. We need to know the sizes of integers on the machine to determine the ultimate result at execution time. e.g. if ints are 16 bits and long 32 bits then:
-1L < 1U == true // because the unsigned int 1U is promoted to signed long
But
-1L > 1UL == true // because -1L is promoted to unsigned long, making it a large positive integer.

When assignment is involved the result must always be of the type of the assigned variable.

For ints, wider is converted to narrower by bit truncation of the high order bits. e.g. converting from int to char.

float to integer conversion truncates the fractional part of the float. // is it possible that the integer part of a float overflows the int?

double to float conversion. treatment of the fractional part is “implementation" dependent. A machine either truncates or rounds the fractional part. // I assume implementation means the C compiler’s implementation. 

// how do you specify a double constant? By default constant values with decimal points or exponents are double.

Type conversions can be forced explicitly using what is called the cast operator. It is considered a unary operator. The syntax is:

(type name) expression.

The result is the same as if one had assigned the expression to variable of the casted type. 

Precedence of the cast operator = that of the other unary operators.

So a call like

double sqrt(double)
root2 = sqrt(2)

is equivalent to 

double n;
n = 2;
root2 = sqrt(n);

## 2.8 Increment and Decrement Operators

Increment before the value is used vs increment after the value is used.

When in doubt about the use of an pre/post-increment in an expression transform it to the equivalent be placing the increment before/after the expression in which it is used.

## 2.9 Bitwise Operators

Applied to integer types only.

bit shift operations can only be non-negative.
left shift fills vacated bits with zeros. same for right shifting an unsigned.
BUT! right shifting a signed quantity fills vacated bits either:
1. with the sign bit aka arithmetic shift.
2. with zeros. 
This is machine dependent.

x = x & ~077 
is more portable than
x = x & ~0177700
because the former is independent of “word length”. the latter assumes a 16 bit quantity.
~077 is considered a constant so it is evaluated at compile time.

Set x to all 0’s followed by n 1’s.
unsigned x;
x = ~0; // set x to all 1’s
x = x << n; // left shift n times. this fills the bits on right with n 0’s.
x = ~x; // flip the bits. now we have n 1’s on the right. followed by 0’s to the left
// in one statement
x = ~(~0 << n); // note that as usual the unary operator has higher precedence.

## 2.10 Assignment Operators and Expressions

Abbreviation for assignments. called "assignment operators" vs. "assignment statement". e.g.
i = i + 1;
i += 1; // means the same as above.
works for all binary ops like +.
In general, the right side can be an complicated expression.
expr_1 += expr_2;
is equivalent to
expr_1 = (expr_1) + (expr_2);  // note parens.

// good use case = expr_1 is complicated.

## 2.11 Conditional Expressions

In C the following is called a "conditional expression:"

expr1 ? expr2 : expr3

Only one of expr2, expr3 is evaluated.

If expr2 : expr3 are of different types, you can determine what the type of the whole expression is by pretending it's a normal binary operation like expr2 + expr3, and then apply usual type conversion rules .

precedence=
just above assignment 

## 2.12 Precedence and Order of Evaluation

Note that sizeof is considered an operator. 

The comma, which denotes lists, e.g. a list of constant array elements, is an operator too, it has the lowest precedence of all.

Note that the same symbols are used for unary +,- and addition+, subtraction-.

Note that the table is missing the address operator, unary &. It's clear it goes in second row from the top, with the other unary operators.

Recall associativity means how precedence level ties are decided in the absence of explicit parens. When in doubt, paren it out.

Note BE CAREFUL:

a & b == c & d
means, since == has higher precedence than &,
(a & (b == c)) & d)

Operator precedence tells use in what order operators will be applied with respect to other operators appearing in the same expression. 

Another aspect of C having to do with the order of what is done is, for a given operator like +, which argument, considered as a whole, is evaluated first?

C doesn’t specify, this decision is left to the compiler implementor. e.g.

x = f() + g(); // May execute f then g or vice versa. This can be problem if f and g share external variables.

EXCEPT these 4 operators, these DO have their operands evaluated in a specific order:
&& // short circuit.
||
?: // What is the order?
, // comma

Another case of un-specified order is function argument evaluation e.g.

printf("%d %d\n", ++n, power(2, n)); /* WRONG */ // "different results with different compilers," // notice how two arguments use “n”. C might increment n then call power() or vice versa. Simply because these expressions appear inside a function's arguments and this is a case where order is not enforced. The correct version is:

++n;
printf("%d %d\n", n, power(2, n));

Another case of ambiguous order:


"a[i] = i++;
The question is whether the subscript is the old value of i or the new. Compilers can interpret this in different ways” // Note that the left and right sides are distinct expressions, and assignment is a binary operator here, so this is analogous to "f() + g()” above.

The key is 
"``side effects'' - some variable is changed as a by-product of the evaluation of an expression.”
"When side effects (assignment to variables) take place within an expression is left to the discretion of the compiler”

Moral = AVOID order ambiguity.

SUMMARY of ambiguous order:
function call addition.
function arguments.
assignments.


# Chapter 3 - Control Flow
control flow = order of computations

## 3.1 Statements and Blocks

;=statement terminator
{}=grouping =block= compound statement. // no ; 
if you declare a variable inside a block, that limits its scope.


## 3.2 If-Else

ambiguity. associate else with closest if. or be explicit with braces.
when in doubt, brace it out.

## 3.3 Else-If

multi way decision with optional default


## 3.4 Switch

multi way decision but with constant expressions
cases must be different
default executes only if no case matches.
you may write cases+default in any order. e.g. put the default first inside the switch.
break! exits the switch entirely. Without it execution falls through. be careful.

## 3.5 Loops - While and For

for loop can be transformed to equivalent while loop.

comma “,” as an operator. two expressions separated by a comma are evaluated in a specific order, viz. left to right. Its value and type = the value and type of the right expression.

In the context of function arguments the comma “,” is not considered an operator. As mentioned above, function argument evaluation order is compiler implementation dependent.

## 3.6 Loops - Do-While

// next: "We have chosen to generate the string backwards, then reverse it."


## 3.7 Break and Continue

continue // in while and do, control jumps to the test immediately, in for, control jumps to the increment.

## 3.8 Goto and labels

avoid.

# Chapter 4 - Functions and Program Structure

## 4.1 Basics of Functions

Failure to return a value returns garbage.

## 4.2 Functions Returning Non-integers

There are allot of typos in K&R!
Always be explicit with types. especially function args and return values.

## 4.3 External Variables

>"``external'' is used in contrast to ``internal'', which describes the arguments and variables defined inside functions."

>Functions themselves are always external, because C does not allow functions to be defined inside other functions. 

The name of an external always references the same storage, even if the name is referenced from a function that was compiled separately.

But, there is a mechanism for making things "visible only within a single source file." Probably the "static" keyword. 

As long as an external is explicitly declared it can be access from ANY function. Recall the "extern hack" in EDK2 that lets you access variables inside the standard library code.

push(pop() - pop()); /* WRONG */ // Another example of order of **evaluation being ambiguous in C.**

## 4.4 Scope Rules 

Explicit use of extern is required if an external variable is used before it is defined or it is defined in another source file.

external variable declaration vs definition. Definition allocates storage for the variable. A definition also serves as a declaration for the text appearing after a definition.

int sp; // definition
extern int sp; // declaration.

array sizes must be specified for a definition. optional otherwise.

## 4.5 Header Files 

## 4.6 Static Variables 

static keyword limits an external's scope to the source file in which it is defined. And within that file the scope is limited to the text appearing after the static definition.

Can be applied to functions.

Can be applied to internal variables. This provides a local variable with persistent storage across function calls.

## 4.7 Register Variables 

keyword that tells the compiler that this variable will be used allot, if possible it should be placed in a machine register to improve performance. But the compiler is free to ignore this. 

Only allowed for automatic variables. Including function arguments.

## 4.8 Block Structure 

Variable declarations inside any block delineated by curly braces limit to scope of that variable to the containing block. You can even declare variables of the same name as ones in the outer containing block. Their existence ends where the block ends. Such declarations also hide external variables and functions, doing this is not good since it can become confusing to have identically named variables even though the scope rules are well defined.

## 4.9 Initialization 

External and static variables are initialized to 0. Not so or automatic and register variables.

External and static variables can only be initialized with a constant expression. This is not a restriction for automatic and register variables, in this case it can be any expression, even a function call.

Array initialization. Without a size specification, the size is determined by the compiler from the initialization list in curly braces. With a size, if the initialization list has fewer elements than the size the remaining entries are set to 0. More initializers that the specified size is an error.

For char arrays a special initialization format is allowed, viz. initialization with a string constant like "bro".


## 4.10 Recursion 

Another good example of recursion is quicksort, a sorting algorithm developed by **C.A.R. Hoare in 1962.**

## 4.11 The C Preprocessor 

Conceptually the first step in compilation.

### 4.11.1 File Inclusion 

### 4.11.2 Macro Substitution 

In a line like

`#define name repl_text`

`name` is called a token.

Example with arguments:

`#define max(A, B) ((A) > (B) ? (A) : (B))`

Always use explicit parens to avoid errors.

It's all bare bones text replacement.

If you examine the expansion of max, you will notice some pitfalls. The expressions are **evaluated twice**; this is bad if they involve **side effects** like increment operators or input and output. For instance 
`max(i++, j++) /* WRONG */`

Some care also has to be taken with **parentheses** to make sure the order of evaluation is preserved; consider what happens when the macro 
`#define square(x) x * x /* WRONG */ is invoked as square(z+1).`

Use case, done in the standard libs. "macros to avoid the **run-time overhead** of a function call per character processed."

You can convert a macro argument into a quoted string by preceding the argument name with a \# character. e.g.

`#define dprint(expr) printf(#expr " = %g\n", expr)`
When this is invoked, as in 
`dprint(x/y)` 
the macro is expanded into 
`printf("x/y" " = &g\n", x/y)` 

The preprocessor operator `##` provides a way to concatenate actual arguments 
`#define paste(front, back) front ## back`
so `paste(name, 1)` creates the token `name1`.

### 4.11.3 Conditional Inclusion 

Conditional preprocessor statements.
`#if` etc.

# Chapter 5 - Pointers and Arrays 

## 5.1 Pointers and Addresses 

`int *ip;`
is intended as a mnemonic; it says that the expression *ip is an int. 

The unary operators `*` and `&` bind more tightly than arithmetic operators, 

`++*ip` 
and 
`(*ip)++` 
The parentheses are necessary in this last example; without them, the expression would increment ip instead of what it points to, because unary operators like * and ++ associate **right to left**.

## 5.2 Pointers and Function Arguments 

Intro. to functions with pointer arguments.

## 5.3 Pointers and Arrays 

There is **one difference** between an array name and a pointer that must be kept in mind. A pointer is a variable, so pa=a and pa++ are legal. But an **array name** is 
**not* a variable; 
constructions like 
a=pa and a++ 
are **illegal**. 

As **formal** parameters in a **function** definition, 
`char s[]; `
and 
`char *s; `
are **equivalent**; 

it is also possible to index backwards in an array; p[-1], p[-2], and so on are **syntactically legal**

## 5.4 Address Arithmetic 

To avoid int overflow when calculating a difference between pointers use `ptrdiff_t` to hold the signed difference of two pointer values. 

use `size_t` for the return value of strlen, to match the standard library version. size_t is the unsigned integer type returned by the sizeof operator. 

It is **not legal** to 

add two pointers, 

or to multiply 

or divide 

or shift 

or mask them, 

or to add float 

or double to them, 

or even, except for void *, to assign
 
a pointer of one type to a pointer of another type **without a cast.**

## 5.5 Character Pointers and Functions 

## 5.6 Pointer Arrays; Pointers to Pointers 
 
 `p = alloc(len) == NULL` // Pg. 91. Is the precedence of = higher than ==? ANS: No. So this isa KnR bug.

## 5.7 Multi-dimensional Arrays 


the number of rows is irrelevant, 


`f(int daytab[2][13]) { ... } `

It could also be 

`f(int daytab[][13]) { ... } `

since the number of rows is irrelevant, or it could be 

`f(int (*daytab)[13]) { ... } `


The parentheses are **necessary** since brackets [] have higher precedence than *. 

---

// = a block of my writing, not quotes from KnR.

Is this precedence reflected in the table given in ch.2? ANS: Yes. [] appears at the top * appears just below it.

So clearly without the parens:

`int *daytab[13]`

"an array pointers, those pointers point to integers" 

Remind me, as a function argument the size, 13, gets ignored right? ANS: Yes. A pointer to the first element of the array is passed. Pg. 84.

`*daytab` is an integer, the first in the array, `*(daytab + 1)` points to the next integer in the array.

And with parens:

`int (*daytab)[13]`

`*daytab` is a pointer to an array of 13 integers. In this case `*(daytab + 1)` would advance the pointer by 13 integers, to the subsequent size 13 integer array. 

Fine, but I can just ignore this since daytab[][13] is clearer and gets the job done.

//  = end of a block of my writing.

---

More generally, only the **first** dimension (subscript) of an array is **free**; **all** the others have to be **specified**. 

---

## 5.8 Initialization of Pointer Arrays 

how that array of names is initialized. 

// An array of strings = an array of pointers to chars.

```
char *name[] = { "Illegal month", 
"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" 
};
``` 

## 5.9 Pointers vs. Multi-dimensional Arrays 

`int a[10][20];` // Multi-d array.

vs. 

`int *b[10];` // array of pointers.

`a` causes storage for 200 ints to be allocated. Each row is of the same size, viz. 20 ints.

`b` storage only for 10 pointers. But each entry can point to an array of ints of differing lengths.

`char *name[] = { "Illegal month", "Jan", "Feb", "Mar" };` // Note each name is of a different length.

vs. 

`char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar" };` // Here, 15 chars are allocated per row.

"For b, however, the definition only allocates 10 pointers and does not initialize them;" //Do automatic int arrays get initialized to 0 but pointer arrays are not init to 0? 
ANS: No, neither is initialized, just like automatic scalars. See knr_pg94.c.

## 5.10 Command-line Arguments 

## 5.11 Pointers to Functions 

`int (*comp)(void *, void *)` // which says that comp is a pointer to a function that has two void * arguments and returns an int. 


`if ((*comp)(v[i], v[left]) < 0)` // comp is a pointer to a function, \*comp is the function, and 

`(*comp)(v[i], v[left])` // is the call to it. 

`int *comp(void *, void *) /* WRONG */` // says that comp is a function returning a pointer to an int

## 5.12 Complicated Declarations 

"for the harder ones, because declarations cannot be read **left to right**, and because **parentheses** are over-used." // as a consequence of precedence and associativity rules.

"* is a prefix operator and it has lower precedence than ()" // same with * and [].

"`char (*(*x())[])()` x: function returning pointer to array[] of pointer to function returning char" // x is a function. That function returns a pointer. That pointer points to an array of pointers. The entries of that array are pointers to functions. Those functions return a char.

"`char (*(*x[3])())[5]` x: array[3] of pointer to function returning pointer to array[5] of char" // x is array of size 3. The entries in that array are pointers to functions. Those functions return pointers to an array of size 5. That array is an array of chars.

# Chapter 6 - Structures 

## 6.1 Basics of Structures 

## 6.2 Structures and Functions 

## 6.3 Arrays of Structures 

## 6.4 Pointers to Structures 

"**Don't assume**, however, that the size of a structure is the sum of the sizes of its members. Because of **alignment** requirements for different objects, there may be unnamed ``holes'' in a structure. Thus, for instance, if a char is one byte and an int four bytes, the structure" 
```
struct {
char c;
int i; 
};
``` 
"might well require eight bytes, not five." 
## 6.5 Self-referential Structures 

Remark on storage allocation of different data types with possibly different alignment restrictions on particular machines. 

alloc() doesn't ensure any sort of alignment but malloc() always meets alignment restrictions.

## 6.6 Table Lookup 

## 6.7 Typedef 

In effect, typedef is like #define, except that since it is interpreted by the **compiler**, it can cope with textual substitutions that are beyond the capabilities of the preprocessor. 

Notice that the type being declared in a typedef appears in the position of a **variable name**, 

`typedef int (*PFI)(char *, char *);`
 creates the type PFI, for ``pointer to **function** (of two char * arguments) returning int,'' 

Uses.

More Readable.

parameterize a program against **portability** problems. e.g. use typedef names for various integer quantities 

provide better documentation 

## 6.8 Unions 

the purpose of a union - a single variable that can legitimately hold any of one of several types. 

Notice union syntax is very similar to the syntax for structures.

```
union u_tag { 
  int ival; 
  float fval; 
  char *sval;
} u;
```

u is a variable name. We can assign to you any of the above types. Use case, constants in a compiler symbol table, a constant can be an int, float, etc.

The same operations are permitted on unions as on structures 

A union may **only** be **initialized** with a value of the type of its **first** member; 

## 6.9 Bit-fields 

pack several objects into a single machine word 

e.g. interfaces to hardware devices 

set of one-bit flags in a single char or int 

defining and accessing fields within a word directly rather than by bitwise logical operators. 

Fields behave like small integers, and may participate in arithmetic expressions just like other integers. 

unnamed fields (a colon and width only) are used for padding. 

The special width 0 may be used to force alignment 

Almost everything about fields is implementation-dependent. 

Fields may be declared only as ints; 

& operator cannot be applied on them. 

# Chapter 7 - Input and Output 

## 7.1 Standard Input and Output 

Programs that confine their system interactions to facilities provided by the standard library can be moved from one system to another without change. 

prog \<infile // simulates standard input via a file. "\<infile is hidden from argc, argv

otherprog | prog // simulates standard input via a pipe from the standard output of otherprogram

prog >outfile // simulates standard output via a file

prog | otherprog // simulates standard output via a pipe to the standard input of otherprog.

## 7.2 Formatted Output - printf 

Things that can go between % and the conversion character.

## 7.3 Variable-length Argument Lists 

void minprintf(char *fmt, ...);
va_list ap;
va_start(ap, fmt);

ival = va_arg(ap, int);
dval = va_arg(ap, double);
sval = va_arg(ap, char *);

va_end(ap);

## 7.4 Formatted Input - Scanf 

`int scanf(char *format, ...)` input analogue of printf. Takes input from stdin. You give it a string format for input, and pointers to some variables in which to store parsed input.

`int sscanf(char *string, char *format, arg1, arg2, ...)` same as above but parses string instead of stdin.

## 7.5 File Access 

```
// for opening files
FILE *fp FILE *fopen(char *name, char *mode)
fp = fopen(name, mode)

// single char i/o to specified file.
int getc(FILE *fp)
int putc(int c, FILE *fp)

// same as above but file set to stdin/out.
#define getchar() getc(stdin) 
#define putchar(c) putc((c), stdout) 

// formatted input/output with specified file.
int fscanf(FILE *fp, char *format, ...) 
int fprintf(FILE *fp, char *format, ...) 

// closing a file
int fclose(FILE *fp)

// You can close stdin and stdout if they are not needed. They can also be reassigned by the library function freopen 

```
## 7.6 Error Handling - Stderr and Exit 

`stderr` - for when you don't want your error messages to appear in the output, e.g. your output is piped to another program as input. Your error message will still appear on the screen even if its output is piped/redirected.

KnR tend to exclude curly braces - they assume the indentation is sufficient for the reader.

Note the use of `fprintf` over `printf`, so you can pass in the file arg.

`exit(n)` - terminates the program and returns n to the parent process. Also automatically closes any open files. Same of a `return n` from main() except that you can call `exit(n)` outside of main().

`int ferror(FILE *fp)` returns non-zero to tell you if something went wrong with a file including stdout, e.g. stdout hit an error if the main mass storage device is full.

`int feof(FILE *fp)` returns non-zero if fp is at EOF.

## 7.7 Line Input and Output 

`char *fgets(char *line, int maxline, FILE *fp)` reads lines, including the new line char.

`int fputs(char *line, FILE *fp)` writes strings, not necessarily ending in a new line.

`gets()` same as fgets() but with stdin
`puts()` same as fputs() but with stdout

## 7.8 Miscellaneous Functions 

brief synopsis of the most useful functions in the standard library.

\<stdlib.h>->system("shellcommandstr") // provides access to the OS shell.

# Chapter 8 - The UNIX System Interface 

## 8.1 File Descriptors 

Files are represented as **small non-negative integers**, called the file descriptor in place of its name.

By default on Unix the file descriptor numbers are as follows:

0 = standard input

1 = " output

2 = " error

`prog <infile >outfile` 
In this case, the shell changes the default assignments for the file descriptors 0 and 1 to the named files. 

## 8.2 Low Level I/O - Read and Write 

`int n_read = read(int fd, char *buf, int n);` `int n_written = write(int fd, char *buf, int n);`

## 8.3 Open, Creat, Close, Unlink 
## 8.4 Random Access - Lseek 
`prog >> myfile` // in Unix appends to myfile

## 8.5 Example - An implementation of Fopen and Getc 
## 8.6 Example - Listing Directories 
## 8.7 Example - A Storage Allocator 

# Appendix B - Standard Library 

identifiers that begin with an underscore are reserved for use by the library, 

## B.1 Input and Output: <stdio.h> 

A stream is a source or destination of data 

### B.1.1 File Operations 
remove()
rename()
tmpfile()
tmpnam()
setvbuf() setbuf()

### B.1.2 Formatted Output 

format = ordinary chars + conversion specifications(->each successive arg to _printf. 

conversion specifications = "%" + flags + field width + "." + precision + length modifier + conversion char

### B.1.3 Formatted Input 

scanf will read across line boundaries to find its input 

### B.1.4 Character Input and Output Functions 
### B.1.5 Direct Input and Output Functions 
### B.1.6 File Positioning Functions 
### B.1.7 Error Functions 

## B.2 Character Class Tests: <ctype.h> 
## B.3 String Functions: <string.h> 
## B.4 Mathematical Functions: <math.h> 
`fmod()` modulus for floats.

## B.5 Utility Functions: <stdlib.h>

abort() vs. exit() = ungraceful vs. graceful termination.

atexit(funcptr) 

system(str) // access to system shell.

getenv() // access to env. variables.

bsearch() // guessing this is a binary search but KnR doesn't say that explicitly.

qsort() // general sorting.

div_t div(int num, int denom) // integer division with a remainder

## B.6 Diagnostics: <assert.h> 
## B.7 Variable Argument Lists: <stdarg.h> 
## B.8 Non-local Jumps: <setjmp.h> 

to avoid the normal function call and return sequence, typically to permit an immediate return from a deeply nested function call.

## B.9 Signals: <signal.h> 

facilities for handling exceptional conditions that arise during execution, such as an interrupt signal

signal()
raise()

## B.10 Date and Time Functions: <time.h> 
## B.11 Implementation-defined Limits: <limits.h> and <float.h> 
END of appendix B.

# Appendix C - Summary of Changes 

Delta of First edition of this book to the current ANSI standard edition of the book.

# next 	"The Standard places explicit minima" 


