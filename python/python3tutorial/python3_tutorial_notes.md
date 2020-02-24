
# https://docs.python.org/3/tutorial/index.html

## https://docs.python.org/3/tutorial/interpreter.html

had to migrate mac ports due to upgrading mac os x. :shit:

## https://docs.python.org/3/tutorial/interpreter.html#invoking-the-interpreter

### https://docs.python.org/3/tutorial/interpreter.html#argument-passing

python3.8 // starts the interpreter in interactive mode.

python3.8 mystript.py // run the given file as a script.

python3.8 -c 'print("poo")' // executes given command // beware of c/p from rich text into command line.

python3.8 -c 'import sys; print("poo %s" % sys.argv[1])’ myarg // same as above but with additional argument // note that argv[0]== -c and argv[1] == myarg

python3.8 -m python3tutorial // if python3tutorial.py is in the current dir. this way of calling python is equivalent to typing the module name as the first command given to the interpreter. // i.e.  python3.8 python3tutorial.py

adding -i tell python to run the named script and then enter interactive mode vs just running and quitting..

python3.8 -i python3tutorial.py

// asking python for help e.g.

help(sys) // open the sys module docs.

// interpreter environ.
//// file encoding can be set via comment on first line of file
/// same for environment set up “#!” == “shebang”.

# https://docs.python.org/3/tutorial/introduction.html

### https://docs.python.org/3/tutorial/introduction.html#numbers

python will assume an type=int if you provide a constant without a decimal point
ditto for operations with type=int only argument
anything with a decimal point is taken as type=float
operations with ints that have a resulting fractional part will be promoted to float e.g. 5/6
int division can be done like in C by using the // operator.
type() is a built in function for  
also like in C the % operation can be used to determine a remainder but unlike in C this operator works with floats too so 5.5 % 5 == .5 .

besides the above python has numeric types call Decimal and Fraction and complex numbers in which j represents the usual i.

// next: https://docs.python.org/3/tutorial/introduction.html#strings

///// just gonna read through together a broader refresh of python without nitty gritty details of things like types.

// weird quirk about strings, if you add an escaped double quote to a string that already contains an escaped single quote then the single quote goes from appearing in the string without a preceding back slash to with a preceding back slash. // explanation = "While this might sometimes look different from the input (the enclosing quotes could change), the two strings are equivalent."

"Python strings cannot be changed — they are immutable. Therefore, assigning to an indexed position in the string results in an error:” // surprising.

https://docs.python.org/3/tutorial/introduction.html#lists

"Lists might contain items of different types, but usually the items all have the same type." // surprising

slices return new lists but direct assignment does not.

the notation for assigning a list to a variable is the notation in C for creating arrays i.e. square bracketed comma separated values. // notable difference with C=big vs. C

you can assign multiple variables in a single line. // big vs. C . You can’t do this in C, but on a related note,  C does allow you to perform an assignment inside an expression, where the value of the assignment is the value assigned.

"the expressions on the right-hand side are all evaluated first before any of the assignments take place. The right-hand side expressions are evaluated from the left to the right." // multiple assignment, how it works.

“:” is the delimiter for the guard of a while loop. // big vs. C

for guards, any non-zero value is considered true. // same as C

python calls lists what in C we call arrays, but lists in python have many more features. // big vs. C

any sequence type, of which one such type is a list, is considered true if its length is non-zero. empty lists are considered false. // big difference vs. C

comparison operator notations are same as in C. // same as C.

python uses indentation where C uses curly braces. // big difference vs. C

pythons print function is very different from printf in C. // big difference vs. C
e.g.
print(a) // here ‘a' is a variable of type int.
print('The value of i is', i) // here the value of i is printed with the use of a format specifier like %d.
print(a, end=',’) // here end is called a "keyword argument" and assigning to it inside an argument to print tells it to finish printing with a “,” at the end instead of the default new line.

# https://docs.python.org/3/tutorial/controlflow.html#more-control-flow-tools

## https://docs.python.org/3/tutorial/controlflow.html#if-statements

python uses “elif" instead of "else if” . // big difference vs. C 

python has no switch or case statement, instead you use a series of “if elif …” // big difference vs. C. 

python’s for statement works different from C, it is used for iterating over sequence types in order. // big difference vs. C  

e.g.  
for w in words:

for correctness concerns, DO NOT modify a sequence while you are iterating over it. You can create a copy to iterate over and modify the original instead. This way the thing that is being looped over does not change as the loop proceeds. Copys can be created using the copy() method or by creating a new “collection” using “{}” e.g.

 // big difference vs. C.

Note in the above that the curly braces = collections = name value pairs = similar to a dictionary but not exactly I suspect. 

## https://docs.python.org/3/tutorial/controlflow.html#the-range-function

for loop using 
range() 
len() 
enumerate() 

" 
A strange thing happens if you just print a range: 
>>> 
>>> print(range(10)) 
range(0, 10) 
“ // surprising python behavior. range returns an iterable object not a list 
" 
how to get a list from a range. Here is the solution: 
>>> 
>>> list(range(4)) 
[0, 1, 2, 3] 
“ 

### https://docs.python.org/3/tutorial/controlflow.html#break-and-continue-statements-and-else-clauses-on-loops 

break works like in C. 
else is used with for and while loops.  similar to else of a try statement for handling exceptions. 
continue works like in C. 

https://docs.python.org/3/tutorial/controlflow.html#defining-functions

def keyword 
doc string with triple quotes 

local function symbol table 
symbol table of enclosing function 
global symbol table 
last, table of built in names. 

assignment is not allowed, but you can reference values in upper scopes. 

unless you use a scope modifier, global , non-local. 

each function call creates a new symbol table. 

call by value means call by reference to objects. 

newly defined functions have their name added to the symbol table with a type=“user defined function”. You can assign the function name to a valuable to create C like function pointers. 

function vs procedure == returns a value vs doesn’t return a value. In python, no return value by default returns "None". 

return returns a given value. no return value or falling off the function return None.

like in Java. objects have methods. methods are functions associated with an object type. classes let you define your own objects and methods.

### https://docs.python.org/3/tutorial/controlflow.html#more-on-defining-functions 

3 ways to allow for variable argument lists. 

https://docs.python.org/3/tutorial/controlflow.html#default-argument-values

1 - provide default values for some arguments. 
"The default values are evaluated at the point of function definition in the defining scope” 

"Important warning: The default value is evaluated only once.” 
def f(a, L=[]): // Here that warning means that L is not reset to an empty list on each call but rather stores a reference to a list that was created when this function definition was created. This is the case with mutable objects. 

### https://docs.python.org/3/tutorial/controlflow.html#keyword-arguments 

// I here note that up until this point all variable types are determined by implication from type of the first assignment to it. 

2 - you have an alternative keyword=argument function call format. 

3 - you can end a functions arguments with two special values “*name”  and “**name”. This lets you provide a variable number of “tuple" arguments (index+value) and a variable number of dictionary-like arguments. The dictionary like arguments are guaranteed to be in the order in which they appeared in the function definition. 

### https://docs.python.org/3/tutorial/controlflow.html#keyword-arguments 

### https://docs.python.org/3/tutorial/controlflow.html#special-parameters 

// notation for clarifying function argument lists. 

### https://docs.python.org/3/tutorial/controlflow.html#positional-or-keyword-arguments 

### https://docs.python.org/3/tutorial/controlflow.html#positional-only-parameters 

### https://docs.python.org/3/tutorial/controlflow.html#keyword-only-arguments 

### https://docs.python.org/3/tutorial/controlflow.html#function-examples 
// Be careful with argument positional name collision with name as a key. 

python’s 3 different argument passing notations. 

### https://docs.python.org/3/tutorial/controlflow.html#arbitrary-argument-lists 

*arg notation in a function argument definition 

### https://docs.python.org/3/tutorial/controlflow.html#unpacking-argument-lists 

passing lists and dictionaries to a function by unpacking. 

### https://docs.python.org/3/tutorial/controlflow.html#lambda-expressions 

strange way of defining short functions. 


### https://docs.python.org/3/tutorial/controlflow.html#documentation-strings 

doc string formating for functions. 



### https://docs.python.org/3/tutorial/controlflow.html#function-annotations 

Additional method of function doc. specifically type info. 
stored in an attribute of the function. 



### https://docs.python.org/3/tutorial/controlflow.html#intermezzo-coding-style 

summary of PEP8 = https://www.python.org/dev/peps/pep-0008/ 

## https://docs.python.org/3/tutorial/datastructures.html#data-structures 

### https://docs.python.org/3/tutorial/datastructures.html#more-on-lists 

### https://docs.python.org/3/tutorial/datastructures.html#using-lists-as-stacks 

### https://docs.python.org/3/tutorial/datastructures.html#using-lists-as-queues 

for efficient queues use  
from collections import deque 

### https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions 



loop control variables persist , see above. 

a notation for creating lists called list comprehensions. 

### https://docs.python.org/3/tutorial/datastructures.html#nested-list-comprehensions 

concise notation for creating lists / matrix == list of lists. 

### https://docs.python.org/3/tutorial/datastructures.html#the-del-statement 

use del to remove an element from a list, clear a list, delete a variable. 

### https://docs.python.org/3/tutorial/datastructures.html#tuples-and-sequences 

an immutable sequence type. notation uses parens+command. vs list which are mutable and use square brackets. 

### https://docs.python.org/3/tutorial/datastructures.html#sets 

unordered collection with no duplicate elements. 
Curly braces or the set() function can be used to create sets. Note: to create an empty set you have to use set(), not {}; the latter creates an empty dictionary. 

### https://docs.python.org/3/tutorial/datastructures.html#dictionaries 

keys, which can be any immutable type; strings and numbers 

https://docs.python.org/3/tutorial/datastructures.html#looping-techniques

// zip() is short for zipper, as in zipper two lists/sequences together. 

again, don’t modify data as you loop over it. always use new storage. 

### https://docs.python.org/3/tutorial/datastructures.html#more-on-conditions 

in 
not in 
// test if a value is in a sequence. 
is 
is not 
// tests if two objects are the same. "only matters for mutable objects like lists.” Why? Well, we know a string is an immutable object, i.e. it is not modifiable after creation. But a list can be modified. See my test below. For mutable objects like a list, “is” tests wether the arguments points to the same object. For immutable like strings, “is” does a value comparison. Hence for immutables the == operator and “is” are equivalent. 



comparison operators  "in/is/</>/==”  
<  
priority of numerical operators e.g. +,/. 

//  1 < 2 == 3 means (1 < 2) && (2 == 3) 

boolean operators "and or not”  
<  
priority of comparison operators  "in/is/</>/==” . 

in order of highest to lowest priority. 
not 
and 
or 

boolean operators evaluated from left to right. short circuited like in C. 

// BE CAREFUL 
recall empty string where a boolean condition is expected means false. otherwise non-empty strings are true. 

// VERY UNUSUAL string operands with boolean short circuit operators can result in a string value. 

"When used as a general value and not as a Boolean, the return value of a short-circuit operator is the last evaluated argument.” 



To do an assignment in an expression, you must use special operator ”:=“. Unlike in C. 

### https://docs.python.org/3/tutorial/datastructures.html#comparing-sequences-and-other-types 

sequence types must be of the same type to do comparison. 

"The comparison uses lexicographical ordering:” // just like string comparison. first mismatch determines result. 

"item” means element in a sequence. 

if an item is a nested sequence type, and the types match, recursive comparison is done. 

if one string/sequence is a substring/sequence of another , the substring is considered  less than the other. 

object of different types can be compared only if comparison methods are defined. 

### https://docs.python.org/3/tutorial/modules.html 
script 
module - defines functions 
import works on local dir. 
__name__ 

### https://docs.python.org/3/tutorial/modules.html#more-on-modules 

modules have private symbol tables. but you can still access the private symbol table. you probably should. 

from fibo import fib1 // imports name into local symbol table. in this case fibo is not an imported name. “fib1” replaced by * mean import ALL names. EXCEPT names beginning with _ . not recommend. 

import fibo as f //  import module name but rename it. 

by default modules are only imported once. even if you try to import it again. so if you change the import module you must restart the interpreter and import again. workaround: import importlib ; importlib.reload(the_already_imported_module) 

### https://docs.python.org/3/tutorial/modules.html#executing-modules-as-scripts 


Previously we called the functions in fibo.py by importing them and making explicit calls to its functions. i.e. 
python 
>> import fibo 
>> fibo.fib(100) 

alternatively we can do 
python fibo.py <args> 
In this case python sets __name__ = “__main__” instead of the default module name. 
This is the mechanism for turning a python script into something more like C code with a  main() function. This is done by adding to the script: 

if __name__ == "__main__": 
    import sys 
    fib(int(sys.argv[1])) 

Note how easily fibo.py can be given command line args with: 
$ python fibo.py 50 
0 1 1 2 3 5 8 13 21 34 

Runs just like C code with an arg. 

Note that now importing fibo does not cause the main function to execute since the __name__ was not set as in the above case. 
>> import fibo 
// Nothing happens, main isn’t run because __name__ was not set. 

### https://docs.python.org/3/tutorial/modules.html#the-module-search-path 

What happens when you run “import spam” 

built-in modules else sys.path where sys.path is set to 
dir or input file 
cd if no file given 
env. var. PYTHONPATH 
install dependent default. 

### https://docs.python.org/3/tutorial/modules.html#compiled-python-files 

### https://docs.python.org/3/tutorial/modules.html#standard-modules 

### https://docs.python.org/3/tutorial/modules.html#packages 

How to organize related code into modules hierarchically. 

### https://docs.python.org/3/tutorial/modules.html#importing-from-a-package 


### https://docs.python.org/3/tutorial/modules.html#intra-package-references 

How to import between two modules that are part of the same package. 

### https://docs.python.org/3/tutorial/modules.html#packages-in-multiple-directories 

# https://docs.python.org/3/tutorial/inputoutput.html#input-and-output 

## https://docs.python.org/3/tutorial/inputoutput.html#fancier-output-formatting 

### https://docs.python.org/3/tutorial/inputoutput.html#formatted-string-literals 

### https://docs.python.org/3/tutorial/inputoutput.html#the-string-format-method 

### https://docs.python.org/3/tutorial/inputoutput.html#manual-string-formatting 

### https://docs.python.org/3/tutorial/inputoutput.html#old-string-formatting 

## https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files 

It is good practice to use the with keyword when dealing with file objects. 

### https://docs.python.org/3/tutorial/inputoutput.html#methods-of-file-objects 

### https://docs.python.org/3/tutorial/inputoutput.html#saving-structured-data-with-json 


FYI: "pickle is a protocol which allows the serialization of arbitrarily complex Python objects.” 

# https://docs.python.org/3/tutorial/errors.html#errors-and-exceptions 

Two kinds of errors 

1. syntax errors 
2. exceptions. 

## https://docs.python.org/3/tutorial/errors.html#syntax-errors 

report= 
offending line copy 
+  
file name + line number  
+ 
little arrow, error is at token before the little arrow. 

error report name = “SyntaxError” 

## https://docs.python.org/3/tutorial/errors.html#exceptions 

exception = error during execution. 
If you handle such errors, your program can continue. 

exceptions have types e.g. “ZeroDivisionError”/“NameError”. These are “built-in”. These take the form of built-in identifiers not reserved key words. 

## https://docs.python.org/3/tutorial/errors.html#handling-exceptions 

syntax for handling 
try 
… 
break     
except ValueError: 
… 

except can be followed by more than one exception. 
// unexplained use of “pass” reserved keyword. I think it means “empty statement”. 
// next: "A class in an except clause is compatible with an exception" 

OSError as err: // unexplained use of “as” 

final except clause serves as catch all. // use carefully. raise keyword, replays exception. 

except else clause // do this if no exception was raised. 

exceptions can have values. 

exceptions bubble up through function calls. 

## https://docs.python.org/3/tutorial/errors.html#raising-exceptions 

usage of raise keyword. 

## https://docs.python.org/3/tutorial/errors.html#user-defined-exceptions 

## https://docs.python.org/3/tutorial/errors.html#defining-clean-up-actions 


finally clause // do this regardless of anything. 

## https://docs.python.org/3/tutorial/errors.html#predefined-clean-up-actions 

use case of the  
“with” statement. // e.g. used to open files. 
See doc for object to see if “with" is supported. 

# https://docs.python.org/3/tutorial/classes.html#classes 

> In C++ terminology, normally class members (including the data members) are public (except see below Private Variables), and all member functions are virtual. 

virtual=

> A virtual function a member function which is declared within a base class and is re-defined(Overriden) by a derived class. 

## https://docs.python.org/3/tutorial/classes.html#a-word-about-names-and-objects

## https://docs.python.org/3/tutorial/classes.html#python-scopes-and-namespaces

The important thing to know about namespaces is that there is absolutely no relation between names in different namespaces;

module1.max != module2.max

attribute for any name following a dot 

module’s attributes and the global names defined in the module: they share the same namespace!

e.g. module1.__name__ and module1.max

Attributes may be read-only or writable. 

del modname.the_answer will remove the attribute the_answer from the object named by modname.

Namespaces are created at different moments and have different lifetimes. 

A scope is a textual region of a Python program where a namespace is directly accessible. 

At any time during execution, there are ***at least three** nested scopes whose namespaces are directly accessible:

local scope
function scope
module scope
builtin scope

global declarations
nonlocal declarations

if not declared nonlocal, those variables are read-only (an attempt to write to such a variable will simply create a new local variable in the innermost scope, leaving the identically named outer variable unchanged).

Class definitions place yet another namespace in the local scope.

It is important to realize that scopes are determined textually:

assignments to names always go into the innermost scope. Assignments do not copy data — they just bind names to objects.

### https://docs.python.org/3/tutorial/classes.html#scopes-and-namespaces-example

// Here we see a big difference from C. Functions may be defined inside functions!

print "test spam"

print "nonlocal spam"

print "nonlocal spam"

print "global spam"

// Note indentation level of "test spam"

## https://docs.python.org/3/tutorial/classes.html#a-first-look-at-classes

Class definitions must be executed like code, unlike in Java where a class is just a definition. This means class definitions can appear as part of a if statement or inside a function.

Methods have special argument list form.

Class definitions create a new namespace.

The end of a class definition creates a "class object" to be created. = wrapper on the new namespace. ClassName becomes a new name in the namespace containing the class definition.

### https://docs.python.org/3/tutorial/classes.html#class-objects

Operations on class objects:

1. attribute refs

MyClass.i
MyClass.f
MyClass.__doc__

2. instantiation.

x = MyClass()

builtin \__doc__ attribute.

self keyword in method argument lists.

Special method name for initialization upon instantiation. \__init__(self): self.data = "poop"

### https://docs.python.org/3/tutorial/classes.html#instance-objects

The only operation allowed is attribute references.

Two kinds of attribute references.

1. data attributes
2. method attributes

access to data attribute does not require declaration during class definition. They can be created upon assignment. You can delete them using del.

method = function belonging to an object. In python class instances are distinct from other object types. Class object vs. instance object vs. list object. Both are considered to have methods.

all class attributes that are function objects = methods of an instance object of that class.

Python distinguishes between a method object and a function object.

x = MyClass()
x.foo() // is a method object.
MyClass.foo() // is a function object.

### https://docs.python.org/3/tutorial/classes.html#method-objects

the special thing about methods is that the instance object is passed as the first argument of the function. 

the **instance object** and the **function object** just found **together** in an abstract object: this is the **method object**.

### https://docs.python.org/3/tutorial/classes.html#class-and-instance-variables

Be careful about when creating classes with respect to shared and unshared data between instances of a class. Particularly for mutable objects like list objects.

## https://docs.python.org/3/tutorial/classes.html#random-remarks

nothing in Python makes it possible to enforce data hiding — it is all based upon convention. // i.e. you are not prevented from accessing data members directly, can always do that, even though a methods exists to do the same, like private data members in Java. Python also lets you add data members to an instance object on the fly. Another distinction with Java.

Often, the first argument of a method is called self. This is nothing more than a **convention:**

It is not necessary that the function definition is textually enclosed in the class definition: assigning a function object to a local variable in the class is also ok.

Methods may reference **global names** in the same way as ordinary functions. The **global scope** associated with a method is the module containing its definition. 

Special data attribute of class instances which store its type(a.k.a class)

object.__class__

## https://docs.python.org/3/tutorial/classes.html#inheritance

For attribute references, the derived class is checked first, if not there, a recursive search begins at the base class.

Note on method overrides, a call to a base class method can end up calling an overiden method in the derived class:

"a method of a base class that calls another method defined in the same base class may end up calling a method of a derived class that overrides it."

If you want to "extend" rather than override a base class method you can call the base class method using:

`BaseClassName.methodname(self, arguments)`

`isinstance(obj, int)` will be True only if `obj.__class__` is int or some **class derived** from int.

`issubclass(bool, int)` is True since bool is a subclass of int.

### https://docs.python.org/3/tutorial/classes.html#multiple-inheritance

> you can think of the search for attributes inherited from a parent class as depth-first, left-to-right, not searching twice in the same class where there is an overlap in the hierarchy.

> if an attribute is not found in DerivedClassName, it is searched for in Base1, then (recursively) in the base classes of Base1, and if it was not found there, it was searched for in Base2, and so on.

> it is slightly more complex than that; the method resolution order changes dynamically 

### https://docs.python.org/3/tutorial/classes.html#private-variables

a name prefixed with an underscore (e.g. _spam) should be treated as a non-public part of the API 

for class-private members
 
to avoid name clashes of names with names defined by subclasses

name mangling. 

Any identifier of the form __spam (**at least two** leading underscores, **at most one** trailing underscore) is **textually** replaced with _classname__spam, where classname is the current class name with **leading underscore(s) stripped**. This mangling is done without regard to the syntactic position of the identifier, as long as it occurs **within the definition of a class**.

helpful for letting **subclasses override methods** without breaking intraclass method calls.

```python
class Mapping:
    def __init__(self, iterable):
        self.items_list = []
        self.__update(iterable) # Note the use of __ here and below causes name mangling to occur. Also note that __update is used here before its introduction below. The existence of that name is evaluated at runtime.

    def update(self, iterable):
        for item in iterable:
            self.items_list.append(item)

    __update = update   # private copy of original update() method

class MappingSubclass(Mapping):

    def update(self, keys, values): # This method override has the effect of re-assigning to the name update() a new function object.
        # provides new signature for update()
        # but does not break __init__() # Because __init__() calls __update() not update().
        for item in zip(keys, values):
            self.items_list.append(item)
            
    __update = 'poo' # Does not collide with the base class's __update because name mangling prevents that.
```
Note that the mangling rules are designed mostly to avoid accidents; **it still is possible to access** or modify a variable that is considered **private**.

Notice that code passed to exec() or eval() does not consider the classname of the invoking class to be the current class; // This remark is unclear, I think it refers to the classname prefix that is used when name mangling occurs.

## https://docs.python.org/3/tutorial/classes.html#odds-and-ends

Recommended way of creating something similar to a C “struct”. Empty class.

If m is an "instance method object".
m.__self__ # is the instance object associated with method m.

m.__func__ # is the function object associated with method m.

## https://docs.python.org/3/tutorial/classes.html#iterators

Create an iterator by defining
`__iter__()`
and
`__next__()`

## https://docs.python.org/3/tutorial/classes.html#generators

Alternative shorthand for creating iterators. Uses yield keyword.

With yield, a function definition can be turned into an iterator. Most of the iterator is created automatically, hence the name "generator".

## https://docs.python.org/3/tutorial/classes.html#generator-expressions

Abbreviation for generators that are used only once. Same syntax as list compressions but with parenthesis in place of square brackets.

# https://docs.python.org/3/tutorial/stdlib.html#brief-tour-of-the-standard-library

## https://docs.python.org/3/tutorial/stdlib.html#operating-system-interface

## https://docs.python.org/3/tutorial/stdlib.html#operating-system-interface

## https://docs.python.org/3/tutorial/stdlib.html#file-wildcards

## https://docs.python.org/3/tutorial/stdlib.html#command-line-arguments

## https://docs.python.org/3/tutorial/stdlib.html#error-output-redirection-and-program-termination

## https://docs.python.org/3/tutorial/stdlib.html#string-pattern-matching

## https://docs.python.org/3/tutorial/stdlib.html#mathematics

## https://docs.python.org/3/tutorial/stdlib.html#internet-access

## https://docs.python.org/3/tutorial/stdlib.html#dates-and-times

## https://docs.python.org/3/tutorial/stdlib.html#data-compression

## https://docs.python.org/3/tutorial/stdlib.html#performance-measurement

## https://docs.python.org/3/tutorial/stdlib.html#quality-control

Interesting. Comments turned into tests. Replacement for pytest?

## https://docs.python.org/3/tutorial/stdlib.html#batteries-included

Other libs.
Remote procedure calls
Email. SMTP. POP.
JSON
Comma Separated Values.
XML.
SQL.

# https://docs.python.org/3/tutorial/stdlib2.html#brief-tour-of-the-standard-library-part-ii

## https://docs.python.org/3/tutorial/stdlib2.html#output-formatting

Ways to print things nicely.

## https://docs.python.org/3/tutorial/stdlib2.html#templating

A way to have text place holders filled into a hard coded text.

## https://docs.python.org/3/tutorial/stdlib2.html#working-with-binary-data-record-layouts

