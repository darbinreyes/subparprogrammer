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





